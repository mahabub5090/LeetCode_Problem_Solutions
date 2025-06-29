// Problem Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/?envType=daily-question&envId=2025-06-27

class Solution {
public:
    int possible(string &s,string &t,int k){
        int n=s.size(),m=t.size();
        int pos=0,cnt=0;
        for(auto &c:s){
            if(c==t[pos]){
                pos++;
                if(pos==m){
                    pos=0;
                    cnt++;
                    if(cnt==k)return 1;
                }
            }
        }
        return 0;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int>freq(26,0);
        for(auto &c:s)freq[c-'a']++;
        vector<char>candidate;
        for(int i=25;i>=0;i--){
            if(freq[i]>=k)candidate.push_back(i+'a');
        }
        queue<string>q;
        for(auto &c:candidate)q.push(string(1,c));
        string ans="";
        while(q.size()){
            string curr=q.front();q.pop();
            if(curr.size()>ans.size())ans=curr;

            for(auto &c:candidate){
                string next=curr+c;
                if(possible(s,next,k)){
                    q.push(next);
                }
            }
        }
        return ans;   
    }
};

// Time Complexity : O(N*(N\K)!);
// Space Complexity: O(N/K)!;