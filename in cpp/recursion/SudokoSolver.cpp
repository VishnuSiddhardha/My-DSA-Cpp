#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> box;
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for(char check='1';check<='9';check++)
                    {
                        if((isValid(i,j,check))){
                            board[i][j] = check;

                            rows[i].insert(check);
                            cols[j].insert(check);
                            int boxNo = (i / 3) * 3 + (j / 3);
                            box[boxNo].insert(check);
                            if(solve(board))
                                return true;
                            else {
                                board[i][j]='.'; 
                                rows[i].erase(check);
                                cols[j].erase(check);
                                int boxNo = (i / 3) * 3 + (j / 3);
                                box[boxNo].erase(check);
                            }
                                
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(int i, int j,char num)
    {
        int boxNo = (i / 3) * 3 + (j / 3);
        if(rows[i].find(num)==rows[i].end() && cols[j].find(num)==cols[j].end() && box[boxNo].find(num)==box[boxNo].end())
            return true;
        return false;
    }
    void fillTable(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                char num = board[i][j];
                rows[i].insert(num);
                cols[j].insert(num);
                int boxNo = (i / 3) * 3 + (j / 3);
                box[boxNo].insert(num);
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        
        fillTable(board);
        solve(board);
    }
};

class Solution {
    bool rows[9][10];   // rows[i][num] = true if num already in row i
    bool cols[9][10];   // cols[j][num] = true if num already in col j
    bool boxes[9][10];  // boxes[boxNo][num] = true if num already in box

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        int num = ch - '0';
                        int boxNo = (i / 3) * 3 + (j / 3);
                        if (!rows[i][num] && !cols[j][num] && !boxes[boxNo][num]) {
                            // place number
                            board[i][j] = ch;
                            rows[i][num] = cols[j][num] = boxes[boxNo][num] = true;

                            if (solve(board)) return true;

                            // backtrack
                            board[i][j] = '.';
                            rows[i][num] = cols[j][num] = boxes[boxNo][num] = false;
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

    void fillTable(vector<vector<char>>& board) {
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(boxes, false, sizeof(boxes));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int boxNo = (i / 3) * 3 + (j / 3);
                    rows[i][num] = cols[j][num] = boxes[boxNo][num] = true;
                }
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        fillTable(board);
        solve(board);
    }
};


int main()
{

    return 0;
}