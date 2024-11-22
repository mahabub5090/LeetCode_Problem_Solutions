// Problem Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/?envType=daily-question&envId=2024-11-22

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        for(int i=0;i<matrix.size();i++){
            string s="";
            for(int j=0;j<matrix[0].size();j++){
                s+=(matrix[i][j]==0?'0':'1'); 
            }
            if(s[0]=='0')mp[s]++;
            else{
                for(auto &c:s)c=(c=='0'?'1':'0');
                mp[s]++;
            }
        }
        int ans=0;
        for(auto &c:mp)ans=max(ans,c.second);
        return ans;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(N);
