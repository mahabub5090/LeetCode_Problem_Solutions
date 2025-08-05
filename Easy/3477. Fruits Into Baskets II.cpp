// Problem Link: https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        for(auto &c:fruits){
            int flag=1;
            for(auto &cc:baskets){
                if(cc>=c){
                    cc=0;
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);
