// Problem Link: https://leetcode.com/problems/maximum-total-subarray-value-ii/description/?envType=daily-question&envId=2026-06-10

class Solution {
public:
    int queryMax(int l,int r,auto &stMax,auto &stMin){
            int j=31-__builtin_clz(r-l+1);
            return max(stMax[l][j],stMax[r-(1<<j)+1][j]);
        };

    int queryMin(int l,int r,auto &stMax,auto &stMin){
            int j=31-__builtin_clz(r-l+1);
            return min(stMin[l][j],stMin[r-(1<<j)+1][j]);
    };


    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        int logn=32-__builtin_clz(n);
        vector<vector<int>> stMax(n,vector<int>(logn)), stMin=stMax;

        for(int i=0;i<n;i++) stMax[i][0]=stMin[i][0]=nums[i];

        for(int j=1;j<logn;j++){
            for(int i=0;i+(1<<j)<=n;i++){
                stMax[i][j]=max(stMax[i][j-1],stMax[i+(1<<(j-1))][j-1]);
                stMin[i][j]=min(stMin[i][j-1],stMin[i+(1<<(j-1))][j-1]);
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        for(int l=0;l<n;l++){
            int val=queryMax(l,n-1,stMax,stMin)-queryMin(l,n-1,stMax,stMin);
            pq.push({val,l,n-1});
        }
            
        long long ans=0;
        while(k--){
            auto [val,l,r]=pq.top();
            pq.pop();

            ans+=val;

            if(l<r){
                int val=queryMax(l,r-1,stMax,stMin)-queryMin(l,r-1,stMax,stMin);
                pq.push({val,l,r-1});
            }    
        }
        return ans;
    }
};

// Time Complexity : O(N)+ O(logN*N) + O(NlogN) + O(K*(logN+logN)) => O(NlogN) + O(KlogN);
// Space Complexity: O(NlogN) + O(N) => O(NlogN);