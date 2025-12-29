// Problem Link: https://leetcode.com/problems/pyramid-transition-matrix/description/?envType=daily-question&envId=2025-12-29

class Solution {
public:
    int T[7][7];
    unordered_map<string,int>memo;

    int solve(string curr,string next){
        if(curr.size()==1)return 1;
        if(next.size()==curr.size()-1)return solve(next,"");

        string key=curr+"@"+next;
        if(memo.count(key))return memo[key];

        int i=next.size();
        int mask=T[curr[i]-'A'][curr[i+1]-'A'];

        for(int bit=0;bit<7;bit++){
            if((mask>>bit)&1){
                if(solve(curr,next+(char)('A'+bit)))return memo[key]=1;
            }
        }
        return memo[key]=0;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto &c:allowed){
            T[c[0]-'A'][c[1]-'A'] |= (1<<(c[2]-'A'));
        }
        return solve(bottom,"");
    }
};

// Time Complexity : O((N^2) * (8^N));
// Space Complexity: O(N * (8^N));
// here: N <= 6;