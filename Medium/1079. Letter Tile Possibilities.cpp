// Problem Link: https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17

class Solution {
    public:
        vector<int>cnt=vector<int>(26,0);
        int backtrack(string s){
            int ans=0;
            for(int i=0;i<26;i++){
                if(cnt[i]){
                    cnt[i]--;
                    ans++;
                    ans+=backtrack(s);
                    cnt[i]++;
                }
            }
            return ans;
        }
        int numTilePossibilities(string tiles) {
            for(auto &c:tiles)cnt[c-'A']++;
            return backtrack(tiles);
        }
    };
    
    // Time Complexity : O(N)*O(2^N) => O(2^N);
    // Space Complexity: O(N);