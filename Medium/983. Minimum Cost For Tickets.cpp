// Problem Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=daily-question&envId=2024-12-31

class Solution {
public:
    map<int,int>mp;
    int dfs(int i,auto &d,auto &c){
        if(i==d.size())return 0;
        if(mp.count(i))return mp[i];
        mp[i]=INT_MAX;
        int index=i;
        for(int j=0;j<3;j++){
            int canPass=j==0?1:j==1?7:30;
            while(index<d.size() && d[index]<d[i]+canPass)index++;
            mp[i]=min(mp[i],c[j]+dfs(index,d,c));
        }
        return mp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(0,days,costs);
    }
};

// Time Complexity : O(N); 
// Space Complexity: O(N);
// Since here N<=365, so we can assume that here O(N)=O(1);