// Problem Link: https://leetcode.com/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                int a=__builtin_popcount(i);
                int b=__builtin_popcount(j);
                if(a<5 && b<7 && a+b==turnedOn){
                    string time=to_string(i);
                    time+=':';
                    if(j<10)time+='0';
                    time+=to_string(j);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);