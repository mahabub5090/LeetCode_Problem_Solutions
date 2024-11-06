// Problem Link: https://leetcode.com/problems/find-if-array-can-be-sorted/submissions/1444485119/?envType=daily-question&envId=2024-11-06

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int>ans,temp;
        temp.push_back(nums[0]);
        map<int,int>mp;
        mp[__builtin_popcount(nums[0])]++;
        for(int i=1;i<nums.size();i++){
            int cnt=__builtin_popcount(nums[i]);
            if(mp[cnt]){
                temp.push_back(nums[i]);
                mp[cnt]++;
            }
            else{
                sort(temp.begin(),temp.end());
                for(auto &c:temp)ans.push_back(c);
                temp.clear();
                temp.push_back(nums[i]);
                mp.clear();
                mp[cnt]++;
            }
        }
        sort(temp.begin(),temp.end());
        for(auto &c:temp)ans.push_back(c);
        return is_sorted(ans.begin(),ans.end());
    }
};

// Time Complexity : O((N^2)logN);
// Space Complexity: O(N);
