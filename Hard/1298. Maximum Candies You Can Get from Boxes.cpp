// Problem Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<int>hasBox(n),used(n);
        queue<int>q;
        int ans=0;

        for(auto &b:initialBoxes){
            hasBox[b]=1;
            if(status[b]){
                q.push(b);
                used[b]=1;
                ans+=candies[b];
            }
        }

        while(q.size()){
            int c=q.front();q.pop();
            for(auto &k:keys[c]){
                status[k]=1;
                if(used[k]==0 && hasBox[k]){
                    q.push(k);
                    used[k]=1;
                    ans+=candies[k];
                }
            }
            for(auto &b:containedBoxes[c]){
                hasBox[b]=1;
                if(used[b]==0 && status[b]){
                    q.push(b);
                    used[b]++;
                    ans+=candies[b];
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);