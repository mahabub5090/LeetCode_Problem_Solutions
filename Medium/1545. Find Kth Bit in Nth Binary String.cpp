// Problem Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19

class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0",cmp="";
        for(int i=1;i<n;i++){
            cmp=s;
            s=cmp+"1";
            reverse(cmp.begin(),cmp.end());
            for(auto &c:cmp)s+=(c=='1')?'0':'1';
        }
        return s[k-1];
    }
};

// Time Complexity : O(2^N); 
// Space Complexity: O(2^N);
