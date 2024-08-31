// Problem Link: https://leetcode.com/problems/path-with-maximum-probability/submissions/1370115033/?envType=daily-question&envId=2024-08-27

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>prob(n,0);
        prob[start_node]=1;
        for(int i=0;i<n;i++){
            int j=0,fg=0;
            for(auto &c:edges){
                int u=c[0],v=c[1];
                if(prob[u]<prob[v]*succProb[j])fg=1;
                if(prob[v]<prob[u]*succProb[j])fg=1;
                prob[u]=max(prob[u],prob[v]*succProb[j]);
                prob[v]=max(prob[v],prob[u]*succProb[j]);
                j++;
            }
            if(fg==0)break;
        }
        return prob[end_node];
    }
};

// Time Complexity : O(N*E) => O(N^2);
// Space Complexity: O(N);
// N=nodes, E=edges;