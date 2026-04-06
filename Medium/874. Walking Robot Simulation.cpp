// Problem Link: https://leetcode.com/problems/walking-robot-simulation/description/
// Problem Link: https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06

// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         map<pair<int,int>,int>mp;
//         for(auto &c:obstacles)mp[{c[0],c[1]}]++;
    
//         int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//         int x=0,y=0,id=0;
//         int ans=0;
//         for(auto &c:commands){
//             if(c==-1)id++,id%=4;
//             else if(c==-2)id--,(id+=4)%=4;
//             else {
//                 while(c--){
//                     if(mp[{x+dir[id][0],y+dir[id][1]}])break;
//                     x+=dir[id][0],y+=dir[id][1];
//                 }
//             }
//             ans=max(ans,x*x+y*y);
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(MlogM) + O(N*(K*logM)) => O(NlogN);
// // Space Complexity: O(M) => O(N);

// Way: 2 =>

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto &c:obstacles)st.insert({c[0],c[1]});
        int x=0,y=0;
        char f='U';
        int ans=0;
        for(auto &c:commands){
            if(c==-2){
                if(f=='U')f='L';
                else if(f=='L')f='D';
                else if(f=='D')f='R';
                else f='U';
            }
            else if(c==-1){
                if(f=='U')f='R';
                else if(f=='R')f='D';
                else if(f=='D')f='L';
                else f='U';
            }
            else {
                if(f=='R'){
                    int target=x+c;
                    while(x<target && !st.count({x+1,y}))x++;
                }
                else if(f=='L'){
                    int target=x-c;
                    while(x>target && !st.count({x-1,y}))x--;
                }
                else if(f=='U'){
                    int target=y+c;
                    while(y<target && !st.count({x,y+1}))y++;
                }
                else {
                    int target=y-c;
                    while(y>target && !st.count({x,y-1}))y--;
                }
            }
            cout<<x<<" "<<y<<endl;
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};

// Time Complexity : O(MlogM) + O(N*(K*logM)) => O(NlogN);
// Space Complexity: O(M) => O(N);
// M = obstacles.size() and 1<=k<=9;
