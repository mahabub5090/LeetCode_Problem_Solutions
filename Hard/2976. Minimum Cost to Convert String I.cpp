// Problem Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>minCost(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)minCost[i][i]=0;
        int len=original.size();
        for(int i=0;i<len;i++){
            int &val=minCost[original[i]-'a'][changed[i]-'a'];
            val=min(val,cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(minCost[i][k]!=INT_MAX && minCost[k][j]!=INT_MAX){
                        minCost[i][j]=min(minCost[i][j],minCost[i][k]+minCost[k][j]);
                    }
                }
            }
        }
        
        long long ans=0,n=target.size();
        for(int i=0;i<n;i++){
            int &val=minCost[source[i]-'a'][target[i]-'a'];
            if(val==INT_MAX)return -1;
            ans+=val;
        }
        return ans;
    }
};

// Time Complexity : O(M) + O(26^3) + O(N) => O(N);
// Space Complexity: O(26^3) => O(1);
// Here N=source.size(), M=original.size();