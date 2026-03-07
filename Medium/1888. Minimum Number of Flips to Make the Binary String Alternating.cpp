// Problem Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07

class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        vector<vector<int>>pref(n,vector<int>(2));
        for(int i=0;i<n;i++){
            pref[i][0]=(i?pref[i-1][1]:0)+(s[i]=='1');
            pref[i][1]=(i?pref[i-1][0]:0)+(s[i]=='0');
        }

        int ans=min(pref[n-1][0],pref[n-1][1]);
        if(n%2){
            vector<vector<int>>suff(n,vector<int>(2));
            for(int i=n-1;i>=0;i--){
                suff[i][0]=(i+1<n?suff[i+1][1]:0)+(s[i]=='1');
                suff[i][1]=(i+1<n?suff[i+1][0]:0)+(s[i]=='0');
            }

            for(int i=0;i<n-1;i++){
                ans=min({ans,pref[i][0]+suff[i+1][0],pref[i][1]+suff[i+1][1]});
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(N) => O(N);
// Space Complexity: O(N*2) + O(N*2) => O(N);