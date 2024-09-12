// Problem Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        map<char,int>mp; for(auto &c:allowed)mp[c]++;
        for(auto &c:words){
            bool fg=1;
            for(auto &cc:c){
                if(mp[cc]==0){fg=0;break;}
            }
            if(fg)cnt++;
        }
        return cnt;
    }
};

// Time Complexity : O(N+M) => O(N);
// Space Complexity: O(N+M) => O(N);