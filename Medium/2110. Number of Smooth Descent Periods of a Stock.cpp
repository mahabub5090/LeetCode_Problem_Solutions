// Problem Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=n;
        int cnt=0,prev=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]==prev-1){
                ans+=++cnt;
            }
            else cnt=0;
            
            prev=prices[i];
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);