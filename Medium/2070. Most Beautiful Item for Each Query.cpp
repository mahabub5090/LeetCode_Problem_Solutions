// Problem Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/submissions/1450072622/?envType=daily-question&envId=2024-11-12

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>>vc;
        for(auto &c:items){
            vc.push_back({c[0],c[1]});
        }
        sort(vc.begin(),vc.end());
        for(int i=1;i<vc.size();i++){
            vc[i].second=max(vc[i].second,vc[i-1].second);
        }
        vector<int>ans;
        for(auto &c:queries){
            auto lb=upper_bound(vc.begin(),vc.end(),make_pair(c+1,0))-1;
            if(lb>=vc.begin()&&lb->first<=c){
                ans.push_back(lb->second);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) + O(NlogN) + O(MlogN) => O(NlogN + MlogN);
// Space Complexity: O(N+M); // M is the number of queries;