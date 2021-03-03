#include <SFML/Graphics.hpp>
using namespace sf;
const Vector2i win = Vector2i(256, 256);
const int CellSize = 2;
int main()
{
	RenderWindow window(VideoMode(win.x, win.y), "paint");
	Vector2i mpos;
	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			mpos = Mouse::getPosition(window);
			RectangleShape shape(Vector2f(CellSize, CellSize));
			shape.setFillColor(Color::White);
			mpos.x = mpos.x / CellSize * CellSize;
			mpos.y = mpos.y / CellSize * CellSize;
			shape.setPosition(Vector2f(mpos.x, mpos.y));
			window.draw(shape);
		}
		window.display();
	}
	return 0;
}