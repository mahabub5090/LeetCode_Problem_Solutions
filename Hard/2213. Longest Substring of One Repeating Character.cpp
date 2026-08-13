// Problem Link: https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/?envType=daily-question&envId=2026-08-13

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        set<pair<int,int>> segments;
        multiset<int> lens;

        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;
            segments.insert({i,j-1});
            lens.insert(j-i);
            i=j;
        }

        int k=queryIndices.size();
        vector<int> ans;

        for(int i=0;i<queryIndices.size();i++){
            int index=queryIndices[i];
            char c=queryCharacters[i];

            if(s[index]==c){
                ans.push_back(*lens.rbegin());
                continue;
            }

            auto it=segments.upper_bound({index,INT_MAX});
            it--;

            int l=it->first, r=it->second;
            segments.erase(it);
            lens.erase(lens.find(r-l+1));

            if(l<=index-1){
                segments.insert({l,index-1});
                lens.insert(index-l);
            }
            if(index+1<=r){
                segments.insert({index+1,r});
                lens.insert(r-index);
            }

            int nl=index, nr=index;
            auto leftIt=segments.lower_bound({index,0});
            auto rightIt=segments.lower_bound({index+1,0});

            if(leftIt!=segments.begin()){
                leftIt--;
                if(leftIt->second==index-1 && s[index-1]==c){
                    int len=leftIt->second - leftIt->first + 1;
                    lens.erase(lens.find(len));

                    nl=leftIt->first;
                    segments.erase(leftIt);
                }
            }

            if(rightIt!=segments.end() && rightIt->first==index+1 && s[index+1]==c){
                int len=rightIt->second - rightIt->first+1;
                lens.erase(lens.find(len));

                nr=rightIt->second;
                segments.erase(rightIt);
            }

            segments.insert({nl,nr});
            lens.insert(nr-nl+1);
            s[index]=c;
            
            ans.push_back(*lens.rbegin());
        }
        return ans;
    }
};

// Time Complexity : O(N * logN) + O(K * logN) => O((N+K)logN);
// Space Complexity: O(N) + O(N) + O(K) => O(N+k);