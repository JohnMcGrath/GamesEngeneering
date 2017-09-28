#include "InputHandler.h"
#include "game.h"

void InputHandler::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		buttonX_->execute();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		buttonY_->execute();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		buttonA_->execute();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		buttonB_->execute();
	}
}