// Problem Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto &c:letters){
            if(c>target)return c;
        }
        return letters[0];
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);