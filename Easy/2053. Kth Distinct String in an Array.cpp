// Problem Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp; 
        for(auto &c:arr)mp[c]++;
        int cnt=0;
        for(auto &c:arr){
            if(mp[c]==1)cnt++;
            if(cnt==k)return c;
        }
        return "";
    }
};

// Time Complexity : O(2*N) => O(N;
// Space Complexity: O(N);