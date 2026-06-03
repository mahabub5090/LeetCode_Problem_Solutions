// Problem Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03

class Solution {
public:
    int solve(auto &s,auto &t,auto &s2,auto &t2){
        int n=s.size(), m=s2.size();
        int firstRide=INT_MAX;
        for(int i=0;i<n;i++){
            firstRide=min(firstRide,s[i]+t[i]);
        }

        int secondRide=INT_MAX;
        for(int i=0;i<m;i++){
            secondRide=min(secondRide,max(firstRide,s2[i])+t2[i]);
        }
        return secondRide;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst=solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int waterFirst=solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(landFirst,waterFirst);
    }
};

// Time Complexity : O(N+M) + O(M+N) => O(N);
// Space Complexity: O(1);