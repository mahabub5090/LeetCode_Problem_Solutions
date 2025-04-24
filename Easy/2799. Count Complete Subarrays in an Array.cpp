// Problem Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;for(auto &c:nums)mp[c]++;
        int n=nums.size(),dist=mp.size();
        int cnt=0,i=0,j=0;
        mp.clear();
        while(j<n){           
            mp[nums[j]]++;
            j++;
            while(i<n && mp.size()==dist){
                cnt+=n-j+1;
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);