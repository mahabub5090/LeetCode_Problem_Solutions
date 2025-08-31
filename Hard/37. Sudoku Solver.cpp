// Problem Link: https://leetcode.com/problems/sudoku-solver/description/?envType=daily-question&envId=2025-08-31

class Solution {
public:
    int isValid(auto &board,int r,int c,char num) {
        for(int i=0;i<9;i++) {
            if(board[r][i]==num)return 0;
            if(board[i][c]==num)return 0;
            int boxRow=3*(r/3)+i/3;
            int boxCol=3*(c/3)+i%3;
            if(board[boxRow][boxCol]==num)return 0;
        }
        return 1;
    }

    int backtrack(auto &board){
        for(int r=0;r<9;r++) {
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') {
                    for(char num='1';num<='9';num++) {
                        if(isValid(board,r,c,num)){
                            board[r][c]=num;

                            if(backtrack(board))return 1;

                            board[r][c]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

// Time Complexity : O(9^(9*9)) => O(1); 
// Space Complexity: O(9*9) => O(1);