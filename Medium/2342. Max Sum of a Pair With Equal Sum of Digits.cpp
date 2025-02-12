// Problem Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            map<int,priority_queue<int,vector<int>,greater<int>>>mp;
            for(auto &c:nums){
                string s=to_string(c);
                int sum=0;
                for(auto &cc:s)sum+=cc-'0';
                mp[sum].push(c);
                if(mp[sum].size()>2)mp[sum].pop();
            }
            int ans=-1;
            for(auto &c:mp){
                if(c.second.size()<2)continue;
                auto pq=c.second;
                int sum=pq.top();
                pq.pop();
                sum+=pq.top();
                ans=max(ans,sum);
            }
            return ans;
        }
    };
    
    // Time Complexity : O(N*9) + O(81*2) => O(N);
    // Space Complexity: O(N);