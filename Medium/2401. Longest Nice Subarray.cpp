// PRoblem Link: https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18

class Solution {
public:
    int check(auto &vc){
        for(int i=0;i<vc.size();i++){
            if(vc[i]>1)return 0;
        }
        return 1;
    }
    void add(auto &vc,int n){
        int i=0;
        for(int i=0;i<32;i++)vc[31-i]+=(n>>i)&1;
    }
    void remove(auto &vc,int n){
        int i=0;
        for(int i=0;i<32;i++)vc[31-i]-=(n>>i)&1;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        vector<int>vc(32,0);
        int i=0,j=0,n=nums.size();
        
        while(j<n){
            add(vc,nums[j]);
            while(i<j && !check(vc))remove(vc,nums[i]),i++;
            if(check(vc))ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

// Time Complexity : O(32*N) => O(N);
// Space Complexity: O(32) => O(1);