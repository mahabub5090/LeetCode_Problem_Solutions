// Problem Link: https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23

class Solution {
public:
    bool isChar(char c){
        return c>='0' && c<='9';
    }
    string fractionAddition(string expression) {
        string c=expression,s="";
        bool fg=0,pre=1;
        vector<pair<int,int>>vc;
        int i=0,last;
        while(i<c.size()){
            if(c[i]=='-')pre=0;
            else if(c[i]=='+')pre=1;
            if(!isChar(c[i])){i++;continue;}
            s="";
            while(i<c.size() && isChar(c[i]))s+=c[i],i++;
            double temp=stoi(s)*(pre?1:-1);
            if(fg==0)last=temp,fg=1;
            else vc.push_back({last,temp<0?temp*-1:temp}),fg=0,last=-1;
        } 
        int d=1;
        for(auto &c:vc)d*=c.second;
        int n=0;
        for(auto &c:vc){
            n+=(c.first*(d/c.second));
        }
        if(n==0.00)return "0/1";
        int div=__gcd(abs(n),d);
        string ans="";
        ans+=to_string(n/div)+"/"+to_string(d/div);
        return ans;
    }
};

// Time Complexity : O(N)+log(min(n,d)) => O(N);
// Space Complexity: O(1);