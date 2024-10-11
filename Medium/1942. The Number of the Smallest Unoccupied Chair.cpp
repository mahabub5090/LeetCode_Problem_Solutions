// Problem Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int store=times[targetFriend][0];
        sort(times.begin(),times.end());
        set<pair<int,int>>tc;
        set<int>chair;
        for(int i=0;i<times.size();i++){
            while(tc.size() && tc.begin()->first<=times[i][0]){
                chair.insert(tc.begin()->second);
                tc.erase(tc.begin());
            }
            chair.insert(i);
            if(times[i][0]==store)return *chair.begin();
            tc.insert({times[i][1],*chair.begin()});
            chair.erase(*chair.begin());
        }
        return -1;
    }
};

// Time Conplexity : O(NlogN)+O(2*N+NlogN) => O(NlogN);
// Space Complexity: O(2*N) => O(N);