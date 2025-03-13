// Problem Link: https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int>freq(n+1,0);
        int op=0,k=0;
        for(int i=0;i<n;i++){
            for(;op<nums[i]-freq[i];k++){
                if(k>=m)return -1;
                int l=queries[k][0],r=queries[k][1],v=queries[k][2];

                if(r<i)continue;
                freq[max(l,i)]+=v;
                freq[r+1]-=v;
            }
            op+=freq[i];
        }

        return k;
    }
};

// Time Complexity : O(N+M) => O(N);
// Space Complexity: O(N+M) => O(N);