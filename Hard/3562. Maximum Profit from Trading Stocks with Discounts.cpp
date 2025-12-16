// Problem Link: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/description/?envType=daily-question&envId=2025-12-16

class Solution {
public:
    int b;
    vector<vector<int>>tree;
    vector<int>curr,next;
    vector<vector<vector<int>>>dp;

    vector<int> merge(auto &a,auto &b2){
        vector<int>vc(b+1,INT_MIN);

        for(int i=0;i<=b;i++){
            if(a[i]<0)continue;
            for(int j=0;i+j<=b;j++){
                vc[i+j]=max(vc[i+j],a[i]+b2[j]);
            }
        }
        return vc;
    }

    void dfs(int u){
        dp[u][0]=vector<int>(b+1,0);
        dp[u][1]=vector<int>(b+1,0);

        for(auto &v:tree[u])dfs(v);

        for(int i=0;i<=1;i++){
            int price=i?curr[u]/2:curr[u];
            int profit=next[u]-price;

            vector<int>skip(b+1,0),take(b+1,INT_MIN);

            for(auto &v:tree[u])skip=merge(skip,dp[v][0]);

            if(price<=b){
                vector<int>base(b+1,0);
                for(auto &v:tree[u]){
                    base=merge(base,dp[v][1]);
                }
                for(int j=price;j<=b;j++){
                    take[j]=base[j-price]+profit;
                }
            }

            for(int j=0;j<=b;j++){
                dp[u][i][j]=max(skip[j],take[j]);
            }
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->b=budget;
        this->curr=present;
        this->next=future;
        tree.assign(n,{});

        for(auto &e:hierarchy){
            --e[0],--e[1];
            tree[e[0]].push_back(e[1]);
        }
       
        dp.assign(n,vector<vector<int>>(2));
        dfs(0);
        
        int ans=0;
        for(int i=0;i<=b;i++){
            ans=max(ans,dp[0][0][b]);
        }
        return ans;
    }
};

// Time Complexity : O(N*(B^2)) => O(N^3);
// Space Complexity: O(N*B) => O(N^2);
// Here B is "budget";