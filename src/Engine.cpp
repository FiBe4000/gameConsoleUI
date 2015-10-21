#include "Engine.hpp"
#include <iostream>
#include <vector>

Engine Engine::engine;

Engine::Engine() : Running(false)
{
    App.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "ConsoleUI");//, sf::Style::Fullscreen);
    App.setFramerateLimit(60);
    App.setVerticalSyncEnabled(true);
    //App.ShowMouseCursor(false);
    //App.SetSize(WINDOW_WIDTH*2, WINDOW_HEIGHT*2);
	state = new State();
    changeState = false;
    std::cerr << "Window set up" << std::endl;
}

Engine::~Engine()
{
    delete state;
}

void Engine::Start()
{
    engine.Run();
}

void Engine::Run()
{
    Running=true;
    std::cerr << "Running main loop" << std::endl;
    while(Running)
    {
    	frameClock.restart();
    	
        if(changeState)
        {
        	std::cerr << "Deleting " << state->p() << std::endl;
            delete state;
            state=NewState;
            changeState=false;
        }

        state->Process();
        state->Update();
        state->Render();
    }
}

void Engine::Stop()
{
    engine.Running=false;
}

void Engine::ChangeState(State* newState)
{
    changeState=true;
    NewState=newState;
}

float Engine::GetFrameTime()
{
	return frameClock.getElapsedTime().asSeconds();
}

