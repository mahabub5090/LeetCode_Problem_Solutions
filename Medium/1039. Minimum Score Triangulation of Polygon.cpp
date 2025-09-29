// Problem Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29

class Solution {
public:
    map<int,int>memo;
    int dp(int i,int j,auto &values){
        int n=values.size();
        if(i+2>j)return 0;
        if(i+2==j)return values[i]*values[i+1]*values[j];

        int key=i*n+j;
        if(memo.count(key))return memo[key];
        
        int minScore=INT_MAX;
        for(int k=i+1;k<j;k++){
            minScore=min(minScore,(values[i]*values[k]*values[j])+dp(i,k,values)+dp(k,j,values));
        }
        return memo[key]=minScore;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        return dp(0,n-1,values);
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N^2);