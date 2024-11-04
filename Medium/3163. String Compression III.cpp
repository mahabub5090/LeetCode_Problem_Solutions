// Problem link: https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04

class Solution {
public:
    string compressedString(string word) {
        string cmp="";
        int cnt=1;
        for(int i=1;i<word.size();i++){
            if(word[i]!=word[i-1]){
                cmp+=to_string(cnt);
                cmp+=word[i-1];
                cnt=1;
            }
            else{
                if(cnt==9){
                    cmp+=to_string(cnt);
                    cmp+=word[i];
                    cnt=0;
                }
                cnt++;
            }
        }
        cmp+=to_string(cnt);
        cmp+=word[word.size()-1];
        
        return cmp;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);