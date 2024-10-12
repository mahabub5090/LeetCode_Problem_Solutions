// Problem Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start,end;
        for(auto &c:intervals){start.push_back(c[0]),end.push_back(c[1]);}
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int l=0,r=0,ans=0;
        while(l<start.size()){
            while(l<start.size() && start[l]<=end[r])l++;
            ans=max(ans,l-r);
            r++;
        }
        return ans;
    }
};

// Time Complexity : O(2*NlogN)+O(N) => O(NlogN);
// Space Complexity: O(2*N) => O(N);