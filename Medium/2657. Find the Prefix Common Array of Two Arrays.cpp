// Problem Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
// Problem Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n=A.size(),cnt=0;
//         vector<int>a(n+1,0),b(n+1,0),ans;
//         for(int i=0;i<n;i++){
//             if(b[A[i]])cnt++;
//             a[A[i]]++;
//             if(a[B[i]])cnt++;
//             b[B[i]]++;
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(N) +O(N) + O(N) => O(N);

// Way: 2 =>

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int> mp;
        vector<int> ans(n,0);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++,mp[B[i]]++;
            if(mp[A[i]]==2) cnt++;
            if(A[i]!=B[i] && mp[B[i]]==2) cnt++;
            
            ans[i]=cnt;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N) + O(N) => O(N);