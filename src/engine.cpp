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

	p_window = SDL_CreateWindow( "TwoDee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
	p_renderer = SDL_CreateRenderer( p_window, -1, SDL_RENDERER_ACCELERATED );
	SDL_Event event;

	p_settings = new Settings();
	
	//Load settings from file here
	
	p_cntrMenu = new ControllerMenu(p_settings);
	p_cntrGame = new ControllerGame(p_renderer);

	//Set the menu as the current controller object
	p_cntrCurrent = p_cntrMenu;
	p_cntrCurrent->SetForegroundStatus();
	bShowMenu = true;
	std::cout << "Assign Menu to Controller Pointer" << std::endl;
	
	// Initialise image loading.
	IMG_Init(IMG_INIT_PNG);

	double timeDelta = 1.0/30.0;
	double timeAccumulator = 0;
	double timeStart = SDL_GetTicks();
	double timeSimulatedThisIteration;
	while(bRunning)
	{
		timeStart = SDL_GetTicks();
		timeSimulatedThisIteration = 0;
		
        // Input() function processes keyboard input.
        Input(event, timeDelta);
		
		while ( timeAccumulator >= timeDelta )
		{
			Update(timeDelta);
			timeAccumulator -= timeDelta;
			timeSimulatedThisIteration += timeDelta;
		}
		
		Draw();
		SDL_RenderPresent( p_renderer ); 
		timeAccumulator += SDL_GetTicks(); - timeStart;
	}
	SDL_DestroyRenderer( p_renderer );
	SDL_DestroyWindow( p_window );
	p_cntrGame->DeleteAssets();
	SDL_Quit();
	
}
void Engine::Input(SDL_Event &event, double dt)
{
    while( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
            case SDL_QUIT:
                bRunning = false;
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				p_cntrCurrent->SetInput(dt);
            default:
                break;
        }
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			std::cout << "Escape key has been pressed!" << std::endl;
			bRunning = false;
		}
		//p_cntrCurrent->SetInput(event);
    }
}
void Engine::Update(double dt)
{
	p_cntrCurrent->Update(dt);
	
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
		p_cntrCurrent->CompareSettings(p_settings);
		bShowMenu = false;
	}
}

