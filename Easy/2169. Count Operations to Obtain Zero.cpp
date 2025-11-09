// Problem Link: https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        while(num1 && num2){
            cnt+=num1/num2;
            num1%=num2;
            swap(num1,num2);
        }
        return cnt;
    }
};


// Time Complexity : O(log max(num1,num2)) => O(logN);
// Space Complexity: O(1);