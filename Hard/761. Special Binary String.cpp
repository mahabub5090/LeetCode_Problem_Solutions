// Problem Link: https://leetcode.com/problems/special-binary-string/description/?envType=daily-question&envId=2026-02-20

class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s=="")return s;
        vector<string>ans;
        int cnt=0;
        for(int i=0,j=0;i<s.size();i++){
            cnt+=(s[i]=='1'?1:-1);
            if(cnt==0){
                string temp=s.substr(j+1,i-j-1);
                ans.push_back('1'+makeLargestSpecial(temp)+'0');
                j=i+1;
            }
        }
        sort(ans.rbegin(),ans.rend());
        return accumulate(ans.begin(),ans.end(),string(""));
    }
};

// Time Complexity : O((N^2)logN);
// Space Complexity: O(N^2);