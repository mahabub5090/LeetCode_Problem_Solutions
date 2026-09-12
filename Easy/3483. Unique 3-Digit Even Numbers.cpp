// Problem Link: https://leetcode.com/problems/unique-3-digit-even-numbers/description/?envType=daily-question&envId=2026-09-11

// // class Solution {
// // public:
// //     int totalNumbers(vector<int>& digits) {
// //         int n=digits.size();
// //         unordered_set<int> st;

// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<n;j++){
// //                 if(i==j) continue;
// //                 for(int k=0;k<n;k++){
// //                     if(i==k || j==k) continue;

// //                     int num=digits[i]*100 + digits[j]*10 + digits[k];

// //                     if(num>=100 && num%2==0 && st.count(num)==0){
// //                         st.insert(num);
// //                     }
// //                 }
// //             }
// //         }
// //         return st.size();
// //     }
// // };

// // // Time Complexity : O(N*N*N) => O(N^3);
// // // Space Complexity: O(900) => O(1);


// // Way: 2 =>

// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         unordered_map<int,int> mp;
//         for(auto &c:digits) mp[c]++;

//         int ans=0;
//         for(int i=100;i<=998;i+=2){
//             unordered_map<int,int> temp;
//             temp[i/100]++;
//             temp[(i%100)/10]++;
//             temp[i%10]++;
            
//             int f=1;
//             for(auto &[c,cnt]:temp){
//                 if(mp[c]<cnt) {
//                     f=0;
//                     break;
//                 }
//             }

//             if(f) ans++;
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(450*3) => O(N);
// // Space Complexity: O(10) => O(1);


// Way : 3 => 

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(auto &c:digits) mp[c]++;

        int ans=0;
        for(int i=1;i<10;i++){
            if(mp[i]==0) continue;
            mp[i]--;

            for(int j=0;j<10;j++){
                if(mp[j]==0) continue;
                mp[j]--;

                for(int k=0;k<10;k+=2){
                    if(mp[k]>0) ans++;
                }

                mp[j]++;
            }

            mp[i]++;
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(9*10*5) => O(N);
// Space Complexity: O(10) => O(1);