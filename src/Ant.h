#include <SFML/Graphics.hpp>


class Ant {
	 
	public:

		Ant(sf::Vector2f newPosition, sf::Texture &texture);

		void draw(sf::RenderWindow &window);

		void setPosition(sf::Vector2f newPosition);

		sf::Vector2f getPosition();

	private:

		sf::Sprite sprite;
};
