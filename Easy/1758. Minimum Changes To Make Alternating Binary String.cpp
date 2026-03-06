// Problem Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05

// class Solution {
// public:
//     int minOperations(string s) {
//         int ans=0,n=s.size();
//         char curr='0',curr2='1';
//         for(auto &c:s){
//             if(c!=curr)ans++;
//             if(c!=curr2)ans2++;
//             curr='0'+(curr=='0');
//             curr2='0'+(curr2=='0');
//         }
//         return min(ans,ans2);
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    int minOperations(string s) {
        int ans=0,n=s.size();
        char curr='0';
        for(auto &c:s){
            if(c!=curr)ans++;
            curr='0'+(curr=='0');
        }
        return min(ans,n-ans);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);