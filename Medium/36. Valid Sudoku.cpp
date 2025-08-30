// Problem Link: https://leetcode.com/problems/valid-sudoku/description/?envType=daily-question&envId=2025-08-30

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,set<char>>row,col,square;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int id=(i/3)*3+j/3;
                char val=board[i][j];

                if(row[i].count(val) || col[j].count(val) || square[id].count(val)) return 0;

                row[i].insert(val);
                col[j].insert(val);
                square[id].insert(val);
            }
        }
        return 1;
    }
};

// Time complexity : O(N^2) => O(9^2) => O(1);
// Space Complexity: O(3*(N^2)) => (3*(9^2)) => O(1);
// board size is (N*N) == 9*9 here;