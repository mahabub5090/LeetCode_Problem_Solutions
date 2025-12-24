// Problem Link: https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tt=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int sum=0,cnt=0;
        for(auto &c:capacity){
            sum+=c;
            cnt++;
            if(sum>=tt)return cnt;
        }
        return 1;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);