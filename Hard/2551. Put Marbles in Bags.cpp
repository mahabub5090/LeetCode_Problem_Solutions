// Problem Link: https://leetcode.com/problems/put-marbles-in-bags/description/?envType=daily-question&envId=2025-03-31

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>pw(n-1,0);
        for(int i=0;i<n-1;i++){
            pw[i]+=weights[i]+weights[i+1];  
        }
        
        sort(pw.begin(),pw.end());

        long long ans=0;
        for(int i=0;i<k-1;i++)ans+=pw[n-i-2]-pw[i];
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);