// Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/?envType=daily-question&envId=2026-07-30

class Solution {
public:
    int minimumPushes(string word) {
        int push=0, curr=1, ans=0;
        for(auto &c:word){
            push++;
            if(push>8) curr++, push%=8;
            ans+=curr;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);