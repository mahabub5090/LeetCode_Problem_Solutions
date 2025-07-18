// Problem Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/?envType=daily-question&envId=2025-07-18

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        vector<long long>part(n+1);
        long long sum=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        part[0]=sum;
        for(int i=n;i<2*n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
            sum-=pq.top();
            pq.pop();
            part[i-(n-1)]=sum;
        }

        long long part2=0;
        priority_queue<int,vector<int>,greater<int>>pq2;
        for(int i=n*3-1;i>=n*2;i--){
            part2+=nums[i];
            pq2.push(nums[i]);
        }

        long long ans=part[n]-part2;
        for(int i=n*2-1;i>=n;i--){
            part2+=nums[i];
            pq2.push(nums[i]);
            part2-=pq2.top();
            pq2.pop();
            ans=min(ans,part[i-n]-part2);
        }
        return ans;
    }
};

// Time Complexity : O(2*NlogN)+O(3*N) => O(NlogN);
// Space Complexity: O(3*N) => O(N);