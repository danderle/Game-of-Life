#include "Grid.h"
#define FONT_FILEPATH "Fonts/Montserrat-Regular.ttf"

Grid::Grid(const float frameWidth, const float frameHeight, const float startPosX, const float startPosY)
{
	mFont.loadFromFile(FONT_FILEPATH);
	mText.setFont(mFont);
	mText.setFillColor(sf::Color::Red);
	mText.setOutlineColor(sf::Color::Yellow);
	mText.setOutlineThickness(2.f);
	mText.setString("Alive: 0");
	mText.setPosition(sf::Vector2f(25.f, 0));

	mCol = static_cast<int>(frameWidth / mCellWidth + 2);
	mRow = static_cast<int>(frameHeight / mCellHeight + 2);

	for (int y = 0; y < mRow; y++)
	{
		for (int x = 0; x < mCol; x++)
		{
			vNeighborCount.emplace_back(0);

			vCells.emplace_back();
			vCells.back().setSize(sf::Vector2f(mCellWidth, mCellHeight));
			vCells.back().setFillColor(sf::Color::Transparent);
			vCells.back().setOrigin(sf::Vector2f(mCellWidth / 2.0f, mCellHeight / 2.0f));

			float xPos = vCells.back().getOrigin().x + startPosX + ((x - 1)*vCells.back().getSize().x);
			float yPos = vCells.back().getOrigin().y + startPosY + ((y - 1)*vCells.back().getSize().y);
			vCells.back().setPosition(sf::Vector2f(xPos, yPos));

			//Walls are dead
			if (y != 0 && y != mRow - 1 && x != 0 && x != mCol - 1)
			{
				vCells.back().setOutlineColor(sf::Color::Blue);
				vCells.back().setOutlineThickness(-1.f);
			}
		}
	}
} 

Grid::~Grid()
{
}

void Grid::Fill(sf::RenderWindow *window)
{
	for (int y = 0; y < mRow; y++)
	{
		for (int x = 0; x < mCol; x++)
		{
			if (vCells.at(mCol * y + x).getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
			{
				if (vCells.at(mCol * y + x).getFillColor() != sf::Color::White)
				{
					vCells.at(mCol * y + x).setFillColor(sf::Color::White);
					mLiveCount++;
				}
			}
		}
	}
	setText();
}

void Grid::Erase(sf::RenderWindow *window)
{
	for (int y = 0; y < mRow; y++)
	{
		for (int x = 0; x < mCol; x++)
		{
			if (vCells.at(mCol * y + x).getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
			{
				if (vCells.at(mCol * y + x).getFillColor() != sf::Color::Transparent)
				{
					vCells.at(mCol * y + x).setFillColor(sf::Color::Transparent);
					mLiveCount--;
				}
			}
		}
	}
	setText();
}

void Grid::Update()
{
	for (int y = 1; y < mRow - 1; y++)
	{
		for (int x = 1; x < mCol - 1; x++)
		{
			int counter = 0;
			counter += vCells[mCol * y + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * y + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y - 1) + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y + 1) + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y - 1) + x].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y + 1) + x].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y - 1) + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;
			counter += vCells[mCol * (y + 1) + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;

			vNeighborCount[mCol * y + x] = counter;
		}
	}

	for (int y = 1; y < mRow - 1; y++)
	{
		for (int x = 1; x < mCol - 1; x++)
		{
			if (vCells[mCol * y + x].getFillColor() == sf::Color::White)
			{
				if (vNeighborCount[mCol * y + x] < 2 || vNeighborCount[mCol * y + x] > 3)
				{
					vCells[mCol * y + x].setFillColor(sf::Color::Transparent);
					mLiveCount--;
				}
			}
			else
			{
				if (vNeighborCount[mCol * y + x] == 3)
				{
					vCells[mCol * y + x].setFillColor(sf::Color::White);
					mLiveCount++;
				}
			}
		}
	}
	sf::sleep(sf::milliseconds(100));
	setText();
}

void Grid::Draw(sf::RenderWindow *window) const
{
	for (auto cell : vCells)
	{
		window->draw(cell);
	}
	window->draw(mText);
}

//#########  Private Methods / Helper functions ##################################

void Grid::setText()
{
	std::string alive = "Alive: " + std::to_string(mLiveCount);
	mText.setString(alive);
}
