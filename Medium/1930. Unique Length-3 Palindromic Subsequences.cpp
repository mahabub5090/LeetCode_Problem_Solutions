// Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
// Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-11-21

// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         map<char,int>mp;
//         for(auto &c:s)mp[c]++;
//         set<char>st;
//         set<string>ans;
//         string cmp="";
//         for(auto &c:s){
//             mp[c]--;
//             for(auto &cc:st){
//                 if(mp[cc]>0){
//                     cmp+=c;cmp+=cc;
//                     ans.insert(cmp);
//                     cmp="";
//                 }
//             }
//             st.insert(c);
//         }
//         return ans.size();
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0,n=s.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++)mp[s[i]].push_back(i);
        for(auto &[cc,vc]:mp){
            int len=vc.size();
            if(len==1)continue;
            int l=vc[0],r=vc[len-1];
            unordered_map<char,int>cnt;
            for(int i=l;i<=r;i++)cnt[s[i]]++;
            ans+=cnt.size()-(cnt.count(cc) && cnt[cc]<3);
            // ans+=cnt.size()-(len==2); // same as previous line;
        }
        return ans;
    }
};

// Time Complexity : O(26*N) => O(N);
// Space Complexity: O(N);