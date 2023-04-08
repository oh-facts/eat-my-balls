#include <App.hpp>

App::App(/* args */)
{
}
void App::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Eat my balls in C++");
	window.setView(sf::View(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y)));

	sf::Clock clock;
	Player player;
	Spawner<Item<sf::CircleShape>> ballSpawner(0.25f);
	Spawner<Item<sf::RectangleShape>> squareSpawner(0.75);
	Score score;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		sf::Time elapsed = clock.restart();

		// logic
		player.update(elapsed);
		ballSpawner.update(elapsed);
		squareSpawner.update(elapsed);

		if(ballSpawner.checkCollision(player))
		{
			score.increaseScore();
		}
		if(squareSpawner.checkCollision(player))
		{
			score.resetScore();
		}

		// render
		window.clear();

		player.render(window);
		ballSpawner.render(window);
		squareSpawner.render(window);	
		score.render(window);

		window.display();
	}
}

App::~App()
{
}
