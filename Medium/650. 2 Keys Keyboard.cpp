// Problem Link: https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

// class Solution {
// public:
//     int minSteps(int n) {
//         int dp[10005];
//         dp[1]=0;
//         for(int i=2;i<=n;i++){
//             dp[i]=i;
//             for(int j=1;j<=i/2;j++){
//                 if(i%j==0)dp[i]=min(dp[i],dp[j]+i/j);
//             }
//         }
//         return dp[n];
//     }
// };

// // Time Complexity : O(N*N) => O(N^2);
// // space Complexity: O(1);

class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        int ans=0,curr=2;
        while(curr<=n){
            if(n%curr==0)ans+=curr,n/=curr;
            else curr++;
        }
        return ans;
    }
};

// Time Complexity : O(N); 
// space Complexity  O(1);