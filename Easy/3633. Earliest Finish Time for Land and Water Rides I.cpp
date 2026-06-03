// Problem Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/?envType=daily-question&envId=2026-06-02

// class Solution {
// public:
//     int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
//         int n=landStartTime.size(), m=waterStartTime.size();
//         int ans=INT_MAX;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 int s=landStartTime[i],t=landDuration[i];
//                 int s2=waterStartTime[j],t2=waterDuration[j];

//                 if(s+t<s2) ans=min(ans,s2+t2);
//                 if(s2+t2<s) ans=min(ans,s+t);

//                 if(s+t>=s2) ans=min(ans,s+t+t2);
//                 if(s2+t2>=s) ans=min(ans,s2+t2+t);
//             }
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N*M) => O(N^2);
// // Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    int solve(auto &s,auto &t, auto &s2,auto &t2){
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