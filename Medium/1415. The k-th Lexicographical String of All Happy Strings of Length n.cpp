// Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

class Solution {
public:
    void all(string s,int n,auto &happy){
        if(s.size()==n){
            happy.push_back(s);
            return;
        };
        for(auto &c:{'a','b','c'}){
            if(s.empty() || s.back()!=c){
                all(s+c,n,happy);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>happy;
        all("",n,happy);
        if(k>happy.size())return "";
        return happy[k-1];
    }
};

// Time Complexity : O(3^N);
// Space Complexity: O(3^N);