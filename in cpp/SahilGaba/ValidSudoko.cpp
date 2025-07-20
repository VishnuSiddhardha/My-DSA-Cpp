#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        unordered_map<int, unordered_set<int>> box;


        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                // check in rows
                if (rows[i].find(num) != rows[i].end()) return false;
                rows[i].insert(num);
                // check in columns
                if (cols[j].find(num) != cols[j].end()) return false;
                cols[j].insert(num);
                // check in boxes
                int boxNo = (i / 3) * 3 + (j / 3);
                if (box[boxNo].find(num) != box[boxNo].end()) return false;
                box[boxNo].insert(num);
            }
        }
        return true;
    }
};

class Solution {
public:
    bool valid(vector<vector<char>>&board,int row,int col,char k){
        int cnt=0;
        for(int i=0;i<9;i++){
            if(board[row][i] == k)
                cnt++;
            if(board[i][col] == k)
                cnt++;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3] == k)
                cnt++;
        }
        if(cnt>3){
            return false;
        }
        return true;
    }

  bool find(vector<vector<char>>&board,int row,int col){
        if(row == 9)
            return true;
        if(col == 9)
            return find(board,row+1,0);
        if(board[row][col] != '.'){
            if(!valid(board,row,col,board[row][col])){
                return false;
            }
        }
        return find(board,row,col+1);
        
}


    bool isValidSudoku(vector<vector<char>>& board) {
        char k;
        return find(board,0,0);   
    }
};

int main()
{

    return 0;
}