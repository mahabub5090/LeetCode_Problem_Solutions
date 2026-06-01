// Problem Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int ans=0, n=cost.size();
        for(int i=0;i<n;i+=3){
            if(i<n) ans+=cost[i];
            if(i+1<n) ans+=cost[i+1];
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(logN); // for sorting recursion stack;