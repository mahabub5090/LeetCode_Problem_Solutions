// Problem Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

// class Solution {
// public:
//     int maxScore(string s) {
//         int ans=0;
//         for(int i=0;i<s.size()-1;i++){
//             int cnt=0;
//             for(int j=0;j<=i;j++)cnt+=s[j]=='0';
//             for(int j=i+1;j<s.size();j++)cnt+=s[j]=='1';
//             ans=max(ans,cnt);
//         }
//         return ans;
//     }
// };

// Time Complexity : O(N^2);
// Space Complexity: O(1); 

// Way: 2 =>

class Solution {
public:
    int maxScore(string s) {
        int ans=0,zero=0,one=count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size()-1;i++){
            zero+=s[i]=='0';
            one-=s[i]=='1';
            ans=max(ans,zero+one);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1); 