// Problem Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int>mp;
        for(auto &c:arr1){
            string s=to_string(c);
            string cmp="";
            for(int i=0;i<s.size();i++){
                cmp+=s[i];
                mp[cmp]++;
            }
        }
        int cnt=0;
        for(auto &c:arr2){
            string s=to_string(c);
            string cmp="";
            for(int i=0;i<s.size();i++){
                cmp+=s[i];
                if(mp[cmp])cnt=max(cnt,i+1);
            }
        }
        return cnt;
    }
};

// Time Complexity : O(8*N);
// Space Complexity: O(8*N);