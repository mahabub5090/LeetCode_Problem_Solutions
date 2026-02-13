// Problem Link: https://leetcode.com/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13

class Solution {
public:
    void twoChars(char x,char y,auto &s,int &ans){
        int i=0,n=s.size();
        vector<int>first(n*2+1,INT_MAX);
        vector<int>touched;
        touched.reserve(n*2+1);

        while(i<n){
            int segStart=i;
            first[n]=segStart-1;
            touched.push_back(n);

            int d=0;
            while(i<n && (s[i]==x || s[i]==y)){
                d+=(s[i]==x)?1:-1;
                int idx=d+n;
                if(first[idx]!=INT_MAX)ans=max(ans,i-first[idx]);
                else{
                    first[idx]=i;
                    touched.push_back(idx);
                }
                i++;
            }

            for(auto &idx:touched)first[idx]=INT_MAX;
            touched.clear();
            i++;
        }
        
    }


    int longestBalanced(string s) {
        int ans=0,n=s.size();

        for(int i=0;i<n;){
            int start=i;
            i++;
            while(i<n && s[i]==s[i-1])i++;
            ans=max(ans,i-start);
        }

        twoChars('a','b',s,ans);
        twoChars('a','c',s,ans);
        twoChars('b','c',s,ans);

        unordered_map<long long,int>pos;
        pos.reserve(n*2+1);

        auto key=[&](long long d,long long d2){
            return (d<<32)^d2;
        };

        int ca=0,cb=0,cc=0;
        pos[key(0,0)]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a')ca++;
            else if(s[i]=='b')cb++;
            else if(s[i]=='c')cc++;

            int d=ca-cb;
            int d2=cb-cc;
            long long k=key(d,d2);

            auto it=pos.find(k);
            if(it!=pos.end())ans=max(ans,i-it->second);
            else pos[k]=i;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);