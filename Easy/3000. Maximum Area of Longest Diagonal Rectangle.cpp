// Problem Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/?envType=daily-question&envId=2025-08-26

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSquare=0,maxArea=0;
        for(auto &c:dimensions){
            int l=c[0],w=c[1];
            int diagonalSquare=l*l+w*w,area=l*w;
            if(diagonalSquare>maxDiagonalSquare){
                maxDiagonalSquare=diagonalSquare;
                maxArea=area;
            }
            else if(diagonalSquare==maxDiagonalSquare)maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

