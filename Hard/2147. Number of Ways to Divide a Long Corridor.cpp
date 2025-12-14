// Problem Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/?envType=daily-question&envId=2025-12-14

class Solution {
public:
    int numberOfWays(string corridor) {
        long long cnt=1;
        int seat=0,prev=-1,mod=1e9+7;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                seat++;
                if(seat==2)prev=i,seat=0;
                else if(seat==1 && prev!=-1){
                    cnt*=(i-prev);
                    cnt%=mod;
                }
            }
        }

        if(seat==1 || prev==-1)return 0;
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);