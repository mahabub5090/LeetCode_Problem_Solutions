// Problem Link: https://leetcode.com/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2025-10-24

class Solution {
public:
    int nextBeautifulNumber(int n) {
        while(++n){
            string s=to_string(n);
            vector<int>vc(10,0);
            for(auto &c:s)vc[c-'0']++;

            int f=1;
            for(int i=0;i<vc.size();i++){
                if(vc[i] && vc[i]!=i){
                    f=0;
                    break;
                }
            }
            if(f)return n;
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

