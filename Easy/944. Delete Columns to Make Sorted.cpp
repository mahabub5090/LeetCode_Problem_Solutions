// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/?envType=daily-question&envId=2025-12-20

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            char prev=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]<prev){
                    ans++;
                    break;
                }
                prev=strs[j][i];
            }
            cout<<endl;
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);


