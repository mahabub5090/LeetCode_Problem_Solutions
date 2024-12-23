// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/?envType=daily-question&envId=2024-12-23

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(auto &q,auto &vc){
        while(q.size()){
            auto c=q.front();q.pop();
            vc[c.second].push_back(c.first->val);
            if(c.first->left){
                q.push({c.first->left,c.second+1});
            }
            if(c.first->right){
                q.push({c.first->right,c.second+1});
            }
        }
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>vc(1e5);
        queue<pair<TreeNode*,int>>q;
        int index=0;
        q.push({root,0});
        bfs(q,vc);
        int ans=0;
        for(auto &c:vc){
            if(c.empty())break;
            vector<int>temp=c;
            sort(temp.begin(),temp.end());
            map<int,int>mp;
            for(int i=0;i<c.size();i++){
                mp[c[i]]=i;
            }
            int cnt=0;
            for(int i=0;i<c.size();i++){
                if(c[i]!=temp[i]){
                    cnt++;
                    int j=mp[temp[i]];
                    mp[c[i]]=j;
                    swap(c[i],c[j]);
                }
            }
            ans+=cnt;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);