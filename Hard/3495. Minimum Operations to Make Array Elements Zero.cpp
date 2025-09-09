// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/?envType=daily-question&envId=2025-09-06

class Solution {
public:
    long long get(int num){
        int i=1,base=1;
        long long cnt=0;
        while(base<=num){
            cnt+=1ll*(i+1)/2*(min(base*2-1,num)-base+1);
            i++;2327. Number of People Aware of a Secret
            base*=2;
        }
        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto &c:queries){
            ans+=(get(c[1])-get(c[0]-1)+1)/2;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);