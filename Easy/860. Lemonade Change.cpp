// Problem Link: https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0;
        for(auto &c:bills){
            if(c==5)f++;
            else if(c==10)f--,t++;
            else{
                if(t)t--,f--;
                else f-=3;
            }

            if(f<0 || t<0)return 0;
        }
        return true;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);