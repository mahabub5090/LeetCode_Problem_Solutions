// Problem Link: https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/?envType=daily-question&envId=2026-02-27

class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.size(),m=0;
        vector<int>dist(n+1,INT_MAX);
        vector<set<int>>nodeSt(2);

        for(int i=0;i<=n;i++){
            nodeSt[i%2].insert(i);
            if(i<n && s[i]=='0')m++;
        }

        queue<int>q;
        q.push(m);
        dist[m]=0;
        nodeSt[m%2].erase(m);

        while(q.size()){
            m=q.front();q.pop();
            int c=max(k-n+m,0),c2=min(m,k);
            int lnode=m+k-2*c2,rnode=m+k-2*c;
            auto &node=nodeSt[lnode%2];

            for(auto it=node.lower_bound(lnode);it!=node.end() && *it<=rnode;){
                int m2=*it;
                dist[m2]=dist[m]+1;
                q.push(m2);
                
                it=next(it);
                node.erase(m2);
            }
        }
        return dist[0]==INT_MAX?-1:dist[0];
    }
};

// Time Complexity : O(N) + O(NlogN) => O(NlogN);
// Space Complexity: O(N+N+N) => O(N);