// Problem Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2024-07-12

class Solution {
public:
    int maximumGain(string s, int x, int y) {
       stack<char>st; long long cnt=0;
        string s1,s2;
        if(x>=y)s1="ab",s2="ba";
        else s1="ba",s2="ab";

        for(auto &c:s){
            if(st.empty())st.push(c);
            else{
                if(st.top()==s1[0] && c==s1[1])cnt+=max(x,y),st.pop();
                else st.push(c);
            }
        }

        s="";
        while(st.size())s+=st.top(),st.pop();
        reverse(s.begin(),s.end());

         for(auto &c:s){
            if(st.empty())st.push(c);
            else{
                if(st.top()==s2[0] && c==s2[1])cnt+=min(x,y),st.pop();
                else st.push(c);
            }
        }

        return cnt;
    }
};

// Time Complexity: O(3*N);
// Space Complexity: O(2*N+1);




