// Problem Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/

class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            vector<string>vc;
            int cnt=0;string tmp="";
            for(auto &c:ans){
                if(cnt==k)vc.push_back(tmp),tmp="",cnt=0;
                cnt++;
                tmp+=c;
            }
            vc.push_back(tmp);
            vector<int>vc2;
            for(auto &c:vc){
                int sum=0;
                for(auto &cc:c)sum+=cc-'0';
                vc2.push_back(sum);
            }
            ans="";
            for(auto &c:vc2)ans+=to_string(c);
        }
        return ans;
    }
};

// Time Complexity : O(N*N*N) => O(N^3);
// Space Complexity: O(N*N) => O(N^2);