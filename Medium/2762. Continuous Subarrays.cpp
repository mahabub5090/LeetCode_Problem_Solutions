// Problem Link: https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int i=0,j=0;
        priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        while(j<nums.size()){
            while(pq.size() && (abs(pq.top().first-nums[j])>2)){
                if(i<=pq.top().second)i=pq.top().second+1;
                pq.pop();
            }
            while(pq2.size() && (abs(pq2.top().first-nums[j])>2)){
                if(i<=pq2.top().second)i=pq2.top().second+1;
                pq2.pop();
            }
            pq.push({nums[j],j});
            pq2.push({nums[j],j});
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);