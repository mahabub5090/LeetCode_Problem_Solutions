// Problem Link: https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>pos;
        for(int i=0;i<positions.size();i++)pos.push_back({positions[i],i});
        sort(pos.begin(),pos.end());
        stack<pair<char,pair<int,int>>>st;
        for(auto &c:pos){
            int idx=c.second;
            if(st.empty())st.push({directions[idx],{idx,healths[idx]}});
            else{
                bool isc=0;
                while(st.size() && st.top().first=='R' && directions[idx]=='L'){
                    if(healths[idx]==st.top().second.second){st.pop();isc=1;break;}
                    else if(st.top().second.second>healths[idx]){
                        st.top().second.second--;isc=1;break;  
                    }
                    else st.pop();healths[idx]--;
                }
                if(isc)continue;
                st.push({directions[idx],{idx,healths[idx]}});
                
            }
        }
        vector<pair<int,int>> ans;
        while(st.size())ans.push_back(st.top().second),st.pop();
        reverse(ans.begin(),ans.end());
        sort(ans.begin(),ans.end());
        vector<int>mainAns;
        for(auto &c:ans)mainAns.push_back(c.second);
        return mainAns;
    }
};

// Time Complexity : O(2*NlogN + 2*N) => O(NlogN);
// Space Complexity: O(4*N) => O(N);