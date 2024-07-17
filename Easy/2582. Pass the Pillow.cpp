// Problem Link: https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06

class Solution {
public:
    int passThePillow(int n, int time) {
        // if(time<n)return time+1;
        int way=(time/(n-1))%2;
        return !way? (time%(n-1))+1: n-(time%(n-1));
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);