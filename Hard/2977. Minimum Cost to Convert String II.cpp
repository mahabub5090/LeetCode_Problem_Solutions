// Problem Link: https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30

class Solution {
public:
    class Trie{
        public:
        
        Trie* child[26];
        int id;

        Trie(){
            for(int i=0;i<26;i++)child[i]=NULL;
            id=-1;
        }
    };
    int add(auto node,auto &word,int &index){
        for(auto &c:word){
            int i=c-'a';
            if(node->child[i]==NULL)node->child[i]=new Trie();
            node=node->child[i];
        }
        if(node->id==-1)node->id=++index;
        return node->id;
    }
    void update(auto &x,auto y){
        if(x==-1 || x>y)x=y;
    }


    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=source.size(),m=original.size();

        Trie* root=new Trie();

        int p=-1;
        vector<vector<int>>G(m*2,vector<int>(m*2,INT_MAX/2));
        for(int i=0;i<m*2;i++)G[i][i]=0;

        for(int i=0;i<m;i++){
            int x=add(root,original[i],p);
            int y=add(root,changed[i],p);
            G[x][y]=min(G[x][y],cost[i]);
        }

        for(int k=0;k<=p;k++){
            for(int i=0;i<=p;i++){
                for(int j=0;j<=p;j++){
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                }
            }
        }

        vector<long long>dp(n,-1);
        for(int i=0;i<n;i++){
            if(i>0 && dp[i-1]==-1)continue;

            long long base=(i==0?0:dp[i-1]);
            if(source[i]==target[i])update(dp[i],base);

            Trie* u=root;
            Trie* v=root;
            for(int j=i;j<n;j++){
                u=u->child[source[j]-'a'];
                v=v->child[target[j]-'a'];
                if(u==NULL || v==NULL)break;

                if(u->id!=-1 && v->id!=-1 && G[u->id][v->id]!=INT_MAX/2)update(dp[j],base+G[u->id][v->id]);
            }
        }
        return dp[n-1];
    }
};

// Time Complexity : O(M*L) + O(M*M*M) + O(N*N) => O(N^3)
// Space Complexity: O(M*L*26) + O(M*M) + O(N) => O(N^2);
// Here N=source.size(), M=original.size(), L=original[i].size();