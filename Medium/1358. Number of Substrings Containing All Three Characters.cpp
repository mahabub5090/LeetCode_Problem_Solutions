// Problem Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int i=0,j=0,n=s.size();
        int ans=0;
        while(j<n){
            if(s[j]=='a')a++;
            if(s[j]=='b')b++;
            if(s[j]=='c')c++;
            j++;
            while(a && b && c && i<n){
                ans+=n-j+1;
                if(s[i]=='a')a--;
                if(s[i]=='b')b--;
                if(s[i]=='c')c--;
                i++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);