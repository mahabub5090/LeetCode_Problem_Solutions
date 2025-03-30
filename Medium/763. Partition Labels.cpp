// Problem Link: https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>vc(26,0);
        for(int i=0;i<s.size();i++)vc[s[i]-'a']=i;
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,vc[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(26) => O(1);