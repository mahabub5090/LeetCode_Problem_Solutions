// Problem Link: https://leetcode.com/problems/furthest-point-from-origin/description/?envType=daily-question&envId=2026-04-24

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int curr=0,wish=0;
        for(auto &c:moves){
            if(c=='_')wish++;
            else curr+=c=='L'?-1:1;
        }
        return abs(curr)+wish;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);