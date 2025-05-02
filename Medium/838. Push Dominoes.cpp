// Problem Link: https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int i=0,j=n-1;
        while(i<n && dominoes[i]=='.')i++;
        if(i<n && dominoes[i]=='L'){
            int k=i;
            while(k>=0)dominoes[k]='L',k--;
        }
        while(j>=0 && dominoes[j]=='.')j--;
        if(j>=0 && dominoes[j]=='R'){
            int k=j;
            while(k<n)dominoes[k]='R',k++;
        }
        for(;i<j;i++){
            if(dominoes[i]=='R'){
                int s=i,e=i+1;
                while(dominoes[e]=='.')e++;
                if(dominoes[e]=='L'){
                    int gap=(e-s-1);
                    int mid=gap/2;
                    while(s<i+mid+1)dominoes[s]='R',s++;
                    if(gap%2)s++;
                    while(s<e)dominoes[s]='L',s++;
                }
                else{
                    while(s<e)dominoes[s]='R',s++;
                }
                i=--e;
            }
            else{
                int s=i;
                while(s<j && dominoes[s]=='.')s++;
                if(i>0 && dominoes[i-1]=='L' && dominoes[s]=='L'){
                    s--;
                    while(s>=0 && dominoes[s]=='.')dominoes[s]='L',s--;
                }
            }
        }         
        return dominoes;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);