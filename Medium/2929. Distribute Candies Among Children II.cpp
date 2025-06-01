// Problem Link: https://leetcode.com/problems/distribute-candies-among-children-ii/description/?envType=daily-question&envId=2025-06-01

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<=min(n,limit);i++){
            int rest=n-i;
            if(rest<=2*limit){
                ans+=min(rest,limit)-max(0,rest-limit)+1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(min(n,limit)) => O(N);
// Space Complexity: O(1);