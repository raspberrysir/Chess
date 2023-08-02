#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
struct Piece
{
    sf::Sprite sprite;
    string color = "";
    string type = "";

    sf::Texture blackKnight;
    sf::Texture blackPawn;
    sf::Texture blackBishop;
    sf::Texture blackRook;
    sf::Texture blackKing;
    sf::Texture blackQueen;

    sf::Texture whiteKnight;
    sf::Texture whitePawn;
    sf::Texture whiteBishop;
    sf::Texture whiteRook;
    sf::Texture whiteKing;
    sf::Texture whiteQueen;
    Piece()
    {

    }
    Piece(string type)
    {
        blackKnight.loadFromFile("images\\black_knight.png");
        blackBishop.loadFromFile("images\\black_bishop.png");
        blackPawn.loadFromFile("images\\black_pawn.png");
        blackKing.loadFromFile("images\\black_king.png");
        blackQueen.loadFromFile("images\\black_queen.png");
        blackRook.loadFromFile("images\\black_rook.png");

        whiteKnight.loadFromFile("images\\white_knight.png");
        whiteBishop.loadFromFile("images\\white_bishop.png");
        whitePawn.loadFromFile("images\\white_pawn.png");
        whiteKing.loadFromFile("images\\white_king.png");
        whiteQueen.loadFromFile("images\\white_queen.png");
        whiteRook.loadFromFile("images\\white_rook.png");

        this->type = type;
        color = type.substr(0, 5);
        if (type == "blackKnight")
            sprite = sf::Sprite(blackKnight);
        else if (type == "blackBishop")
            sprite = sf::Sprite(blackBishop);
        else if (type == "blackPawn")
            sprite = sf::Sprite(blackPawn);
        else if (type == "blackKing")
            sprite = sf::Sprite(blackKing);
        else if (type == "blackQueen")
            sprite = sf::Sprite(blackQueen);
        else if (type == "blackRook")
            sprite = sf::Sprite(blackRook);
        else if (type == "whiteKnight")
            sprite = sf::Sprite(whiteKnight);
        else if (type == "whiteBishop")
            sprite = sf::Sprite(whiteBishop);
        else if (type == "whitePawn")
            sprite = sf::Sprite(whitePawn);
        else if (type == "whiteKing")
            sprite = sf::Sprite(whiteKing);
        else if (type == "whiteQueen")
            sprite = sf::Sprite(whiteQueen);
        else if (type == "whiteRook")
            sprite = sf::Sprite(whiteRook);
    }

    /*Piece& operator=(Piece rhs)
    {
        cout << "Copy constructed" << endl;
        this->color = rhs.color;
        this->sprite = rhs.sprite;
        this->type = rhs.type;
        return *this;
    }

    Piece(Piece &rhs)
    {
        cout << "Copy assigned" << endl;
        this->color = rhs.color;
        this->sprite = rhs.sprite;
        this->type = rhs.type;
    }*/
};