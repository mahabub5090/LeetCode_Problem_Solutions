// Problem Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0;
        int i=0,j=0,n=players.size(),m=trainers.size();
        while(i<n && j<m){
            if(players[i]<=trainers[j])cnt++,i++,j++;
            else j++;
        }
        return cnt;
    }
};

// Time Complexity : O(NlogN) + O(MlogM) + O(min(N,M)) => O(NlogN);
// Space Complexity: O(1);