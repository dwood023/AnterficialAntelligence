#include "Animation.h"
#include "AssetLoader.h"
#include <SFML/Graphics.hpp>
#include <vector>

Animation::Animation(std::vector<sf::IntRect> newFrames, float newFrameRate) {

	frames = newFrames;
	frameRate = newFrameRate;
	frameCounter = 0;

}

void Animation::update(sf::Sprite& spriteToAnimate, float deltaTime) {
	 
	timeSinceLastAnimFrame += deltaTime;

	if (timeSinceLastAnimFrame >= 1.0f / frameRate) {

		if (frameCounter >= frames.size()) 
			 frameCounter = 0;

		spriteToAnimate.setTextureRect(frames[frameCounter++]);	 

		timeSinceLastAnimFrame = 0;	

	}

}

