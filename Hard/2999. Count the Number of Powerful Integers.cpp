// Problem Link: https://leetcode.com/problems/count-the-number-of-powerful-integers/description/?envType=daily-question&envId=2025-04-10

class Solution {
public:
    long long calculate(string x,string s,int limit){
        if(x.size()<s.size())return 0;
        if(x.size()==s.size())return x>=s?1:0;

        string suff=x.substr(x.size()-s.size(),s.size());
        long long cnt=0;
        int pl=x.size()-s.size();
        for(int i=0;i<pl;i++){
            if(limit<(x[i]-'0')){
                cnt+=(long long)pow(limit+1,pl-i);
                return cnt;
            }  
            cnt+=(long long)(x[i]-'0')*pow(limit+1,pl-1-i);
        }

        if(suff>=s)cnt++;
        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st=to_string(start-1),f=to_string(finish);
        return calculate(f,s,limit)-calculate(st,s,limit);
    }
};

// Time Complexity : O(log(finish)) => O(logN);
// Space Complexity: O(log(finish)) => O(logN);