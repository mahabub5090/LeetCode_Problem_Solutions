// Problem Link: https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/description/?envType=daily-question&envId=2026-08-28

class Solution {
public:
    void build(auto &left, auto &mp){
        char c='a';
        while(c<='z'){
            int cnt=mp.count(c)?mp[c]:0;
            for(int i=0;i<cnt;i++) left+=c;                 
            c++;
        }
    }
    string makePalindrome(auto &left, char mid, int n){
        string ans=left;
        if(n%2) ans+=mid;
        ans+=ans;
        if(n%2) ans.pop_back();
        reverse(ans.begin()+n/2+n%2,ans.end());
        return ans;
    }


    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto &c:s) mp[c]++;

        int oddCnt=0;
        char mid;
        for(auto &[c,cnt]:mp) if(cnt%2) oddCnt++, mid=c;

        if((n%2==0 && oddCnt) || (n%2 && oddCnt!=1)) return "";

        for(auto it=mp.begin();it!=mp.end();){
            it->second/=2;
            if(it->second==0) it=mp.erase(it);
            else it++;
        }
    
        string targetLeft=target.substr(0,n/2);
        string left="";

        for(auto &c:targetLeft){
            // 1st Case: same character;
            if(mp.count(c)){
                mp[c]--;
                left+=c;
                if(mp[c]==0) mp.erase(c);
                continue;
            }

            // 2nd Case: next half has greater character.
            for(char next=c;next<='z';next++){
                if(mp.count(next)==0) continue;
                left+=next;
                mp[next]--;
                if(mp[next]==0) mp.erase(next);

                build(left,mp);
                goto constructFullString;
            }

            // 3rd Case: next half has lower character.
            char mx='a';
            vector<char> have(26,0);
            for(auto &cc:mp) mx=max(mx,cc.first), have[cc.first-'a']++;

            int len=left.size();
            while(len){
                char last=left.back();
                left.pop_back();
                mp[last]++;
                have[last-'a']++;
                mx=max(mx,last);

                if(mx>target[len-1]){
                    for(int i=target[len-1]-'a'+1;i<26;i++){
                        if(have[i]==0) continue;
                        int cc='a'+i;
                        left+=cc;
                        mp[cc]--;
                        break;
                    }
                    build(left,mp);
                    goto constructFullString;
                }
                len--;
            }

        }

        constructFullString:
        string ans=makePalindrome(left,mid,n);

        if(ans<=target){
            // 4th Case: IF, ans == target;
            next_permutation(left.begin(),left.end());
            ans=makePalindrome(left,mid,n);
        }
        return (ans>target) ? ans: "";
    }
};

// Time Complexity : O(N*26) => O(N);
// Space Complexity: O(N);