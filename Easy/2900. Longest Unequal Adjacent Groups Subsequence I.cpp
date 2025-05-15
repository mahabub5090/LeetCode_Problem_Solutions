// Problem Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        ans.push_back(words[0]);
        int n=words.size(),last=groups[0];
        for(int i=1;i<n;i++){
            if(groups[i]!=last){
                ans.push_back(words[i]);
                last=groups[i];
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);