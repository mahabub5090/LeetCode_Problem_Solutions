// Problem Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07

class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int>ans;
            unordered_map<int,int>mp,mp2;
            for(auto &c:queries){
                if(mp[c[0]]){
                    int color=mp[c[0]];
                    mp2[color]--;
                    if(mp2[color]==0)mp2.erase(color);
                }
                mp[c[0]]=c[1];
                mp2[c[1]]++;
                ans.push_back(mp2.size());
            }
            return ans;
        }
    };
    
    // Time Complexity : O(N);
    // Space Complexity: O(2*N) => O(N);