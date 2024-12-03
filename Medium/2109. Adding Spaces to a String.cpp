// Problem Link: https://leetcode.com/problems/adding-spaces-to-a-string/submissions/1469272050/?envType=daily-question&envId=2024-12-03

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,j=0;
        string ans="";
        for(auto &c:s){
            if(j<spaces.size() && i==spaces[j])j++,ans+=" ";
            ans+=c;
            i++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);