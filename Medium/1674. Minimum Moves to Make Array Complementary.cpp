// Problem Link: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/?envType=daily-question&envId=2026-05-13

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2*limit+2,0);

        for(int i=0;i<n/2;i++){
            int mn=min(nums[i],nums[n-1-i]);
            int mx=max(nums[i],nums[n-1-i]);

            diff[2]+=2;
            diff[mn+1]-=1;
            diff[mn+mx]-=1;
            diff[mn+mx+1]+=1;
            diff[mx+limit+1]+=1;
        }

        int ans=n, curr=0;
        for(int i=2;i<=2*limit;i++){
            curr+=diff[i];
            ans=min(ans,curr);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N+limit) => O(N);
// Space Complexity: O(2*limit+2) => O(N);