// Problem Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

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