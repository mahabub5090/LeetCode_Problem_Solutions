// Problem Link: https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09

// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         long long ans=x;
//         for(long long i=1;i<=n-1;i++){
//             ans=(ans+1)|x;
//         }
//         return ans;
//     }
// };

// Time Complexity : O(N);
// Space Complexity: O(1);

// Way-2 =>

class Solution {
public:
    long long minEnd(int n, int x) {
        long long in=1,ix=1,ans=x;    
        while(in<=n-1){
            if((ix&x)==0){
                if((in&(n-1))){
                    ans|=ix;
                }
                in<<=1;
            }
            ix<<=1;
        }
        return ans;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);
