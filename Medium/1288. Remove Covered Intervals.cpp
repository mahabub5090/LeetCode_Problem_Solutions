// Problem Link: https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06

// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
//             if(a[0]==b[0]) return a[1]>b[1];
//             return a[0]<b[0];
//         });

//         stack<pair<int,int>> st;
//         for(auto &c:intervals){
//             int a=c[0],b=c[1];

//             if(st.empty()){
//                 st.push({a,b});
//             }
//             else{
//                 auto [a2,b2]=st.top();
//                 if(a2<=a && b2>=b) continue;
//                 st.push({a,b});
//             }
//         }
//         return st.size();
//     }
// };

// // Time Complexity : O(NlogN) + O(N) => O(NlogN);
// // Space Complexity: O(logN) + O(N) => O(N);


// Way: 2 =>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        int cnt=1, currL=intervals[0][0],currR=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int a=intervals[i][0], b=intervals[i][1];

            if(currL<=a && currR>=b) continue;
            cnt++;
            currL=a;
            currR=b;
        }
        return cnt;
    }
};

// Time Complexity : O(NlogN) + O(N) => O(NlogN);
// Space Complexity: O(logN);