// Problem Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07

class Solution {
public:
    vector<int>days;

    int find(int i){
        if(days[i]!=i)days[i]=find(days[i]);
        return days[i];
    }
    int maxEvents(vector<vector<int>>& events) {
        int mx=0;
        for(auto &c:events)mx=max(mx,c[1]);
        days.resize(mx+2);
        iota(days.begin(),days.end(),0);

        sort(events.begin(),events.end(),[](auto &c,auto &d){
            return c[1]<d[1];
        });


        int ans=0;
        for(auto &c:events){
            int availableDay=find(c[0]);

            if(availableDay<=c[1]){
                ans++;
                days[availableDay]++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N*logN) => O(NlogN);
// Space Complexity: O(N);