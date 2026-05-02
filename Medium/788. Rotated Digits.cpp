// Problem Link: https://leetcode.com/problems/rotated-digits/description/?envType=daily-question&envId=2026-05-02

class Solution {
public:
    int possible(int n){
        string s=to_string(n);
        int f=0;
        for(auto &c:s){
            if(c=='0' || c=='1' || c=='8')continue;
            if(c=='2' || c=='5' || c=='6' || c=='9'){
                f=1;
                continue;
            }
            return 0;
        }
        return f;
    }

    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)ans+=possible(i);
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);