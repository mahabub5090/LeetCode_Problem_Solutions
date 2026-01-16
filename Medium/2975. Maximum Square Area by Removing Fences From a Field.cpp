// Problem Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/?envType=daily-question&envId=2026-01-16

class Solution {
public:
    unordered_set<int> getEdges(auto &fences,int limit){
        unordered_set<int>st;
        fences.push_back(1);
        fences.push_back(limit);
        sort(fences.begin(),fences.end());

        for(int i=0;i<fences.size();i++){
            for(int j=i+1;j<fences.size();j++){
                st.insert(fences[j]-fences[i]);
            }
        }
        return st;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges=getEdges(hFences,m);
        auto vEdges=getEdges(vFences,n);

        long long ans=0,mod=1e9+7;
        for(auto &c:hEdges){
            if(vEdges.count(c))ans=max((int)ans,c);
        }
        if(ans==0)return -1;
        return (ans*ans)%mod;
    }
};

// Time Complexity : O(M*M) + O(N*N) => O(N^2);
// Space Complexity: O(M*M) + O(N*N) => O(N^2);