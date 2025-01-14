// Problem Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),cnt=0;
        vector<int>a(n,0),b(n,0),ans;
        for(int i=0;i<n;i++){
            if(b[A[i]-1])cnt++;
            a[A[i]-1]++;
            if(a[B[i]-1])cnt++;
            b[B[i]-1]++;
            ans.push_back(cnt);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);