// Problem Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, j=0, cnt=0, smallLen=INT_MAX, n=s.size();

        string ans=s;
        while(j<n){
            cnt+=s[j++]=='1';

            while(cnt==k){
                smallLen=min(smallLen,j-i);

                string temp=s.substr(i,j-i);
                if(temp.size()<ans.size()) ans=temp;
                else if(temp.size()==ans.size()) ans=min(ans,temp);

                cnt-=s[i++]=='1';
            } 
        }
        return smallLen==INT_MAX?"":ans;
    }
};

// Time Complexity : O(N * N) => O(N^2);
// Space Complexity: O(N);