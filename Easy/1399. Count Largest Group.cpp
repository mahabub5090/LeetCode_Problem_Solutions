// Problem Link: https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23

class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        int mx=0;
        for(int i=1;i<=n;i++){
            int sum=0,c=i;
            while(c)sum+=c%10,c/=10;
            mp[sum]++;
            mx=max(mx,mp[sum]);
        }
        int cnt=0;
        for(auto &c:mp)if(c.second==mx)cnt++;
        return cnt;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(logN);