// Problem Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2025-10-27

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,n=bank.size(),m=bank[0].size();
        int cnt=0;
        int i=0;
        while(cnt==0 && i<n)cnt=count(bank[i].begin(),bank[i].end(),'1'),i++;

        for(;i<n;i++){
            int cnt2=count(bank[i].begin(),bank[i].end(),'1');
            if(cnt2){
                ans+=cnt*cnt2;
                cnt=cnt2;
            }
        }

        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);