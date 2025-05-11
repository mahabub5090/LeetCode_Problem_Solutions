// link: https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(auto &c:arr){
            if(c%2)cnt++;
            else cnt=0;
            if(cnt==3)return 1;
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=2;i<arr.size();i++){
            if(arr[i]%2 && arr[i-1]%2 && arr[i-2]%2)return 1;
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);