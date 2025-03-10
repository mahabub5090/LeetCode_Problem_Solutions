// Problem Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10

class Solution {
public:
    int isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long atLeastK(auto &word,int k){
        map<char,int>mp;
        int cc=0;
        int l=0,r=0,n=word.size();
        long long ans=0;
        while(r<n){
            if(isVowel(word[r]))mp[word[r]]++;
            else cc++;
            while(mp.size()==5 && cc>=k){
                ans+=n-r;
                if(isVowel(word[l])){
                    mp[word[l]]--;
                    if(mp[word[l]]==0)mp.erase(word[l]);
                }
                else cc--;
                l++;
            }
            r++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k)-atLeastK(word,k+1);
    }
};

// Time Complexity : O(2*N) * log(5) => O(N);
// Space Complexity: O(5) => O(1);