// Problem Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

class Solution {
public:
    int backtrack(int i,auto &ans,auto &used) {
        int n=ans.size();
        if(i==n)return 1;
        if(ans[i]!=-1)return backtrack(i+1,ans,used);

        for(int j=used.size()-1;j>=1;j--){
            if(used[j])continue;
            if(j>1 && (i+j>=n || ans[i+j]!=-1))continue;

            used[j]++;
            ans[i]=j;  
            if(j>1)ans[i+j]=j;

            if(backtrack(i+1,ans,used))return 1;

            used[j]=0;
            ans[i]=-1;
            if(j>1)ans[i+j]=-1;
        }
        return 0;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans((2*n)-1,-1);
        vector<int>used(n+1,0);
        backtrack(0,ans,used);
        return ans;
    }
};

// Time Complexity : O(2^N) * O(N) => O(2^N);
// Space Complexity: O(N^2);