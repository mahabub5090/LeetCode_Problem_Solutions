// Problem Link: https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/1388767268/?envType=daily-question&envId=2024-09-13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<arr.size();i++)arr[i]^=arr[i-1];
        vector<int>ans;
        for(auto &c:queries){
            int all=arr[c[1]],dlt=c[0]?arr[c[0]-1]:0;
            ans.push_back(all^dlt);
        }
        return ans;
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space complexity: O(N);

