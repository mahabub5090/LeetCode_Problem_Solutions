// Problem Link: https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(auto &c:words){
            for(auto &cc:words){
                if(c==cc)continue;
                if(cc.find(c)!=cc.npos){
                    ans.push_back(c);
                    break;
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^2)*(L^2)) => O(N^4);
// Space Complexity: O(N);
// L is the size of words[i].length here;