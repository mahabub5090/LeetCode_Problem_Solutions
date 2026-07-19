// Problem Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26,0), vis(26,0);
        for(auto &c:s) cnt[c-'a']++;

        string ans;
        for(auto &c:s){
            if(vis[c-'a']==0){
                while(ans.size() && ans.back()>c){
                    if(cnt[ans.back()-'a']>0){
                        vis[ans.back()-'a']--;
                        ans.pop_back();
                    }
                    else break;
                }

                vis[c-'a']++;
                ans+=c;
            }

            cnt[c-'a']--;
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N+26) => O(N);
// Space Complexity: O(26) + O(26) + O(26) => O(1);