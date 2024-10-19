// Problem Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19

// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         string s="0",cmp="";
//         for(int i=1;i<n;i++){
//             cmp=s;
//             s=cmp+"1";
//             reverse(cmp.begin(),cmp.end());
//             for(auto &c:cmp)s+=(c=='1')?'0':'1';
//         }
//         return s[k-1];
//     }
// };

// Time Complexity : O(2^N); 
// Space Complexity: O(2^N);

// Way-2 =>

class Solution {
public:
    char solve(int tt,int k){
        if(tt==1)return '0';
        if(tt/2>=k)return solve(tt/2,k);
        else if((tt/2)+1<k){
            char res=solve(tt/2,tt-k+1);
            return res=='1'?'0':'1';
        }
        return '1';
    }
    char findKthBit(int n, int k) {
        if(n==1)return '0';
        int tt=pow(2,n)-1;       
        return solve(tt,k);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);