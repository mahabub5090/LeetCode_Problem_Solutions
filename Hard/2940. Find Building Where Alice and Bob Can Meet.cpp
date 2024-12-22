// Problem Link:https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/?envType=daily-question&envId=2024-12-22

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),-1);

        map<int,vector<pair<int,int>>>mp;
        int index=0;
        for(auto &c:queries){
            int maxIndex=max(c[0],c[1]);
            int maxHeight=max(heights[c[0]],heights[c[1]]);
            if(c[0]==c[1] || (c[0]<c[1] && heights[c[0]]<heights[c[1]])){
                ans[index]=c[1];
                index++;
                continue;
            }
            if(c[0]>c[1] && heights[c[0]]>heights[c[1]]){
                ans[index]=c[0];
                index++;
                continue;
            }
            mp[maxIndex].push_back({maxHeight,index++});
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        
        index=0;
        for(auto &c:heights){
            for(auto &cc:mp[index]){
                pq.push({cc});
            }
            while(pq.size() && pq.top().first<c){
                ans[pq.top().second]=index;
                pq.pop();
            }
            index++;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);