// Problem Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>freq(k,0);
        for(auto &c:arr){
            int rem=c%k;
            if(rem<0)rem+=k;
            freq[rem]++;
        }
        if(freq[0]%2)return 0;
        for(int i=1;i<=k/2;i++){
            if(freq[i]!=freq[k-i])return 0;
        }
        return 1;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);