// Time Complexity: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16 

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int>mp,last;
        long long ans=0;
        long long cnt=0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            cnt+=mp[nums[j]]++;
            while(cnt>=k){
                ans+=n-j;
                cnt-=--mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);