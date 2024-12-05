// Problem Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05

class Solution {
public:
    bool canChange(string start, string target) {
        string s="",s2="";
        for(auto &c:start)if(c!='_')s+=c;
        for(auto &c:target)if(c!='_')s2+=c;
        if(s!=s2)return 0;
        int lc=count(start.begin(),start.end(),'L');
        int rc=count(start.begin(),start.end(),'R');
        if(lc&&rc){
            int i=start.size()-1,lastL=0,lastL2=0,firstR=0,firstR2=0;
            while(start[i]!='L')i--;
            lastL=i;
            i=0;
            while(start[i]!='R')i++;
            firstR=i;
            i=target.size()-1;
            while(target[i]!='L')i--;
            lastL2=i;
            i=0;
            while(target[i]!='R')i++;
            firstR2=i;
            if(lastL>=lastL2 && firstR<=firstR2)return 1;
            return 0;
        }
        else if(lc){
            int i=0,firstL=0,firstL2=0,lastL=0,lastL2=0;
            while(start[i]!='L')i++;
            firstL=i;
            i=0;
            while(target[i]!='L')i++;
            firstL2=i;
            i=start.size()-1;
            while(start[i]!='L')i--;
            lastL=i;
            i=target.size()-1;
            while(target[i]!='L')i--;
            lastL2=i;
            if(lastL>=lastL2 && firstL>=firstL2)return 1;
            return 0;
        }
        else if(rc){
            int i=0,firstR=0,firstR2=0,lastR=0,lastR2=0;
            while(start[i]!='R')i++;
            firstR=i;
            i=0;
            while(target[i]!='R')i++;
            firstR2=i;
            i=start.size()-1;
            while(start[i]!='R')i--;
            lastR=i;
            i=target.size()-1;
            while(target[i]!='R')i--;
            lastR2=i;
            if(firstR<=firstR2 && lastR<=lastR2)return 1;
            return 0;
        }
        return 1;
    }
};

// Time Complexity : O(8*N) => O(N);
// Space Complexity: O(1);