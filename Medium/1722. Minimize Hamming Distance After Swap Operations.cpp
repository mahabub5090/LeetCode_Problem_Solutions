// Problem Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/?envType=daily-question&envId=2026-04-21

class Solution {
public:
    vector<int>parent,rank;
    int find(int c){
        if(parent[c]!=c)parent[c]=find(parent[c]);
        return parent[c];
    }
    void Union(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;

        if(rank[a]<rank[b])swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b])rank[a]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)parent[i]=i;
        for(auto &c:allowedSwaps)Union(c[0],c[1]);

        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<n;i++){
            int p=find(i);
            mp[p][source[i]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int p=find(i);
            if(mp[p][target[i]]!=0)mp[p][target[i]]--;
            else ans++;
        }
        return ans;
    }
};

// Time Complexity : O(3*N) + O(M) + O(2*N) => O(N);
// Space Complexity: O(3*N) => O(N);
// M = allowedSwaps.size();