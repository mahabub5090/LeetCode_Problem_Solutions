// Problem Link: https://leetcode.com/problems/power-grid-maintenance/description/?envType=daily-question&envId=2025-11-06

class Solution {
public:
    vector<int>parent,size;
    map<int,priority_queue<int,vector<int>,greater<int>>>mp;

    void Union(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);
        if(up==vp)return;

        if(size[up]>size[vp]){
            size[up]+=size[vp];
            parent[vp]=up;
            while(mp[vp].size()){
                mp[up].push(mp[vp].top());
                mp[vp].pop();
            }
        }
        else{
            size[vp]+=size[up];
            parent[up]=vp;
            while(mp[up].size()){
                mp[vp].push(mp[up].top());
                mp[up].pop();
            }
        }
    }
    int findParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node]);
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>ans;
        parent.resize(c);
        size.resize(c,1);
        vector<int>offLine(c,0);

        for(int i=0;i<c;i++){
            parent[i]=i;
            mp[i].push(i);
        }

        for(auto &c:connections){
            Union(--c[0],--c[1]);
        }

        for(auto &c:queries){
            if(c[0]==2){
                offLine[--c[1]]=1;
                continue;
            }

            if(offLine[--c[1]]==0){
                ans.push_back(++c[1]);
                continue;
            }

            int p=findParent(c[1]);
            while(mp[p].size() && offLine[mp[p].top()])mp[p].pop();
            if(mp[p].size())ans.push_back(mp[p].top()+1);
            else ans.push_back(-1);
        }

        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);