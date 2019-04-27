#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid
{
public:
	Grid() = delete;
	Grid(const float col, const float row, const float startPosX, const float startPosY);
	~Grid();

	void Fill(sf::RenderWindow *window);
	void Erase(sf::RenderWindow *window);
	void Update();
	void Draw(sf::RenderWindow *window) const;

private:
	void setText();

	static constexpr float mCellWidth = 20.f;
	static constexpr float mCellHeight = 20.f;
	int mCol;
	int mRow;
	unsigned int mLiveCount = 0;
	std::vector<sf::RectangleShape> vCells;
	std::vector<int> vNeighborCount;
	sf::Font mFont;
	sf::Text mText;
};

