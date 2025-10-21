// Problem Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

class Solution {
public:
    pair<int,int> bound(int val,auto &nums){
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l+1)/2;
            
            if(nums[mid]<val)l=mid+1;
            else r=mid-1;
        }

        int l2=0,r2=nums.size()-1;
        while(l2<=r2){
            int mid=l2+(r2-l2+1)/2;
            
            if(nums[mid]<=val)l2=mid+1;
            else r2=mid-1;  
        }
        return {l,l2};
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        int ans=0;
        unordered_map<int,int>mp;

        int lastIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[lastIndex]){
                mp[nums[lastIndex]]=i-lastIndex;
                ans=max(ans,mp[nums[lastIndex]]);
                lastIndex=i;
            }
        }

        mp[nums[lastIndex]]=nums.size()-lastIndex;
        ans=max(ans,mp[lastIndex]);

        for(int i=nums[0];i<=nums.back();i++){
            int l=bound(i-k,nums).first;
            int r=bound(i+k,nums).second;

            int cnt=min(r-l,mp[i]+numOperations);
            ans=max(ans,cnt);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N*2logN) => O(NlogN);
// Space Complexity: O(N);