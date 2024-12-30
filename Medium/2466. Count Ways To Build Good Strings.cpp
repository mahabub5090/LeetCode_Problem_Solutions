// Problem Link: https://leetcode.com/problems/count-ways-to-build-good-strings/submissions/1492432038/?envType=daily-question&envId=2024-12-30

class Solution {
public:
    int mod=1e9+7;
    vector<int>vc;
    int dfs(int len,int z,int o,int l,int h){
        if(len>h)return 0;
        if(vc[len]!=-1)return vc[len];
        int cnt=0;
        if(len>=l)cnt+=1;
        cnt+=dfs(len+z,z,o,l,h)+dfs(len+o,z,o,l,h);
        return vc[len]=cnt%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vc.assign(high+1,-1);
        return dfs(0,zero,one,low,high);
    }
};

// Time Complexity : O(H) => O(N); 
// Space Complexity: O(H) => O(N); 
// H is the maximam high value here.
