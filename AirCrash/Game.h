/// <summary>
/// author Ryan McDonald 2025
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

float vectorLength(sf::Vector2f t_v);

const int HEIGHT = 800;
const int WIDTH = 1000;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void processMouseDown(sf::Event t_event);
	void processMouseUp(sf::Event t_event);

	void setupFontAndText();
	void setupSprite();
	void setupSky();
	void setupPlanes();
	void setupExplosion();
	void animateExplosion();

	void movePlanes();
	void keepOnScreen(sf::Vector2f &t_location);
	void drawPlane(sf::Sprite &t_plane);
	bool checkCollisionsBB(sf::Sprite &t_plane1, sf::Sprite &t_plane2);
	bool checkCollisionsDistance(sf::Vector2f t_pos1, float t_rad1, 
						sf::Vector2f t_pos2, float t_rad2);


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	sf::Texture m_skyTexture; //texture for sky
	sf::Sprite m_skySprite; //sprite for sky

	sf::Texture m_planesTexture;

	//BIGPLANE
	sf::Sprite m_bigPlaneSprite;
	sf::Vector2f m_bigPlaneVelocity{1.0f,-1.0f};
	sf::Vector2f m_bigPlaneLocation{ 200.0f,200.0f };
	float m_bigHeading{ 45.0f };
	float m_bigRadius;

	//SMALLPLANE
	sf::Sprite m_smallPlaneSprite;
	sf::Vector2f m_smallPlaneVelocity{ -1.6f,1.6f };
	sf::Vector2f m_smallPlaneLocation{ 600.0f,0.0f };
	float m_smallHeading{ 225.0f };
	float m_smallRadius;

	sf::Vector2f m_mouseDown;

	sf::Texture m_explosionTexture;
	sf::Sprite m_explosionSprite;
	bool m_exploding{ false };
	int m_expFrame{ 0 };
	float m_expIncrement{ 0.6f };
	float m_expFrameTimer{ 0.0f };


	bool m_exitGame; // control exiting game
	bool m_debugging;

};

#endif // !GAME_HPP

