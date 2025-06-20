// Problem Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/?envType=daily-question&envId=2025-06-20

class Solution {
public:
    int getAns(int x,int y,auto &s,int k){
        int ans=0,curr=0;
        for(auto &c:s){
            if(c=='N')curr+=(x?1:(k-->0?1,1:-1));
            else if(c=='S')curr+=(x==0?1:(k-->0?1:-1));
            else if(c=='E')curr+=(y?1:(k-->0?1:-1));
            else curr+=(y==0?1:(k-->0?1:-1));
            ans=max(ans,curr);
        }
        return ans;
    }
    int maxDistance(string s, int k) {
        int ans=0;
        ans=getAns(1,1,s,k);
        ans=max(ans,getAns(0,1,s,k));
        ans=max(ans,getAns(1,0,s,k));
        ans=max(ans,getAns(0,0,s,k));
        return ans;
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(1);
