// Problem Link: https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08

class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int tt=i*i+j*j;
                int root=sqrt(tt);
                if(root*root==tt && root<=n)ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);