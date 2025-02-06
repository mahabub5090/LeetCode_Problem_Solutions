// Problem Link: https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &c:mp){
            int pair=c.second;
            if(pair>1){
                pair=(pair-1)*pair/2;
                ans+=8*pair;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*N) + O(N) => O(N^2);
// Space Complexity: O(N^2);