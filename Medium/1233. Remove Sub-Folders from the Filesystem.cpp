// Problem Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        for(auto &c:folder){
            if(ans.empty() || c.find(ans.back()+'/')!=0){
                ans.push_back(c);
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);