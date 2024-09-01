// Problem Link: https://leetcode.com/problems/find-the-key-of-the-numbers/

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<string>str;
        str.push_back(to_string(num1));
        str.push_back(to_string(num2));
        str.push_back(to_string(num3));
        for(auto &cc:str){
            for(int i=cc.size();i<4;i++)cc='0'+cc;
        };
        string ans="";
        for(int i=0;i<4;i++){
            ans+=min({str[0][i],str[1][i],str[2][i]});
        }
        return stoi(ans);
    }
};

// TIme Complexity : O(N);
// Space Complexity: O(1);