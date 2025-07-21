// Problem Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/
// Problem Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21

class Solution {
public:
    string makeFancyString(string s) {
        string fancy="";int cnt=0;char cc=' ';
        for(auto &c:s){
            if(c!=cc){
                cnt=1;
                cc=c;
                fancy+=c;
            }
            else{
                cnt++;
                if(cnt<=2){
                    fancy+=c;
                }
            }
        }
        return fancy;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        for(auto &c:s){
            if(ans.size()>=2 && c==ans.back() && c==ans[ans.size()-2])continue;
            else ans+=c;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);