// Problem Link: https://leetcode.com/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-10-02

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numExchange<=numBottles){
            numBottles-=numExchange;
            numExchange++;
            numBottles++;
            ans++;
        }
        return ans;
    }
};

// Time Complexity : O(sqrt(N));
// Space Complexity: O(1);
