// Problem Link: https://leetcode.com/problems/find-closest-person/description/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:abs(x-z)<abs(y-z)?1:2;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);
