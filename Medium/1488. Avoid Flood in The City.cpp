// Problem Link: https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,0);
        set<int>st;
        map<int,int>mp;

        for(int i=0;i<n;i++){
            int c=rains[i];
            if(c>0){
                ans[i]=-1;
                if(mp.count(c)){
                    if(st.empty())return {};
                    auto pos=st.upper_bound(mp[c]);
                    if(pos==st.end())return {};
                    ans[*pos]=c;
                    st.erase(pos); 
                }
                mp[c]=i;
            }
            else st.insert(i);
        }
        int val;
        for(auto &c:rains){
            if(c){
                val=c;
                break;
            }
        }
        for(auto &c:st)ans[c]=val;
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);