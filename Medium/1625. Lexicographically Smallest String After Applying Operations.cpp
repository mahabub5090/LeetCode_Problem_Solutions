// Problem Link: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19

class Solution {
public:
    void add(string &s2,int start,string &s,int a){
        int minVal=10,times=0;

        for(int i=0;i<10;i++){
            int added=((s2[start]-'0')+(i*a))%10;
            if(added<minVal){
                minVal=added;
                times=i;
            }
        }

        for(int i=start;i<s2.size();i+=2){
            s2[i]='0'+((s2[i]-'0')+(times*a))%10;
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        string ans=s;
        s+=s;
        int gcd=__gcd(b,n);

        for(int i=0;i<n;i+=gcd){
            string s2=s.substr(i,n);
            add(s2,1,s,a);
            if(b%2)add(s2,0,s,a);
            ans=min(ans,s2);
        }
        return ans;
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(2*N) => O(N);