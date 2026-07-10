// Problem Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/description/?envType=daily-question&envId=2026-07-10

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> index(n), pos(n);

        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int a,int b){
            return nums[a]<nums[b];
        });

        for(int i=0;i<n;i++) pos[index[i]]=i;

        int m=32-__builtin_clz(n);
        vector<vector<int>> f(n,vector<int>(m,0));

        int left=0;
        for(int i=0;i<n;i++){
            while(nums[index[i]]-nums[index[left]]>maxDiff) left++;
            f[i][0]=left;
        }

        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++) {
                int prev=f[i][j-1];
                f[i][j]=f[prev][j-1];
            }
        }

        vector<int> ans;
        for(auto &c:queries){
            auto x=pos[c[0]], y=pos[c[1]];

            if(x>y) swap(x,y);
            if(x==y) ans.push_back(0);
            else{
                int step=0;
                for(int i=m-1;i>=0;i--){
                    if(f[y][i]>x){
                        y=f[y][i];
                        step+=(1<<i);
                    }
                }
                if(f[y][0]<=x) ans.push_back(step+1);
                else ans.push_back(-1);
            }
        }
        return ans;   
    }
};

// Time Complexity : O(NlogN) + O(N) + O(M*N) + O(Q*M) => O(NlogN + M*N + Q*M);
// Space Complexity: O(N) + O(N) + O(N*M) + O(Q) => O(N*M + Q);
// Q = queries.size(), M = total bits in N, 1<= M <= 18 and 1 <= N,Q <= 1e5;