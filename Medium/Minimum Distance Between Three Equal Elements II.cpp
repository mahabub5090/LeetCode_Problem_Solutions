// Problem Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n,-1);
        unordered_map<int,int>occurs;
        int ans=n+1;

        for(int i=n-1;i>=0;i--){
            if(occurs.count(nums[i])){
                next[i]=occurs[nums[i]];
            }
            occurs[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            int secondPos=next[i];
            if(secondPos!=-1){
                int thirdPos=next[secondPos];
                if(thirdPos!=-1){
                    ans=min(ans,thirdPos-i);
                }
            }
        }
        return ans==n+1?-1:2*ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);