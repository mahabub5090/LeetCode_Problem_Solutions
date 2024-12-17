// Problem Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/?envType=daily-question&envId=2024-12-17

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans="";
        priority_queue<pair<char,int>>pq;
        vector<int>charCount(26);
        for(auto &c:s)charCount[c-'a']++;
        for(int i=0;i<26;i++)if(charCount[i])pq.push({'a'+i,charCount[i]});
        while(pq.size()){
            auto c=pq.top();pq.pop();
            if(c.second<=repeatLimit){
                ans.append(c.second,c.first);
            }
            else{
                ans.append(repeatLimit,c.first);
                if(pq.size()){
                    auto c2=pq.top();pq.pop();
                    ans+=c2.first;
                    if(c2.second>1)pq.push({c2.first,c2.second-1});
                    pq.push({c.first,c.second-repeatLimit});
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);