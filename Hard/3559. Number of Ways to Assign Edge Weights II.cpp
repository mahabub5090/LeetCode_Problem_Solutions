// Problem Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/description/?envType=daily-question&envId=2026-06-12

class Solution {
public:
    int mod=1e9+7;
    vector<int> pw;

    class LCA{
        public:
            int n,m;
            vector<int> d;
            vector<vector<int>> e, f;

            void dfs(int x,int fa){
                f[x][0]=fa;
                for(auto &c:e[x]){
                    if(c==fa) continue;
                    d[c]=d[x]+1;
                    dfs(c,x);
                }
            }

            LCA(auto &edges,const int root=1){
                n=edges.size()+1;
                m=(log(n)/log(2))+1;
                d.resize(n+1);
                e.resize(n+1);
                f.resize(n+1,vector<int>(m,0));

                for(auto &c:edges){
                    e[c[0]].push_back(c[1]);
                    e[c[1]].push_back(c[0]);
                }

                dfs(root,0);

                for(int i=1;i<m;i++){
                    for(int j=1;j<=n;j++) f[j][i]=f[f[j][i-1]][i-1];
                }
            }


            int getLCA(int x,int y){
                if(d[x]>d[y]) swap(x,y);

                for(int i=m-1;i>=0;i--){
                    if(d[x]<=d[f[y][i]]) y=f[y][i];
                }

                if(x==y) return x;

                for(int i=m-1;i>=0;i--){
                    if(f[x][i]!=f[y][i]){
                        x=f[x][i];
                        y=f[y][i];
                    }
                }
                return f[x][0];
            }

            int dis(int x,int y){
                int lca=getLCA(x,y);
                return (d[x]+d[y])-(d[lca]*2);
            }
    };


    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        pw.resize(1e5+1);
        pw[0]=1;
        for(int i=1;i<1e5+1;i++) pw[i]=(pw[i-1]*2)%mod;

        LCA lca(edges,1);
        int Q=queries.size();
        vector<int> ans(Q);

        for(int i=0;i<Q;i++){
            int x=queries[i][0], y=queries[i][1];
            if(x!=y) ans[i]=pw[lca.dis(x,y)-1];
        }
        return ans;
    }
};

// Time Complexity : O(1e5+1) + O(E+V+E+(logV*V)) + O(Q*logV) => O(NlogN);
// Space Complexity: O(1e5+1) + O(V) + O(V+E) + O(VlogV) + O(Q) => O(NlogN);
// N<=1e5, V<=N, E==V-1 , Q<=N;