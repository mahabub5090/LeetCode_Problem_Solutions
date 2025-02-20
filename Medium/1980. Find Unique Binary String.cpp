// Problem Link: https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

class Solution {
public:
    void solve(int n,string s,auto &vc){
        if(s.size()==n){
            vc.push_back(s);
            return;
        }
        solve(n,s+'1',vc);
        solve(n,s+'0',vc);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int>mp;
        for(auto &c:nums)mp[c]++;
        vector<string>vc;
        solve(n,"",vc);
        for(auto &c:vc){
            if(mp[c]==0){
                return c;
            }
        }
        return "";
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(2^N);