#include "State.hpp"
#include "Engine.hpp"

State::State() : GStateReq(false), IStateReq(false), MStateReq(false)
{
}

State::~State()
{
}

void State::Process()
{	
    Engine::engine.App.pollEvent(event);
	
	static bool OldEscKeyDown = false;
    static bool OldF1KeyDown = false;
    static bool OldF2KeyDown = false;
    static bool OldF3KeyDown = false;
	
    bool EscKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    bool F1KeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::F1);
    bool F2KeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::F2);
    bool F3KeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::F3);
    
    if(event.type == sf::Event::Closed)
    {
        Engine::Stop();
    }
    if(EscKeyDown && !OldEscKeyDown)
    {
        Engine::Stop();
    }
    
	OldEscKeyDown = EscKeyDown;
    OldF1KeyDown = F1KeyDown;
    OldF2KeyDown = F2KeyDown;
	OldF3KeyDown = F3KeyDown;
}

void State::Update()
{
}

void State::Render()
{
    Engine::engine.App.clear();
}

void State::ReqStateChange(int state)
{
	switch(state)
	{
		case GAME_STATE:
			GStateReq = true;
		break;
		
		case INTRO_STATE:
			IStateReq = true;
		break;
		
		case MENU_STATE:
			MStateReq = true;
		break;	
	}
}
