// Problem Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt[4]={0};
        int f=0,f2=1;
        for(auto &c:nums){
            cnt[c%2]++;
            if(f==0 != c%2)cnt[2]++,f=!f;
            if(f2==0 != c%2)cnt[3]++,f2=!f2;
        }
        return max({cnt[0],cnt[1],cnt[2],cnt[3]});
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
