// Problem Link: https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21

class Solution {
public:
    void dfs(int c,auto &ans,int n){
        if(c>n)return;
        ans.push_back(c);
        c*=10;
        for(int i=0;i<=9;i++)dfs(c+i,ans,n);
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(i,ans,n);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N); 