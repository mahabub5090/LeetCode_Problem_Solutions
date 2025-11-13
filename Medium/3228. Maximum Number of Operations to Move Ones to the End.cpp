// Problem Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

// class Solution {
// public:
//     int maxOperations(string s) {
//         int n=s.size();
//         vector<int>pref(n,0);
//         for(int i=0;i<n;i++)pref[i]+=s[i]=='1';
//         for(int i=1;i<n;i++)pref[i]+=pref[i-1];
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='0'){
//                 while(i<n && s[i]!='1')i++;
//                 ans+=pref[i-1];
//             }
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(N);

// Way : 2 =>

class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                while(i<n && s[i]!='1')i++;
                i--;
                ans+=cnt;
            }
            else cnt++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);