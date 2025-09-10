// Problem Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/description/?envType=daily-question&envId=2025-09-10

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>person;
        for(auto &c:friendships){
            unordered_set<int>exit;
            for(auto &cc:languages[c[0]-1])exit.insert(cc);
            for(auto &cc:languages[c[1]-1]){
                if(exit.count(cc)){
                    exit.clear();
                    break;
                }
            }
            if(exit.size()==0)continue;
            person.insert(c[0]);
            person.insert(c[1]);
        }
        vector<int>cnt(n+1);
        for(auto &c:person){
            for(auto &cc:languages[c-1])cnt[cc]++;
        }
        int ans=person.size(),m=ans;
        for(auto &c:cnt)ans=min(ans,m-c);
        return ans;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M+N) => O(N);
// Here M is languages.size();