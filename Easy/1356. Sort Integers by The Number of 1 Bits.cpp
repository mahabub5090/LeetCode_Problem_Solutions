// Problem Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2026-02-25

class Solution {
public:
    int cnt(int n){
        return __builtin_popcount(n);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(cnt(a)==cnt(b))return a<b;
            return cnt(a)<cnt(b);
        });
        return arr;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);