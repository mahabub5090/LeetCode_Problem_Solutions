// Problem Link: https://leetcode.com/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size(),ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[fruits[j]]=j;
            j++;
            while(mp.size()>2){
                i=n;
                int type=-1;
                for(auto &[val,index]:mp){
                    if(index<i)i=index,type=val;
                }
                mp.erase(type);
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);