// Problem Link: https://leetcode.com/problems/jump-game-vii/description/?envType=daily-question&envId=2026-05-25

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> pref(n),dp(n);

        for(int i=0;i<minJump;i++) pref[i]=1;
        for(int i=minJump;i<n;i++){
            int left=i-maxJump, right=i-minJump;

            if(s[i]=='0'){
                int tt=pref[right]-(left<=0?0:pref[left-1]);
                dp[i]=(tt!=0);
            }
            pref[i]=pref[i-1]+dp[i];
        }
        return dp[n-1];
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N) + O(N) => O(N);