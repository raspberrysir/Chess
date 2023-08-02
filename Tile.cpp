#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

struct Tile
{
    sf::Sprite sprite;
    bool hasPiece = false;;
    Tile()
    {

    }
    Tile(sf::Sprite sprite)
    {
        this->sprite = sprite;
    }

    Tile& operator=(Tile rhs)
    {
        cout << "Tile Copy constructed" << endl;
        this->hasPiece = rhs.hasPiece;
        this->sprite = rhs.sprite;
        return *this;
    }

    Tile (Tile& rhs)
    {
        cout << "Tile Copy assigned" << endl;
        this->hasPiece = rhs.hasPiece;
        this->sprite = rhs.sprite;
    }
};