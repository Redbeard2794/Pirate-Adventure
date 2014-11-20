////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
 
 
////////////////////////////////////////////////////////////
///Entrypoint of application
////////////////////////////////////////////////////////////
 
int main()
{
// Create the main window
//sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
//load a font
sf::Font font;
font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");
 
//create a formatted text string
//sf::Text text;
//text.setFont(font);
//text.setString("Hello World");
//text.setStyle(sf::Text::Underlined| sf::Text::Italic | sf::Text::Bold);
//text.setPosition(20,40);
//text.setCharacterSize(40);
 
//create a circle
//sf::CircleShape circle(50);
//circle.setPosition(300,200);

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Pirate Adventure");

	
	
	Player p;
	sf::Clock clock;
	//sf::View view1(sf::Vector2f(p.getPosition().x, p.getPosition().y), sf::Vector2f(300, 200));
	//window.setView(view1);
    // define the level with an array of tile indices

	ParticleSystem particles(15);
	bool releaseParticles = false;
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3, 1, 3, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 16))
        return -1;
// Start game loop
	
	while (window.isOpen())
	{

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			releaseParticles = !releaseParticles;
		}
        // draw the map
		p.Update();
		//view1.setCenter(p.getPosition());
		//view1.move(100, 100);
        window.clear();
        window.draw(map);
					p.draw(window);
		if(releaseParticles == true)
		{
			particles.setEmitter(p.getPosition());
			sf::Time elapsed = clock.restart();
			particles.update(elapsed);
			window.draw(particles);
		}

        window.display();
 
	//draw frame items
	//window.draw(text);
 
	//window.draw(circle);
	// Finally, display rendered frame on screen
	//window.display();
	} //loop back for next frame

 //return 0;
return EXIT_SUCCESS;
} 