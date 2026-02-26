// Problem Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()!=1){
            if(s.back()=='1'){
                int i=s.size()-1;
                while(i>=0){
                    if(s[i]=='1')s[i]='0';
                    else{
                        s[i]='1';
                        break;
                    }
                    i--;
                }
                if(i==-1)s='1'+s;
            }
            else s.pop_back();
            ans++;
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);