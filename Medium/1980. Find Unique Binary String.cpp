// Problem Link: https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20
// Problem Link: https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

cclass Solution {
public:
    vector<string>vc;
    void solve(string s,int n){
        if(s.size()==n){
            vc.push_back(s);
            return;
        }
        solve(s+'0',n);
        solve(s+'1',n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto &c:nums)st.insert(c);
        solve("",nums.size());
        for(auto &c:vc)if(st.count(c)==0)return c;
        return "";
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(2^N);