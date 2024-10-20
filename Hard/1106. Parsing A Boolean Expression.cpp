// Problem Link: https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto &c:expression){
            if(c==',' || c=='(')continue;
            if(c!=')')st.push(c);
            else{
                bool t=false,f=false;
                while(st.top()=='t' || st.top()=='f'){
                    char cc=st.top();
                    st.pop();
                    t+=(cc=='t');
                    f+=(cc=='f');

                }
                char op=st.top();st.pop();
                if(op=='!')st.push(t?'f':'t');
                else if(op=='&'){
                    st.push(f?'f':'t');
                }
                else st.push(t?'t':'f');
            }
        }
        return st.top()=='t';
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);