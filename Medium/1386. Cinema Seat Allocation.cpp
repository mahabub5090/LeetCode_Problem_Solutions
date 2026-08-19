// Problem Link: https://leetcode.com/problems/cinema-seat-allocation/description/?envType=daily-question&envId=2026-08-19

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto &c:reservedSeats){
            mp[c[0]].insert(c[1]);
        }

        int ans=0;
        for(auto &[c,st]:mp){
            vector<int> seats(11,0);
            for(auto &seat:st) seats[seat]++;
            for(int i=1;i<11;i++) seats[i]+=seats[i-1];
            

            if(seats[5]-seats[1]==0 && seats[9]-seats[5]==0) ans+=2;
            else if(seats[5]-seats[1]==0 || seats[7]-seats[3]==0 || seats[9]-seats[5]==0) ans++;
        }

        ans+=(n-mp.size())*2;
        return ans;
    }
};

// Time Complexity : O(R) + O(R*(10+10)) => O(R);
// Space Complexity: O(R*10) + O(10) => O(R);
// R = reservedSeats.size();