// Problem Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/?envType=daily-question&envId=2024-11-20

class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        for(auto &cc:s)a+=(cc=='a'),b+=(cc=='b'),c+=(cc=='c');
        if(a<k || b<k ||c<k)return -1;
        int i=0,j=0,cnt=0,n=s.size();
        while(true){
            while(a>=k && b>=k && c>=k && j<n){
                a-=s[j]=='a';
                b-=s[j]=='b';
                c-=s[j]=='c';
                j++;
                if(a>=k && b>=k && c>=k)cnt=max(cnt,j-i);
            }
            cout<<j<<" ";
            while((a<k || b<k || c<k) && i<n){
                 a+=s[i]=='a';
                 b+=s[i]=='b';
                 c+=s[i]=='c';
                 i++;
            }
            if(i==n || j==n)break;
        }
        return n-cnt;
    }
};

// Time Complexity : O(N);
// Space Complxeity: O(1);