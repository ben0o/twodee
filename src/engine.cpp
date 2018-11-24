#include "engine.hpp"

Engine::Engine()
{
    // Default Constructor
    bRunning = true;
}
Engine::~Engine()
{
    // Destructor
}
void Engine::Run()
{	
	SDL_Init( SDL_INIT_EVERYTHING );

	p_window = SDL_CreateWindow( "TwoDee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	p_renderer = SDL_CreateRenderer( p_window, -1, SDL_RENDERER_ACCELERATED );

	SDL_Event event;

	p_cntrMenu = new ControllerMenu();
	p_cntrGame = new ControllerGame(p_renderer);

	//Set the menu as the current controller object
	p_cntrCurrent = p_cntrMenu;
	p_cntrCurrent->SetForegroundStatus();
	bShowMenu = true;
	std::cout << "Assign Menu to Controller Pointer" << std::endl;
	
	// Initialise image loading.
	IMG_Init(IMG_INIT_PNG);

	// ---- Delta Time Code 1 ----
	// If this code is used, the player sprite moves at a steady rate across the screen.
	// Set current clock time
	float startTime = SDL_GetTicks();
	float currentTime = 0;

	double deltaTime = 0;

	while (bRunning)
	{
		currentTime = startTime;
		startTime = SDL_GetTicks();

		deltaTime = ((startTime - currentTime) * 1000 / (double)SDL_GetTicks());
		Input(event, 0); // Process input events
		Update(deltaTime);
		Draw();
	}
	// --------------------------


	// ---- Delta Time Code 2 ----
	// If this code is used, the player sprite instantly moves to the opposite edge of the screen.
	//double timeDelta = 1.0 / 30.0;
	//double timeAccumulator = 0;
	//double timeStart = SDL_GetTicks();
	//double timeSimulatedThisIteration;
	//while (bRunning)
	//{
	//	timeStart = SDL_GetTicks();
	//	timeSimulatedThisIteration = 0;
	//
	//	Input(event, 0);
	//	while (timeAccumulator >= timeDelta)
	//	{
	//		Update(timeDelta);
	//		timeAccumulator -= timeDelta;
	//		timeSimulatedThisIteration += timeDelta;
	//	}
	//	Draw();
	//	timeAccumulator += SDL_GetTicks() - timeStart;
	//}
	// -------------------------

	SDL_DestroyRenderer( p_renderer );
	SDL_DestroyWindow( p_window );
	p_cntrGame->DeleteAssets();
	SDL_Quit();
	
}
void Engine::Input(SDL_Event &event, double dt)
{
    while( SDL_PollEvent( &event ) )
    {
		if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0)
		{
			//std::cout << "SetInput() function called." << std::endl;
			p_cntrCurrent->SetInput(event);
		}

		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			std::cout << "Escape key has been pressed!" << std::endl;
			bRunning = false;
		}
    }
}
void Engine::Update(double deltaTime)
{
	p_cntrCurrent->Update(deltaTime);
	
	if (!p_cntrCurrent->GetForegroundStatus())
	{
		//Current controller has slipped into the background, bring other controller to the front 
		ToggleMenu();
	}
	
}
void Engine::Draw()
{
	p_cntrCurrent->Draw(p_renderer);
}
void Engine::ToggleMenu()
{
	if (!bShowMenu)
	{ //Show menu
		std::cout << "Assign Menu to Controller Pointer" << std::endl;
		p_cntrCurrent = p_cntrMenu;
		p_cntrCurrent->SetForegroundStatus();
		bShowMenu = true;
	}
	else
	{ //Show game
		std::cout << "Assign Game to Controller Pointer" << std::endl;
		p_cntrCurrent = p_cntrGame;
		p_cntrCurrent->SetForegroundStatus();
		bShowMenu = false;
	}
}

