// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>pref(n,{0,0}),suff(n,{0,0});
        for(int i=0;i<n;i++)if(boxes[i]=='1'){
            pref[i]={i,1};
            suff[i]={i,1};
        }
        for(int i=1;i<n;i++){
            pref[i].first+=pref[i-1].first;
            pref[i].second+=pref[i-1].second;
        }
        for(int i=n-2;i>=0;i--){
            suff[i].first+=suff[i+1].first;
            suff[i].second+=suff[i+1].second;
        }
        for(int i=0;i<n;i++){
            int tt=0;
            if(i)tt+=(i*pref[i-1].second)-pref[i-1].first;
            if(i!=n-1)tt+=suff[i].first-(i*suff[i].second);
            ans[i]=tt;
        }
        return ans;
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(3*N) => O(N);
