// Problem Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=daily-question&envId=2024-10-13

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vc;
        for(int i=0;i<n;i++){
            for(auto &c:nums[i])vc.push_back({c,i});
        }
        sort(vc.begin(),vc.end());
        vector<int>flag(n,0);
        int cnt=0;
        int i=0,j=0;
        pair<int,pair<int,int>>ans={INT_MAX,{0,0}};
        while(j<vc.size()){
            while(cnt!=n && j<vc.size()){
                if(flag[vc[j].second]==0)cnt++;
                flag[vc[j].second]++;
                j++;
            }
            while(cnt==n){
                if(ans.first>vc[j-1].first-vc[i].first){
                    ans.first=vc[j-1].first-vc[i].first;
                    ans.second={vc[i].first,vc[j-1].first};
                }
                flag[vc[i].second]--;
                if(flag[vc[i].second]==0)cnt--;
                i++;
            }
        }
        return {ans.second.first,ans.second.second};
    }
};

// Time Complexity : O(2*N) + O(NlogN) => O(NlogN);
// Space Complexity: O(2*N) => O(N);