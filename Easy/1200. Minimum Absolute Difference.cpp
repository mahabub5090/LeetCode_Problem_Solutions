// Problem Link: https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        vector<pair<int,vector<int>>>vc;
        for(int i=0;i<n-1;i++)vc.push_back({abs(arr[i]-arr[i+1]),{arr[i],arr[i+1]}});
        sort(vc.begin(),vc.end());

        vector<vector<int>>ans;
        int less=vc[0].first,i=0;
        
        while(i<vc.size() && vc[i].first==less){
            ans.push_back(vc[i].second);
            i++;
        }
        return ans;
    }
};

// Time Complexity : O(2*NlogN) => O(NlogN);
// Space Complexity: O(2*N) => O(N);