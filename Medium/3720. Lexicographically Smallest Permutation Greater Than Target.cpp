// Problem Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/?envType=daily-question&envId=2026-08-27

class Solution {
public:
    string build(auto &ans, auto &mp){
        char c='a';
        while(c<='z'){
            int cnt=mp.count(c)?mp[c]:0;
            for(int i=0;i<cnt;i++) ans+=c;                 
            c++;
        }
        return ans;
    }

    string lexGreaterPermutation(string s, string target) {
        unordered_map<char,int> mp;
        for(auto &c:s) mp[c]++;

        string ans=move(s);
        ans="";

        build(ans,mp);
        reverse(ans.begin(),ans.end());
        if(ans<=target) return "";

        ans="";
        for(auto &c:target){
            // 1st Case: same character;
            if(mp.count(c)){
                mp[c]--;
                ans+=c;
                if(mp[c]==0) mp.erase(c);
                continue;
            }
            
            // 2nd Case: next half has greater character.
            for(char next=c;next<='z';next++){
                if(mp.count(next)==0) continue;
                ans+=next;
                mp[next]--;
                if(mp[next]==0) mp.erase(next);

                return build(ans,mp);
            }

            // 3rd Case: next half has lower character.
            char mx='a';
            vector<char> have(26,0);
            for(auto &cc:mp) mx=max(mx,cc.first), have[cc.first-'a']++;

            int len=ans.size();
            while(len){
                char last=ans.back();
                ans.pop_back();
                mp[last]++;
                have[last-'a']++;
                mx=max(mx,last);

                if(mx>target[len-1]){
                    for(int i=target[len-1]-'a'+1;i<26;i++){
                        if(have[i]==0) continue;
                        int cc='a'+i;
                        ans+=cc;
                        mp[cc]--;
                        break;
                    }
                    return build(ans,mp);
                }
                len--;
            }
        }
        // 4th Case: ans == target;
        next_permutation(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(N) + O(N) + O((25*N) + (N+25+N)) + O(N) => O(N);
// Space Complexity: O(26) + O(26) => O(1);