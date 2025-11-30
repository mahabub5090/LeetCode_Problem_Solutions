// Problem Link: https://leetcode.com/problems/make-sum-divisible-l-p/description/?envType=daily-question&envId=2024-10-03
// Problem Link: https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2025-11-30

// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         long long tt=0;
//         for(auto &c:nums)tt+=c;
//         int rem=tt%p;
//         if(rem==0)return 0;
        
//         map<int,int>mp;
//         mp[0]=-1;
//         long long ps=0;
//         int ans=nums.size();

//         for(int i=0;i<nums.size();i++){
//             ps+=nums[i];
//             int currMod=ps%p;
//             int tMod=(currMod-rem+p)%p;

//             if(mp.find(tMod)!=mp.end())ans=min(ans,i-mp[tMod]);
//             mp[currMod]=i;
//         }

//         return ans==nums.size()?-1:ans;
//     }
// };

// // TIme Complexity : O(2*N) => O(N);
// // Space Complexity: O(N;

// way => 2 (Easy way);

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tt=0,n=nums.size();
        for(auto &c:nums)tt+=c,tt%=p;
        if(tt==0)return 0;

        int ans=n,sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=p;

            int diff=(sum-tt+p)%p;
            if(mp.count(diff))ans=min(ans,i-mp[diff]);

            mp[sum]=i;
        }

        return ans==n?-1:ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);
