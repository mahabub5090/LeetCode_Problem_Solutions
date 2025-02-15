// Problem Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15

class Solution {
public:
    int possible(string s,int target){
        if(s=="" && target==0)return 1;
        if(target<0)return 0;

        for(int i=0;i<s.size();i++){
            string l=s.substr(0,i+1);
            string r=s.substr(i+1);
            if(possible(r,target-stoi(l)))return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int pw=pow(i,2);
            if(possible(to_string(pw),i))ans+=pw;
        }   
        return ans;
    }
};

// Time Complexity : O(N) * O(2^(log10 N)) => O(2^(logN));
// Space Complexity: O(logN);