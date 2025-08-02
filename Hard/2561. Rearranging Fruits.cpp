// Problem Link: https://leetcode.com/problems/rearranging-fruits/description/?envType=daily-question&envId=2025-08-02

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int mn=INT_MAX;
        for(auto &c:basket1)mp[c]++,mn=min(mn,c);
        for(auto &c:basket2)mp[c]--,mn=min(mn,c);

        vector<int>extra,extra2;
        for(auto &[val,diff]:mp){
            if(diff%2)return -1;
            if(diff>0){
                for(int i=0;i<diff/2;i++)extra.push_back(val);
            }
            else{
                diff*=-1;
                for(int i=0;i<diff/2;i++)extra2.push_back(val);
            }
        }

        sort(extra.begin(),extra.end());
        sort(extra2.rbegin(),extra2.rend());

        long long ans=0;
        mn==INT_MAX?mn/=2:mn/=1;
        for(int i=0;i<extra.size();i++){
            ans+=min({2*mn,extra[i],extra2[i]});
        }
        return ans;
    }
};
// Time Complexity : O(4*N) + O(2*NlogN) => O(NlogN);
// Space Complexity: O(3*N) => O(N);