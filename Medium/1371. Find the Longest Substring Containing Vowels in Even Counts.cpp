// Problem Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution {
public:
    int isv(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int findTheLongestSubstring(string s) {
        map<int,int>mp;
        mp[0]=-1;
        int cnt=0,ans=0;

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isv(c))cnt^=(1<<((int)(c-'a')));
            if(mp.count(cnt))ans=max(ans,i-mp[cnt]);
            else mp[cnt]=i;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);