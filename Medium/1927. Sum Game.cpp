// Problem Link: https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23

// class Solution {
// public:
//     bool sumGame(string num) {
//         int n=num.size();
//         pair<int,int> left, right;

//         for(int i=0;i<n;i++){
//             if(i<n/2){
//                 if(num[i]=='?') left.second++;
//                 else left.first+=num[i]-'0';
//             }
//             else{
//                 if(num[i]=='?') right.second++;
//                 else right.first+=num[i]-'0';
//             }
//         }
//         if((left.second+right.second)%2) return 1;

//         int aliceLeft=(left.second+1)/2, aliceRight=(right.second+1)/2;

//         int leftMax=left.first+aliceLeft*9;
//         int rightMax=right.first+aliceRight*9;
        
//         int leftScope=(left.second/2+right.second%2)*9;
//         int rightScope=(right.second/2+left.second%2)*9;

//         int cnt=0;
//         if(leftMax>=right.first) cnt+=(right.first+rightScope>=leftMax);
//         else cnt+=(leftMax+leftScope>=right.first);

//         if(rightMax>=right.first) cnt+=(left.first+leftScope>=rightMax);
//         else cnt+=(rightMax+rightScope>=left.first);
        
//         return cnt<2;
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(1);


// Way : 2 =>

class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        pair<int,int> left, right;

        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?') left.second++;
                else left.first+=num[i]-'0';
            }
            else{
                if(num[i]=='?') right.second++;
                else right.first+=num[i]-'0';
            }
        }
        if((left.second+right.second)%2) return 1;

        auto &[ls,lq]=left;
        auto &[rs,rq]=right;

        return !(2*(ls-rs)==(rq-lq)*9);
        // Bob can only wins if, ls+lq*(9/2) == rs+rq*(9/2); // 9/2=4.5;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);