#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool win(vector<string>& board, char c) {
        // check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        }
        // check cols
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
        }
        // check diagonals
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }

public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }

        // Rule 1: X goes first, so count check
        if (oCount > xCount || xCount > oCount + 1) return false;

        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');

        // Rule 2: both can't win
        if (xWin && oWin) return false;

        // Rule 3: if X wins, must have played one extra move
        if (xWin && xCount != oCount + 1) return false;

        // Rule 4: if O wins, must have equal moves
        if (oWin && xCount != oCount) return false;

        return true;
    }
};


int main()
{

    return 0;
}