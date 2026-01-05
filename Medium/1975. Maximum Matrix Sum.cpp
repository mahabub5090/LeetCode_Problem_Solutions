// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/submissions/1461400347/?envType=daily-question&envId=2024-11-24
// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

// class Solution {
// public:
//     long long maxMatrixSum(vector<vector<int>>& matrix) {
//         int neg=0,zero=0,mn=1e9;
//         long long ans=0;
//         for(auto &c:matrix){
//             for(auto &cc:c){
//                 if(cc==0)zero++;
//                 else if(cc<0)neg++;
//                 mn=min(mn,abs(cc));
//             }
//         }
//         if(neg%2==0 || (neg%2 && zero)){
//             return ans;
//         }
//         return ans-abs(2*mn);
//     }
// };

// // Time Complexity : O(N*M) => O(N^2);
// // Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0,zero=0,neg=0,mn=INT_MAX;
        for(auto &c:matrix){
            for(auto &cc:c){
                if(cc==0)zero++;
                if(cc<0)neg++;
                sum+=abs(cc);
                mn=min(mn,abs(1ll*cc));
            }
        }
        if(zero==0 && neg%2)sum-=2*mn;
        return sum;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(1);