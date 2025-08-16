//  Problem Link: https://leetcode.com/problems/maximum-69-number/description/?envType=daily-question&envId=2025-08-16

class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(auto &c:s){
            if(c=='6'){
                c='9';
                break;
            }
        }
        return stoi(s);
    }
};

// Time Complexity : O(maximam number of digits in num)=> O(5) => O(1);
// Space Complexity: O(1);