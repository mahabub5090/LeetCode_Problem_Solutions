// Problem Link: https://leetcode.com/problems/maximum-swap/submissions/1425043691/?envType=daily-question&envId=2024-10-17

class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num),cmp=s;
        sort(cmp.begin(),cmp.end(),greater<char>());
        int j=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==cmp[i])j=i;
            else break;
        }
        if(j+1==s.size())return num;
        char c=s[j+1];
        for(int i=j+1;i<s.size();i++){
            c=max(c,s[i]);
        }
        int j2=s.size()-1;
        while(j2>j){
            if(s[j2]==c){swap(s[j+1],s[j2]);break;}
            else j2--;
        }
        return stoi(s);
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);
