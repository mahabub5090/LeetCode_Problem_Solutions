// Problem Link: https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>l,r;
        for(auto &c:nums)r[c]++;

        long long ans=0,mod=1e9+7;

        for(auto &c:nums){
            r[c]--;
            if(l.count(c*2) && r.count(c*2)){
                ans+=1ll*l[c*2]*r[c*2];
                ans%=mod;
            }
            l[c]++;
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);
