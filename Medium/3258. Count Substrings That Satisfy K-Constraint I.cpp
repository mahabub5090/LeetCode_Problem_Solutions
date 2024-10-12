// Problem Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt=0,cnt2=0,i=0,j=0,ans=0;
        while(j<s.size()){
            cnt+=s[j]=='0',cnt2+=s[j]=='1';
            while(cnt>k && cnt2>k){
                cnt-=s[i]=='0',cnt2-=s[i]=='1';
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
