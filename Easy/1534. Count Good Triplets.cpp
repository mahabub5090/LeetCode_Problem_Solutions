// Problem Link: https://leetcode.com/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int  n=arr.size(),cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c)cnt++;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(1);