// Problem Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int maxSide=0,n=topRight.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int h=min(topRight[i][1],topRight[j][1])-max(bottomLeft[i][1],bottomLeft[j][1]);
                int w=min(topRight[i][0],topRight[j][0])-max(bottomLeft[i][0],bottomLeft[j][0]);

                maxSide=max(maxSide,min(h,w));
            }
        }
        return 1ll*maxSide*maxSide;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);