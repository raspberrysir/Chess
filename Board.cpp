#include "Tile.cpp"
#include "Piece.cpp"
#include <iostream>
using namespace std;

struct Board
{
    Tile* board[8][8];
    Piece* pieces[8][8];
    sf::Texture blackTile;
    sf::Texture whiteTile;
    Board()
    {
        whiteTile.loadFromFile("images\\white_tile.png");
        blackTile.loadFromFile("images\\black_tile.png");
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if ((i + j) % 2 == 0)
                {
                    sf::Sprite sprite(blackTile);
                    sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    Tile* newTile = new Tile(sprite);
                    board[i][j] = newTile;
                }
                else
                {
                    sf::Sprite sprite(whiteTile);
                    sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    Tile* newTile = new Tile(sprite);
                    board[i][j] = newTile;
                }

                if (i == 1)
                {
                    Piece* newPiece = new Piece("whitePawn");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 6)
                {
                    Piece* newPiece = new Piece("blackPawn");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 0 && (j == 0 || j == 7))
                {
                    Piece* newPiece = new Piece("whiteRook");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 0 && (j == 1 || j == 6))
                {
                    Piece* newPiece = new Piece("whiteKnight");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 0 && (j == 2 || j == 5))
                {
                    Piece* newPiece = new Piece("whiteBishop");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 0 && j == 4)
                {
                    Piece* newPiece = new Piece("whiteQueen");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 0 && j == 3)
                {
                    Piece* newPiece = new Piece("whiteKing");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 7 && (j == 0 || j == 7))
                {
                    Piece* newPiece = new Piece("blackRook");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 7 && (j == 1 || j == 6))
                {
                    Piece* newPiece = new Piece("blackKnight");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 7 && (j == 2 || j == 5))
                {
                    Piece* newPiece = new Piece("blackBishop");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 7 && j == 4)
                {
                    Piece* newPiece = new Piece("blackQueen");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else if (i == 7 && j == 3)
                {
                    Piece* newPiece = new Piece("blackKing");
                    newPiece->sprite.setPosition(sf::Vector2f(j * 80, i * 80));
                    pieces[i][j] = newPiece;
                    board[i][j]->hasPiece = true;
                }
                else
                    pieces[i][j] = nullptr;
            }
        }
    }
    
    ~Board()
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j]->hasPiece)
                    delete pieces[i][j];
                delete board[i][j];
            }
        }
    }

    Board& operator=(Board rhs)
    {
        cout << "Board copy constructed" << endl;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                this->board[i][j] = rhs.board[i][j];
                if(rhs.board[i][j]->hasPiece)
                    this->pieces[i][j] = rhs.pieces[i][j];
            }
        }
        return *this;
    }

    Board(Board& rhs)
    {
        cout << "Board copy assigned" << endl;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                this->board[i][j] = rhs.board[i][j];
                if (rhs.board[i][j]->hasPiece )
                    this->pieces[i][j] = rhs.pieces[i][j];
            }
        }
    }
};