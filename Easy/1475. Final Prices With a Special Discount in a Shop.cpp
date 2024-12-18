// Problem Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/submissions/1482008302/?envType=daily-question&envId=2024-12-18

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    prices[i]-=prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);