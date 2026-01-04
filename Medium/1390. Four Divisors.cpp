// Problem Link: https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

class Solution {
public:
    vector<vector<int>>divisors;

    void storeDivisors(int &n){
        divisors.resize(n+1);

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                divisors[j].push_back(i);
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        storeDivisors(mx);

        int ans=0;
        for(auto &c:nums){
            auto &vc=divisors[c];
            if(vc.size()==4){
                ans+=accumulate(vc.begin(),vc.end(),0);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(M log M) => O(NlogN);
// Space Complexity: O(M log M) => O(NlogN);
// M is the max element(value) of 'nums' array;