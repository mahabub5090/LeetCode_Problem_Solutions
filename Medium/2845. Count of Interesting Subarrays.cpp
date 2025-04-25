// Problem Link: https://leetcode.com/problems/count-of-interesting-subarrays/description/?envType=daily-question&envId=2025-04-25

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        map<int,int>cnt;
        int pref=0;
        cnt[0]=1;

        for(auto &c:nums){
            pref+=c%modulo==k;
            ans+=cnt[(pref-k)%modulo];
            cnt[pref%modulo]++;
        }
        return ans;
    }
};

// Time Complexity : O(N*log(modulo)) => O(NlogN);
// Space Complexity: O(modulo) => O(N);