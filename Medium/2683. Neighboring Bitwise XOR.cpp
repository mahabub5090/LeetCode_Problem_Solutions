// Problem Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int xr=0,last=0;
        for(int i=0;i<n;i++){
            last=last^derived[i];
        }
        if(0==last)return 1;
        xr=1,last=1;
        for(int i=0;i<n;i++){
            last=last^derived[i];
        }
        if(1==last)return 1;
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr=0;
        for(auto &c:derived)xr^=c;
        return xr==0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);