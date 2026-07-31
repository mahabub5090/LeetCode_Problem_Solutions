// Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/?envType=daily-question&envId=2026-07-30

// class Solution {
// public:
//     int minimumPushes(string word) {
//         int push=0, curr=1, ans=0;
//         for(auto &c:word){
//             push++;
//             if(push>8) curr++, push%=8;
//             ans+=curr;
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(1);


// Way: 2 =>

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int mx=n/8, rem=n%8;
        int ans=8*(mx*(mx+1)/2) + (rem*(mx+1));
        return ans;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);