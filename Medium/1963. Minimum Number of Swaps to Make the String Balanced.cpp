// Problem Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08

class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto &c:s){
            if(st.empty())st.push(c);
            else{
                if(st.top()==
                '[' && c==']')st.pop();
                else st.push(c);
            }
        }
        return (int)st.size()/4+((int)st.size()%4!=0);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);