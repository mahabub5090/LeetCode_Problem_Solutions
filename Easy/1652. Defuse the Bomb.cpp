// Problem Link: https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>vc;
        for(auto &c:code)vc.push_back(c);
        for(auto &c:code)vc.push_back(c);
        for(auto &c:code)vc.push_back(c);
        vector<int>pref(vc.size(),0);
        vector<int>ans;
        for(int i=0;i<vc.size();i++){
            pref[i]=(i==0?0:pref[i-1])+vc[i];
        }
        if(k==0)for(auto &c:code)ans.push_back(0);
        else if(k>0){
            for(int i=code.size();i<code.size()*2;i++){
                ans.push_back(pref[i+k]-pref[i]);
            }
        }
        else{
            for(int i=code.size();i<code.size()*2;i++){
                ans.push_back(pref[i-1]-pref[i-1+k]);
            }
        }
        return ans;
    }
};

// Time Complexity : O(3*N)+O(3*N)+O(N) => O(N);
// Space Complexity: O(3*N) => O(N);