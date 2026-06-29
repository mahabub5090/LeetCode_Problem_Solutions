// Problem Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0, n=word.size();
        for(auto &c:patterns){
            int m=c.size();
            
            for(int i=0;i<n-m+1;i++){
                int j=0;
                while(j<m){
                    if(c[j]!=word[i+j]) break;
                    j++;
                }
				if(j==m){
                    ans++;
                    break;
                }
            }
        }
		return ans;
    }
};

// Time Complexity : O(P*N*M) => O(N^3);
// Space Complexity: O(1);
// P = patterns.size(), N = word.size(), M = word[i].size();