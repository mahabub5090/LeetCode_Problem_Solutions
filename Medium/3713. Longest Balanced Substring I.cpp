// Problem Link: https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

class Solution {
public:
    int longestBalanced(string s) {
        int ans=0,n=s.size();
        vector<int>cnt(26,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                char ch=s[j]-'a';
                cnt[ch]++;
                int f=1;
                for(auto &c:cnt){
                    if(c && c!=cnt[ch]){
                        f=0;
                        break;
                    }
                }
                if(f)ans=max(ans,j+1-i);
            }
            for(auto &c:cnt)c=0;;
        }
        return ans;
    }
};

// Time Complexity : O(N*N*26) => O(N^2);
// Space Complexity: O(26) => O(1);