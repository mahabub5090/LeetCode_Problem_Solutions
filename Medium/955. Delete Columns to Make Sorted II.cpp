// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/?envType=daily-question&envId=2025-12-21

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        int ans=0;
        vector<int>cuts(n,0);

        for(int i=0;i<m;i++){
            int f=1;
            for(int j=0;j<n-1;j++){
                if(cuts[j]==0 && strs[j][i]>strs[j+1][i]){
                    f=0;
                    break;
                }
            }
            if(f){
                for(int j=0;j<n-1;j++){
                    if(strs[j][i]<strs[j+1][i])cuts[j]++;
                }
            }
            else ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);