// Problem Link: https://leetcode.com/problems/lexicographically-smallest-generated-string/description/?envType=daily-question&envId=2026-03-31

class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        string s(n+m-1,'a');
        vector<int> fixed(n+m-1,0);

        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=i;j<i+m;j++){
                    if(fixed[j] && s[j]!=str2[j-i])return "";
                    s[j]=str2[j-i];
                    fixed[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                int flag=0,idx=-1;
                for(int j=i+m-1;j>=i;j--){
                    if(str2[j-i]!=s[j])flag=1;
                    if(idx==-1 && fixed[j]==0)idx=j;
                }
                if(flag)continue;
                else if(idx!=-1)s[idx]='b';
                else return "";
            }
        }

        return s;
    }
};

// Time Complexity : O(N*M)  => O(N^2);
// Space Complexity: O(N+M) => O(N);