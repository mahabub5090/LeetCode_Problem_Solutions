// Problem Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.rbegin(),batteries.rend());
        long long ex=0;
        for(int i=n;i<batteries.size();i++)ex+=batteries[i];

        vector<int>curr(batteries.begin(),batteries.begin()+n);
        reverse(curr.begin(),curr.end());

        for(int i=0;i<n-1;i++){
            if(ex<1ll*(i+1)*(curr[i+1]-curr[i])){
                return curr[i]+ex/(i+1);
            }
            ex-=1ll*(i+1)*(curr[i+1]-curr[i]);
        }
        return curr[n-1]+ex/n;
    }
};

// Time Complexity : O(M * logM) => O(NlogN);
// Space Complexity: O(M) => O(N);