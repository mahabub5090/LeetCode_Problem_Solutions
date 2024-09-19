// Problem Link: https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19

class Solution {
public:
    int op(char c,int x,int y){
        if(c=='+')return x+y;
        if(c=='-')return x-y;
        return x*y;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        for(int i=0;i<expression.size();i++){
            char c=expression[i];
            if(c=='+'||c=='-'||c=='*'){
                auto a=diffWaysToCompute(expression.substr(0,i));
                auto b=diffWaysToCompute(expression.substr(i+1,expression.size()));
                
                for(auto &c2:a){
                    for(auto &c3:b)ans.push_back(op(c,c2,c3));
                }

            }
        }
        if(ans.empty())return {stoi(expression)};
        return ans;
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(2^N);