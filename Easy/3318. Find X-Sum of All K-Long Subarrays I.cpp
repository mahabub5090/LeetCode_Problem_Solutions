// Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n-k+1;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<i+k;j++)mp[nums[j]]++;

            vector<pair<int,int>>vc;
            for(auto &c:mp)vc.push_back(c);
            sort(vc.begin(),vc.end(),[](auto &c,auto &d){
                if(c.second==d.second)return c.first>d.first;
                return c.second>d.second;
            });

            int sum=0;
            for(int j=0;j<x && x<=vc.size();j++){
                sum+=vc[j].first*vc[j].second;
            }
            if(x>vc.size())sum=accumulate(nums.begin()+i,nums.begin()+i+k,0);

            ans.push_back(sum);
        }
        return ans;
    }
};

// Time Complexity : O(N*k*logK) => O((N^2)logN);
// Space Complexity: O(K) => O(N);