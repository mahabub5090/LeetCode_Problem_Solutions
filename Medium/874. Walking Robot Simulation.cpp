// Problem Link: https://leetcode.com/problems/walking-robot-simulation/description/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,int>mp;
        for(auto &c:obstacles)mp[{c[0],c[1]}]++;
    
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,id=0;
        int ans=0;
        for(auto &c:commands){
            if(c==-1)id++,id%=4;
            else if(c==-2)id--,(id+=4)%=4;
            else {
                while(c--){
                    if(mp[{x+dir[id][0],y+dir[id][1]}])break;
                    x+=dir[id][0],y+=dir[id][1];
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};

// Time Complexity : O(N+M) => O(N;
// Space Complexity: O(M) => O(N);