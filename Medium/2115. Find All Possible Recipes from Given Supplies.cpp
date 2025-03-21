// Problem Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

class Solution {
public:
    map<string,int>memo;
    bool possible(string c,auto &mp,auto &have,auto &vis){
        if(memo.count(c))return memo[c];
        if(vis[c])return 0;
        vis[c]++;
        int cnt=0;
        for(auto &cc:mp[c]){
            if(mp.count(cc)){
                if(possible(cc,mp,have,vis))cnt++;;
            }
            else if(have[cc])cnt++;
        }
        if(cnt==mp[c].size())return memo[c]=1;
        return memo[c]=0;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int>have;
        for(auto &c:supplies)have[c]++;
        map<string,vector<string>>mp;
        int n=recipes.size();
        for(int i=0;i<n;i++)mp[recipes[i]]=ingredients[i];
        vector<string>ans;
        for(auto &c:recipes){
            int cnt=0;
            for(auto &cc:mp[c]){
                map<string,int>vis;
                if(mp.count(cc)){
                    if(possible(cc,mp,have,vis))cnt++;
                }
                else if(have[cc])cnt++;
            }
            if(cnt==mp[c].size())ans.push_back(c);
        }
        return ans;
    }
};

// Time Complexity : O(R*R+S) => O(N^2);
// Space Complexity: O(R+I+S) => O(N);
// R is recipes.size(), s is supplies.size() and I is ingredients.size();