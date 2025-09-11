// Problem Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11

class Solution {
public:
    int isVowel(char &c){
        string s="aeiouAEIOU";
        return (s.find(c)!=string::npos);
    }
    string sortVowels(string s) {
        vector<int>vc(26,0),vc2(26,0);
        for(auto &c:s){
            if(isVowel(c)){
                if(isupper(c)){
                    vc[c-'A']++;
                }
                else vc2[c-'a']++;
                c='#';
            }
        }
        int i=0,f=1;
        while(i<26 && vc[i]==0)i++;
        if(i==26){
            f=0;
            i=0;
            while(i<26 && vc2[i]==0)i++;
        }
        for(auto &c:s){
            if(c=='#'){
                if(f){
                    c='A'+i;
                    vc[i]--;
                    while(i<26 && vc[i]==0)i++;
                }
                else{
                    c='a'+i;
                    vc2[i]--;
                    while(i<26 && vc2[i]==0)i++;
                }    
                if(i==26){
                    f=0;
                    i=0;
                    while(i<26 && vc2[i]==0)i++;
                }
            }
        }
        return s;
    }
};

// Time Complexity : O(26*N) => O(N);
// Space Complexity: O(2*26) => O(1);