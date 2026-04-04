// Problem Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/description/?envType=daily-question&envId=2026-04-04

// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         int len=encodedText.size();
//         int n=rows,m=len/n;
//         vector encodedMat(n,vector<char>(m));
//         int idx=0;
//         for(auto &c:encodedMat){
//             for(auto &cc:c)cc=encodedText[idx++];
//         }

//         string ans="";
//         for(int cnt=0;cnt<max(n,m);cnt++){
//             int i=0,j=cnt;
//             while(i<n && j<m){
//                 ans+=encodedMat[i][j];
//                 i++,j++;
//             }
//         }
//         while(ans.size() && ans.back()==' ')ans.pop_back();
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(N) + O(N)=> O(N);
// // Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len=encodedText.size();
        int n=rows,m=len/n;

        string ans="";
        for(int cnt=0;cnt<max(n,m);cnt++){
            int i=0,j=cnt;
            while(i<n && j<m){
                ans+=encodedText[(i*m)+j];
                i++,j++;
            }
        }
        while(ans.size() && ans.back()==' ')ans.pop_back();
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(1);