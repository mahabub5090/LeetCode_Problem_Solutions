// Problem Link:https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01

class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=0;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]==word[i+1])cnt++;
        }
        return cnt+1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);