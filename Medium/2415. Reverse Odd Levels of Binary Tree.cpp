// Problem Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20

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
    int countLevel(auto &q){
        int cnt=0;
        while(q.size()){
            auto c=q.front();q.pop();
            cnt=c.second;
            if(c.first->left!=NULL){
                q.push({c.first->left,c.second+1});
                q.push({c.first->right,c.second+1});
            }
        }
        return cnt+1;
    }
    void bfs(auto &q,auto &store){
        while(q.size()){
            auto c=q.front();q.pop();
            store[c.second].push_back(c.first->val);
            if(c.first->left!=NULL){
                q.push({c.first->left,c.second+1});
                q.push({c.first->right,c.second+1});
            }
        }
    }
    void changeVal(auto &q,auto &store){
        int cnt=0,lastIndex=0;
        while(q.size()){
            auto c=q.front();q.pop();
            if(c.second!=lastIndex)lastIndex=c.second,cnt=0;
            vector<int>temp=store[c.second];
            c.first->val=temp[cnt++];
            if(c.first->left!=NULL){
                q.push({c.first->left,c.second+1});
                q.push({c.first->right,c.second+1});        }
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<vector<int>>store(countLevel(q));
        q.push({root,0});
        bfs(q,store);  
        q.push({root,0});
        for(int i=0;i<store.size();i++){
            if(i%2)reverse(store[i].begin(),store[i].end());
        }
        changeVal(q,store);
        return root;
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(2*N) => O(N);