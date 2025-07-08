// Problem Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2025-07-08

class Solution {
public:
    vector<vector<int>>dp;
    vector<int>prev;

    int dfs(int i,int k,auto &events){
        if(i<0 || k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];

        int skip=dfs(i-1,k,events);
        int take=events[i][2]+dfs(prev[i],k-1,events);
        return dp[i][k]=max(skip,take);
    }

    int maxValue(vector<vector<int>>& events, int k) {      
        int n=events.size();
        sort(events.begin(),events.end(),[](auto &c,auto &d){
            return c[1]<d[1];
        });

        prev.resize(n,-1);

        for(int i=0;i<n;i++){
            int l=0,r=i-1;
            while(l<=r){
                int mid=(l+r)/2;

                if(events[mid][1]<events[i][0]){
                    prev[i]=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
        }

        dp.assign(n,vector<int>(k+1,-1));
        return dfs(n-1,k,events);
    }
};

// Time Complexity : O(2*(NlogN)) + (N*K) => O(NlogN + (N*K));
// Space Complexity: O(N) + O(N*K) => O(N*K);
// Here (N*K)<=1e6;