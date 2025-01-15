// Problem Link: https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        string s=bitset<32>(num1).to_string();
        int cnt=__builtin_popcount(num2);
        string ans="";
        for(auto &c:s){
            if(c=='1' && cnt)ans+='1',cnt--;
            else ans+='0';
        }
        for(int i=ans.size()-1;i>=0 && cnt;i--){
            if(ans[i]=='0')ans[i]='1',cnt--;
        }
        while(cnt--){
            ans='1'+ans;
            cout<<cnt<<" ";
        }
        return stoi(ans,NULL,2);
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);