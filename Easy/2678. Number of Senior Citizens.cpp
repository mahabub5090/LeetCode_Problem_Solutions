// Problem Link: https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto &s:details){
            if(s[11]>='6'){
                if(s[11]=='6' && s[12]=='0')continue;
                else cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);