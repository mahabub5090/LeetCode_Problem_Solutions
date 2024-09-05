// Problem Link: https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int need=mean*(n+rolls.size());
        for(auto &c:rolls)need-=c;
        int mid=need/n;
        int rem=need%n;
        vector<int>ans(n,mid);
        for(int i=0;i<rem;i++)ans[i]++;
        if(ans[n-1]<1 || ans[0]>6)return {};
        return ans;
    }
};

// Time Complexity : 2*O(N) => O(N);
// Space Complexity: O(N);