// Problem Link: https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod=1e9+7;
        unordered_map<int,int>mp;
        for(auto &c:points)mp[c[1]]++;

        long long ans=0,sum=0;
        for(auto &c:mp){
            long long edge=1ll*c.second*(c.second-1)/2;
            ans+=edge*sum;
            ans%=mod;
            sum+=edge;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);