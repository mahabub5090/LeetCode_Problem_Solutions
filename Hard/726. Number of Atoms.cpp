// Problem Link: https://leetcode.com/problems/number-of-atoms/description/?envType=daily-question&envId=2024-07-14

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int>st;
        map<string,int>mp;
        int cnt=0,mul=1;

        string c; char curr;bool num;
        for(int i=formula.size()-1;i>=0;i--){
            c="";c+=formula[i];
            curr=formula[i];
            num=0;

            if(isdigit(curr)){
                while(isdigit(formula[i-1]))c+=formula[--i];
                num=1;
            }

            if(islower(curr)){
                while(islower(formula[i-1]))c+=formula[--i];
                c+=formula[--i];
            }

            reverse(c.begin(),c.end());

            if(num && formula[i-1]==')'){mul*=stoi(c),st.push(stoi(c)),i--;continue;}
            if(num){cnt+=stoi(c);continue;}

            if(curr==')'){st.push(1);continue;}
            if(curr=='('){mul/=st.top(),st.pop();continue;}

            mp[c]+=max(1,cnt?cnt*mul:mul);
            cnt=0;
        }

        string ans="";
        for(auto &c:mp){
            ans+=c.first;
            c.second>1?ans+=to_string(c.second):ans+="";
        }
        return ans;
    }
};

// Time Complexity : O(2*N + N log M) => O(N log N); // M is the unique elements added in map;
// Space Complexity: O(2*N) => O(N);