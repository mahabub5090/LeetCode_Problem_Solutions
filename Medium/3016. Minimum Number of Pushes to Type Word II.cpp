// Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06
// Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31

// class Solution {
// public:
//     int minimumPushes(string word) {
//         vector<int>vc(26);
//         for(auto &c:word)vc[c-'a']++;
//         sort(vc.begin(),vc.end(),greater<int>());
//         int ans=0,cnt=0;
//         for(auto &c:vc){
//             ans+=c*(1+(cnt++/8));
//         }
//         return ans;   
//     }
// };

// // Time Complexity : O(N+log26+26) => O(N);
// // Space Complexity: O(26) => O(1); 


// way: 2 =>

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26,0);
        for(auto &c:word) cnt[c-'a']++;
        sort(cnt.rbegin(),cnt.rend());

        int push=0, curr=1, ans=0;
        for(auto &c:cnt){
            if(c==0) break;

            push++;
            if(push>8) curr++, push%=8;
            ans+=curr*c;
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(log26) + O(26) => O(N);
// Space Complexity: O(26) => O(1);