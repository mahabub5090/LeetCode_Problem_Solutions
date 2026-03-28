// Problem Link: https://leetcode.com/problems/find-the-string-with-lcp/description/?envType=daily-question&envId=2026-03-28

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string word(n,'\0');
        char curr='a';

        for(int i=0;i<n;i++){
            if(word[i]=='\0'){
                if(curr>'z')return "";
                word[i]=curr;

                for(int j=i+1;j<n;j++){
                    if(lcp[i][j]>0)word[j]=word[i];
                }
                curr++;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word[i]!=word[j]){
                    if(lcp[i][j])return "";
                    // else continue;
                }
                else if(i==n-1 || j==n-1){
                    if(lcp[i][j]!=1)return "";
                    // else continue;
                }
                else if(lcp[i][j]!=lcp[i+1][j+1]+1)return ""; 
            }
        }

        return word;
    }
};

// Time Complexity : O(N^2) + O(N^2) => O(N^2);
// Space Complexity: O(1);