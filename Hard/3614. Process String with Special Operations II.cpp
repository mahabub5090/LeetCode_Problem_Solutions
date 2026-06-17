// Problem Link: https://leetcode.com/problems/process-string-with-special-operations-ii/description/?envType=daily-question&envId=2026-06-17

class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(auto &c:s){
            if(c=='*') len-=(len>0);
            else if(c=='#') len*=2;
            else if(c=='%') continue;
            else len++;
        }

        if(k+1>len) return '.';

        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*') len++;
            else if(s[i]=='#'){
                if(k+1>(len+1)/2) k-=len/2;
                len=(len+1)/2;
            }
            else if(s[i]=='%') k=len-k-1;
            else{
                if(k+1==len) return s[i];
                else len--;
            }
        }
        return '.';
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(1);