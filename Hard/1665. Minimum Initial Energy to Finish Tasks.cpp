// Problem Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto &a,auto &b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });

        int ans=0, n=tasks.size();
        for(int i=n-1;i>=0;i--){
            ans=max(ans+tasks[i][0],tasks[i][1]);
        }
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N) => O(NlogN);
// Space Complexity: O(logN); // for internal recursion stack in sort();