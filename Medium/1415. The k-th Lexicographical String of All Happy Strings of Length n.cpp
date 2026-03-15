// Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19
// Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

// class Solution {
// public:
//     void all(string s,int n,auto &happy){
//         if(s.size()==n){
//             happy.push_back(s);
//             return;
//         };
//         for(auto &c:{'a','b','c'}){
//             if(s.empty() || s.back()!=c){
//                 all(s+c,n,happy);
//             }
//         }
//     }
//     string getHappyString(int n, int k) {
//         vector<string>happy;
//         all("",n,happy);
//         if(k>happy.size())return "";
//         return happy[k-1];
//     }
// };

// // Time Complexity : O(N*(2^N));
// // Space Complexity: O(N*(2^N));

// way: 2 =>

class Solution {
public:
    string genarate(string s,int n,int &cnt,int k){
        if(s.size()==n){
            cnt++;
            if(cnt==k)return s;
            return "";
        }

        for(auto c:{'a','b','c'}){
            if(s.empty() || s.back()!=c){
                string ans=genarate(s+c,n,cnt,k);
                if(ans!="")return ans;
            }
        }
        return "";
    }

    string getHappyString(int n, int k) {
        int tt=3*(1<<(n-1));
        if(k>tt)return "";
        int cnt=0;
        return genarate("",n,cnt,k);
    }
};

// Time Complexity : O(K*N) => O(N*(2^N));
// Space Complexity: O(N);