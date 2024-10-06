// Problem Link: https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string s1=sentence1,s2=sentence2;
        int n=s1.size(),m=s2.size();
        if(n<m)swap(s1,s2),swap(n,m);
        vector<string>vc,vc2;
        stringstream ss(s1),ss2(s2);
        while(ss>>s1)vc.push_back(s1);
        while(ss2>>s2)vc2.push_back(s2);

        int i=0,j=vc2.size(),k=vc.size();
        if(j==0){
            if(vc2[0]==vc[0] || vc2[0]==vc[k-1])return 1;
            return 0;
        }

        while(i<j && vc[i]==vc2[i])i++;
        while(j>0 && vc2[j-1]==vc[k---1])j--;
        
        if(j>i)return 0;
        return 1;
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(2*N) => O(N);