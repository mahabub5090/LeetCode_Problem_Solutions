// Problem Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum=neededTime[0],mx=neededTime[0],ans=0;
        char prev=colors[0];
        for(int i=1;i<colors.size();i++){
            if(prev==colors[i])mx=max(mx,neededTime[i]),sum+=neededTime[i];
            else{
                ans+=sum-mx;
                sum=neededTime[i];
                mx=neededTime[i];
                prev=colors[i];
            }
        }
        ans+=sum-mx;
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);