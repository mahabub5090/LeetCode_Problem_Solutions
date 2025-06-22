// Problem Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        for(int i=0;i<s.size();i+=k){
            string c="";
            for(int j=0;j<k;j++){
                if(i+j<s.size())c+=s[i+j];
                else c+=fill;
            }
            ans.push_back(c);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);