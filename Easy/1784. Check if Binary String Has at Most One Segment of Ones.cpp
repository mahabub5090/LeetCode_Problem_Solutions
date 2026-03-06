// Problem Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06

class Solution {
public:
    bool checkOnesSegment(string s) {
        char prev='0';
        int cnt=0;
        for(auto &c:s){
            if(c!=prev){
                prev=c;
                if(c=='1')cnt++;
            }
        }
        return cnt<=1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);