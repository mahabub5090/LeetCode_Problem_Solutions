// Problem Link: https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long ans=0,n=nums.size();
            for(int i=0;i<n;i++)nums[i]-=i+1;
            unordered_map<int,int>l,r;
            for(auto &c:nums)r[c]++;
            for(int i=0;i<n;i++){
                int c=nums[i];
                r[c]--;
                ans+=i-l[c];
                l[c]++;
            }
            return ans;
        }
    };
    
    // Time Complexity : O(N);
    // Space Complexity: O(2*N) => O(N);