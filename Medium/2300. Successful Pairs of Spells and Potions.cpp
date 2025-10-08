// Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08

class Solution {
public:
    int getAns(int c,auto &vc,long long target){
        int l=0,r=vc.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            long long mul=1ll*c*vc[mid];
            if(mul<target)l=mid+1;
            else r=mid-1;
        }
        return vc.size()-l;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(auto &c:spells){
            ans.push_back(getAns(c,potions,success));
        }
        return ans;
    }
};

// Time Complexity : O(NlogM)=> O(NlogN);
// Space Complexity: O(N) + O(M) => O(N);