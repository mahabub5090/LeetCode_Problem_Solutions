// Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n=s.size();
//         vector<int>pref(n+1,0),suff(n+1,0);
//         for(int i=1;i<n+1;i++){
//             pref[i]+=pref[i-1]+(s[i-1]=='b');
//             suff[n-i]+=suff[n-i+1]+(s[n-i]=='a');
//         }

//         int ans=n;
//         for(int i=0;i<n+1;i++)ans=min(ans,pref[i]+suff[i]);
//         return ans;
//     }
// };

// // Time Complexity : O(2*N) => O(N);
// // Space Complexity: O(2*N) => O(N);

// Way: 2 =>

class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,b=0,ans=s.size();
        for(auto &c:s)a+=(c=='a');
        for(auto &c:s){
            a-=(c=='a');
            ans=min(ans,a+b);
            b+=(c=='b');
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);