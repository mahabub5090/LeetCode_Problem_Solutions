// Problem Link: https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int n=groups.size(),m=elements.size();
            unordered_map<int,int>mp;
            for(int i=0;i<m;i++){
                if(mp.count(elements[i]))continue;
                mp[elements[i]]=i;
            }
            vector<int>ans(n,-1);
            for(int i=0;i<n;i++){
                vector<int>divisor;
                int curr=groups[i];
                for(int j=1;j*j<=curr;j++){
                    if(curr%j==0){
                        divisor.push_back(j);
                        divisor.push_back(curr/j);
                    }
                }
                ans[i]=INT_MAX;
                for(auto &c:divisor){
                    if(mp.count(c))ans[i]=min(ans[i],mp[c]);
                }
                ans[i]==INT_MAX?ans[i]=-1:ans[i]+=0;
            }
            return ans;
        }
    };
    
    // Time Complexity : O(M) + O(N*(√N)) => O(N√N);
    // Space Complexity: O(M+N) => O(N);
    // M is elements.size() here and N is gorups.size();