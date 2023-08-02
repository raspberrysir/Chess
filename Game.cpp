#include "Move.cpp"
using namespace std;

struct Game
{
    Board board;
    sf::RenderWindow window;
    string whoseTurn = "black";
    void render()
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                window.draw(board.board[i][j]->sprite);
            }
        }
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board.board[i][j]->hasPiece)
                {
                    window.draw(board.pieces[i][j]->sprite);
                }
            }
        }
        window.display();
    }

    Game() : window(sf::VideoMode(8 * 80 + 150, 8 * 80 + 150), "Chess")
    {
        render();
    }
    void show()
    {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    int initialX = position.x;
                    int initialY = position.y;
                    while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        position = sf::Mouse::getPosition(window);
                        sf::Vector2f positionF(position.x - 40.0, position.y - 40.0);
                        if (board.board[initialY / 80][initialX / 80]->hasPiece)
                        {
                            board.pieces[initialY / 80][initialX / 80]->sprite.setPosition(positionF);
                            render();
                        }
                    }
                    if (board.board[initialY / 80][initialX / 80]->hasPiece)
                    {
                        Piece* piece = board.pieces[initialY / 80][initialX / 80];
                        Move move(*piece, whoseTurn, initialY / 80, initialX / 80, position.y / 80, position.x / 80);
                        if (move.isLegal(board))
                        {
                            cout << "Is Legal Woo Hoo" << endl;
                            sf::Vector2f positionF(position.x / 80 * 80 + 0.0, position.y / 80 * 80 + 0.0);
                            board.pieces[position.y / 80][position.x / 80] = board.pieces[initialY / 80][initialX / 80];
                            board.pieces[initialY / 80][initialX / 80] = nullptr;
                            board.board[position.y / 80][position.x / 80]->hasPiece = true;
                            delete board.pieces[initialY / 80][initialX / 80];
                            board.board[initialY / 80][initialX / 80]->hasPiece = false;
                            board.pieces[position.y / 80][position.x / 80]->sprite.setPosition(positionF);
                            if (whoseTurn == "white")
                                whoseTurn = "black";
                            else
                                whoseTurn = "white";
                        }
                        else
                        {
                            cout << "Illegal uwu" << endl;
                            sf::Vector2f positionF(initialX / 80 * 80 + 0.0, initialY / 80 * 80 + 0.0);
                            board.pieces[initialY / 80][initialX / 80]->sprite.setPosition(positionF);
                        }
                        render();
                    }
                    
                }
            }           



            
        }
    }

    
};