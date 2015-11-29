#ifndef __AntificialAntelligence__Animation__
#define __AntificialAntelligence__Animation__

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
	 
	public:
        Animation();
    
		Animation(std::vector<sf::IntRect> newFrames, float newFrameRate);

		void update(sf::Sprite& spriteToAnimate, float deltaTime);

	private:

		std::vector<sf::IntRect> frames;

		float timeSinceLastAnimFrame;

		int frameCounter;

		float frameRate;

};

#endif
