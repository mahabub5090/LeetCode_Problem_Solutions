// Problem Link: https://leetcode.com/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03

class Solution {
public:
    unordered_map<int,int> memo;
    int solve(int i,auto &arr){
        int n=arr.size();
        if(i==n) return 0;
        if(memo.count(i)) return memo[i];

        memo[i]=arr[i]-solve(i+1,arr);

        if(i+1<n) memo[i]=max(memo[i],arr[i]+arr[i+1]-solve(i+2,arr));
        if(i+2<n) memo[i]=max(memo[i],arr[i]+arr[i+1]+arr[i+2]-solve(i+3,arr));

        return memo[i];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int ans=solve(0,stoneValue);
        if(ans==0) return "Tie";
        if(ans>0) return "Alice";
        return "Bob";
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);