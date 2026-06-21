// Problem Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxVal=*max_element(costs.begin(),costs.end());
        vector<int> freq(maxVal);
        for(auto &c:costs) freq[c-1]++;
        for(int i=1;i<maxVal;i++) freq[i]+=freq[i-1];

        int n=costs.size();
        vector<int> sortedCost(n);
        for(int i=0;i<n;i++){
            int c=costs[i];
            sortedCost[freq[c-1]-1]=c;
            freq[c-1]--;
        }

        // for(auto &c:sortedCost)cout<<c<<" ";

        int cnt=0;
        for(auto &c:sortedCost){
            coins-=c;
            if(coins>=0) cnt++;
            else break;
        }
        return cnt;
    }
};

// Time Complexity : O(M) + O(M) + O(N) + O(N) => O(N+M);
// Space Complexity: O(M) + O(N) => O(N+M);
// N = costs.size(), M = max(cost[i]);