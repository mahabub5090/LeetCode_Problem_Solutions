// Problem Link: https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=daily-question&envId=2026-06-22

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto &c:text){
            if(c!='b' && c!='a' && c!='l' && c!='o' && c!='n') continue;
            mp[c]++;
        }

        int ans=(mp.size()==5)?INT_MAX:0;
        for(auto &c:mp){
            if(c.first=='l' || c.first=='o') ans=min(ans,c.second/2);
            else ans=min(ans,c.second);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(5) => O(N);
// Space Complexity: O(5) => O(1);