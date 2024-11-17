// Problem Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/?envType=daily-question&envId=2024-11-17

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        int j=0,n=nums.size(),ans=n+1;
        vector<long long>pref(n+1);pref[0]=nums[0];
        for(int i=1;i<n+1;i++)pref[i]=pref[i-1]+nums[i-1];
        while(j<n+1){   
            pq.push({pref[j],j}); 
            while(pq.size() && pref[j]-pq.top().first>=k){
                auto c=pq.top();pq.pop();
                ans=min(ans,j-c.second);
            }
            j++;
        }
        return ans==n+1?-1:ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);