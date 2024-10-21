// Problem Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21

class Solution {
public:
    void backtraking(int idx,string s,auto &st,int &ans){
        int n=s.size();
        if(idx==n){
            ans=max(ans,(int)st.size());
            return;
        }
        for(int i=idx;i<n;i++){
            string cmp=s.substr(idx,i-idx+1);
            if(st.find(cmp)==st.end()){
                st.insert(cmp);
                backtraking(i+1,s,st,ans);
                st.erase(cmp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int ans=0;
        set<string>st;
        backtraking(0,s,st,ans);
        return ans;
    }
};

// Time Complexity : O(N) * O(2^N);
// Space Complexity: O(N);