// Problem Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>Q;
        for(int i=0;i<n;i++)Q.push(i+1);
        int cnt=0;
        while(Q.size()>1){
           int curr=Q.front();
           Q.pop(); cnt++;
           if(cnt==k)cnt=0;
           else Q.push(curr);
        }
        return Q.front();
    }
};

// Time-Complexity => O(N*K) => O(N*N);
// Space-Complexity => O(N);

// Can't solve the follow-up question of it.
