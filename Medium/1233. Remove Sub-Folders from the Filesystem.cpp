// Problem Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25
// Problem Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2025-07-19

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

// way: 2=>

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string prev=ans.back();
            string curr=folder[i];
            int j=0,flag=1;
            while(j<prev.size()){
                if(prev[j]!=curr[j]){
                    ans.push_back(curr);
                    flag=0;
                    break;
                }
                j++;
            }
            if(flag && curr[j]!='/'){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);