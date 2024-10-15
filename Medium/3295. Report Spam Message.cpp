// Problem Link: https://leetcode.com/problems/report-spam-message/description/

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int>mp;for(auto &c:bannedWords)mp[c]++;
        int cnt=0;
        for(auto &c:message){
            if(mp[c])cnt++;
        }
        return cnt>=2;
    }
};

// TIme Complexity : O(2*N) => O(N);
// Space Complexity: O(N);