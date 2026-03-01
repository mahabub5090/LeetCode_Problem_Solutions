// Problem Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end())-'0';
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);