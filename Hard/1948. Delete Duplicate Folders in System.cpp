// Problem Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/description/?envType=daily-question&envId=2025-07-20

class Trie{
    public:
    string serial;
    unordered_map<string,Trie*>children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root= new Trie();

        for(auto path:paths){
            Trie* curr=root;
            for(auto &node:path){
                if(curr->children.count(node)==0)curr->children[node]=new Trie();
                curr=curr->children[node];
            }
        }

        unordered_map<string,int>freq;

        function<void(Trie*)>construct=[&](Trie* node){
            if(node->children.empty())return;

            vector<string>vc;
            for(auto &[folder,child]:node->children){
                construct(child);
                vc.push_back(folder+"("+child->serial+")");
            }

            sort(vc.begin(),vc.end());
            for(auto &s:vc){
                node->serial+=move(s);
            }
            freq[node->serial]++;
    };

    construct(root);

    vector<vector<string>>ans;
    vector<string>path;

    function<void(Trie*)>dfs=[&](Trie* node){
        if(freq[node->serial]>1)return;

        if(path.empty()==0){
            ans.push_back(path);
        }
        for(auto &[folder,child]:node->children){
            path.push_back(folder);
            dfs(child);
            path.pop_back();
        }
    };
    dfs(root);
    return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);