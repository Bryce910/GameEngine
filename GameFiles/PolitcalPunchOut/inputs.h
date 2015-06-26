#pragma once
#include "linker.h"
class inputs
{
public:
	inputs();
	friend class menu;
	friend class labels;
	sf::RectangleShape TEXTBOX; //textbox
	sf::RectangleShape SLIDERBAR; //sliding bar
	sf::CircleShape SLIDER; //sliding circle
	sf::Vector2f SLIDERVALUES; //values for slider
	sf::Text LABEL; //text label
	sf::Vector2f LOCATION; //location of label
	sf::Font FONT; //font for text
	sf::Texture BUTTONTEXTURE; // texture for button
	sf::Sprite BUTTON; // button sprite
	std::vector<sf::Sprite> BUTTONLIST; //list of button
	void FsetButton();
	~inputs();
};

