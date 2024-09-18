// Problem Link: https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vc;
        for(auto &c:nums)vc.push_back(to_string(c));
        sort(vc.begin(),vc.end(),[](auto &a,auto b){
            return a+b>b+a;
        });
        string ans="";
        bool ok=0;
        for(auto &c:vc){
            ans+=c;
            if(c!="0")ok=1;
        }
        return ok?ans:"0";
    }
};

// Time Complexity : O(2*N+NlogN) => O(NlogN);
// Space Complexity: O(N);