// Problem Link: https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15

class Solution {
public:
    bool isValid(string word) {
        int v=0,con=0;
        for(auto &c:word){
            if(c>='A' && c<='Z')c+=32;
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')v++;
            else if(c>='a' && c<='z')con++;
            else if(c>='0' && c<='9')continue;
            else return 0;
        }
        return word.size()>=3 && v && con;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);