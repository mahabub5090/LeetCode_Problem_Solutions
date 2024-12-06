// Problem Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;for(auto &c:banned)mp[c]++;
        int cnt=0,tt=0;
        for(int i=1;i<=n;i++){
            if(mp[i])continue;
            if(tt+i<=maxSum)cnt++,tt+=i;
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);