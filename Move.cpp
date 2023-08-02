#include "Board.cpp"

struct Move
{
    Piece piece;
    string playerColor;
    int rFromLoc;
    int cFromLoc;
    int rToLoc;
    int cToLoc;
    Move(Piece piece, string playerColor, int rFromLoc, int cFromLoc, int rToLoc, int cToLoc)
    {
        cout << "Turn constructor" << endl;
        this->piece = piece;
        this->playerColor = playerColor;
        this->rFromLoc = rFromLoc;
        this->cFromLoc = cFromLoc;
        this->rToLoc = rToLoc;
        this->cToLoc = cToLoc;
    }

    bool isLegal(Board& board)
    {
        if (piece.color != playerColor)
            return false;
        if (rFromLoc == rToLoc && cFromLoc == cToLoc)
            return false;
        string name = piece.type.substr(5, piece.type.length());
        if (name == "Knight")
        {
            cout << name << endl;
            cout << "Piece is knight" << endl;
            if((abs(rToLoc - rFromLoc) == 1 && abs(cToLoc - cFromLoc) == 2) || (abs(rToLoc - rFromLoc) == 2 && abs(cToLoc - cFromLoc) == 1))
            {
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        else if (name == "Pawn")
        {
            if ((cToLoc == cFromLoc))
            {
                if (playerColor == "white" && rFromLoc == 1 && rToLoc - rFromLoc > 2 || (playerColor == "white" && rFromLoc > rToLoc))
                    return false;
                if (playerColor == "black" && rFromLoc == 6 && rFromLoc - rToLoc > 2 || (playerColor == "black" && rFromLoc < rToLoc))
                    return false;
                if (playerColor == "white" && rFromLoc != 1 && rFromLoc - rToLoc > 1)
                    return false;
                if (playerColor == "black" && rFromLoc != 6 && rToLoc - rFromLoc > 1)
                    return false;
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        //capture();
                        return false;
                    }
                    return false;
                }
                return true;
            }
            if (abs(cToLoc - cFromLoc) == 1)
            {
                if (playerColor == "white" && rToLoc - rFromLoc == 1 && board.board[rToLoc][cToLoc]->hasPiece && board.pieces[rToLoc][cToLoc]->color != playerColor)
                {
                    capture();
                    return true;
                }
                if (playerColor == "black" && rFromLoc - rToLoc == 1 && board.board[rToLoc][cToLoc]->hasPiece && board.pieces[rToLoc][cToLoc]->color != playerColor)
                {
                    capture();
                        return true;
                }
            }
            return false;
        }
        else if (name == "King")
        {
            if ((abs(rToLoc - rFromLoc) <= 1 && abs(cToLoc - cFromLoc) <= 1))
            {
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        else if (name == "Rook")
        {
            if (rToLoc == rFromLoc)
            {
                for (int i = min(cToLoc, cFromLoc) + 1; i < max(cToLoc, cFromLoc); ++i)
                {
                    if (board.board[rToLoc][i]->hasPiece)
                        return false;
                }
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            else if (cToLoc == cFromLoc)
            {
                for (int i = min(rToLoc, rFromLoc) + 1; i < max(rToLoc, rFromLoc); ++i)
                {
                    if (board.board[i][cToLoc]->hasPiece)
                        return false;
                }
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        else if (name == "Bishop")
        {
            if (abs(cToLoc - cFromLoc) != abs(rToLoc - rFromLoc))
                return false;
            int a = (cToLoc - cFromLoc) / abs(cToLoc - cFromLoc);
            int b = (rToLoc - rFromLoc) / abs(rToLoc - rFromLoc);
            for (int i = 1; i < abs(cToLoc - cFromLoc); ++i)
            {
                if (board.board[rFromLoc + b * i][cFromLoc + a * i]->hasPiece)
                    return false;
            }
            if (board.board[rToLoc][cToLoc]->hasPiece)
            {
                if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                {
                    capture();
                    return true;
                }
                return false;
            }
            return true;
        }
        else if (name == "Queen")
        {
            if (rToLoc == rFromLoc)
            {
                for (int i = min(cToLoc, cFromLoc) + 1; i < max(cToLoc, cFromLoc); ++i)
                {
                    if (board.board[rToLoc][i]->hasPiece)
                        return false;
                }
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            else if (cToLoc == cFromLoc)
            {

                //straight
                for (int i = min(rToLoc, rFromLoc) + 1; i < max(rToLoc, rFromLoc); ++i)
                {
                    if (board.board[i][cToLoc]->hasPiece)
                        return false;
                }
                if (board.board[rToLoc][cToLoc]->hasPiece)
                {
                    if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                    {
                        capture();
                        return true;
                    }
                    return false;
                }
                return true;
            }

            //diagonal
            if (abs(cToLoc - cFromLoc) != abs(rToLoc - rFromLoc))
                return false;
            int a = (cToLoc - cFromLoc) / abs(cToLoc - cFromLoc);
            int b = (rToLoc - rFromLoc) / abs(rToLoc - rFromLoc);
            for (int i = 1; i < abs(cToLoc - cFromLoc); ++i)
            {
                if (board.board[rFromLoc + b * i][cFromLoc + a * i]->hasPiece)
                    return false;
            }
            if (board.board[rToLoc][cToLoc]->hasPiece)
            {
                if (board.pieces[rToLoc][cToLoc]->color != playerColor)
                {
                    capture();
                    return true;
                }
                return false;
            }
            return true;

        }
        return true;
    }
    void capture()
    {
        cout << "Piece taken" << endl;
    }
};