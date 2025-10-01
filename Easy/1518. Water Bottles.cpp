// Problem Link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
// Probelm Link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01

// way-1 O(logN) => 

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            ans+=numBottles/numExchange;
            numBottles=numExchange+numBottles%numExchange;
        }
        return ans;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);

// way-2 O(1) =>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1); // (numBottles-1) for handle some failed cases,like numBottles=4 & numExchange=3;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);