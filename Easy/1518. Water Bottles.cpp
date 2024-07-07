// Problem Link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07

// way-1 O(logN) => 

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=0,n=numBottles,x=numExchange,c=0;
        while(n>=x){
            c=n%x;
            n/=x;
            cnt+=n;
            n+=c;
        }
        return numBottles+cnt;
    }
};

// way-2 O(1) =>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};