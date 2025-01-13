// Problem Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        map<char,int>l,r;
        for(auto &c:s)r[c]++;
        int cnt=0;
        for(auto &c:s){
            if(l[c] && r[c]-1>0){
                int mn=min(l[c],r[c]-1);
                cnt+=mn*2;
                l[c]-=mn;
                r[c]-=mn;
            }
            l[c]++,r[c]--;
        }
        return n-cnt;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);