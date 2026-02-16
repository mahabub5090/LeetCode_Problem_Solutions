// Problem Link: https://leetcode.com/problems/add-binary/description/?envType=daily-question&envId=2026-02-15

class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int carry=0;
        while(i>=0 && j>=0){
            int sum=(a[i]=='1')+(b[j]=='1')+carry;
            ans+='0'+(sum%2);
            carry=sum>1;
            i--,j--;
        }
        while(i>=0){
            int sum=(a[i]=='1')+carry;
            ans+='0'+(sum%2);
            carry=sum>1;
            i--;
        }
        while(j>=0){
            int sum=(b[j]=='1')+carry;
            ans+='0'+(sum%2);
            carry=sum>1;
            j--;
        }
        if(carry)ans+='0'+carry;

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(max(i,j)) => O(N);
// Space Complexity: O(max(i,j)) => O(N);
// here i=a.size()-1,b=b.size()-1;