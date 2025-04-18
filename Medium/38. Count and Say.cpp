// Problem Link: https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

// class Solution {
// public:
//     void solve(int n,string &s){
//         if(n==1)return;
//         solve(n-1,s);
//         string cmp=s;
//         s="";
//         int i=0,m=cmp.size();
//         for(int i=0;i<m;i++){
//             int cnt=0;
//             while(i+cnt+1<m && cmp[i+cnt]==cmp[i+cnt+1])cnt++;
//             s+=to_string(cnt+1);
//             s+=cmp[i];
//             i+=cnt;
//         }
//     }
//     string countAndSay(int n) {
//         string s="1";
//         solve(n,s);
//         return s;
//     }
// };

// // Time Complexity : O(N^2);
// // Space Complexity: O(N);

// way: 2 =>

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int it=1;it<n;it++){
            string cmp=s;
            s="";
            int i=0,m=cmp.size();
            for(int i=0;i<m;i++){
                int cnt=0;
                while(i+cnt+1<m && cmp[i+cnt]==cmp[i+cnt+1])cnt++;
                s+=to_string(cnt+1);
                s+=cmp[i];
                i+=cnt;
            }
        }
        return s;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);