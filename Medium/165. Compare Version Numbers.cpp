// Problem Link: https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n=version1.size(),m=version2.size();
        while(i<n && j<m){
            string s="",s2="";
            while(i<n && version1[i]!='.')s+=version1[i++];
            while(j<m && version2[j]!='.')s2+=version2[j++];
            cout<<s<<" "<<s2<<endl;
            i++,j++;
            if(stoi(s)==stoi(s2))continue;
            if(stoi(s)<stoi(s2))return -1;
            return 1;
        }
        if(i>=n){
            int cnt=0;
            while(j<m)cnt+=(version2[j]!='.' && version2[j]!='0'),j++;
            if(cnt)return -1;
            else return 0;
        }
        if(j>=m){
            int cnt=0;
            while(i<n)cnt+=(version1[i]!='.' && version1[i]!='0'),i++;
            if(cnt)return 1;
            else return 0;
        }
        return 0;
    }
};

// Time Complexity : O(N+M) => O(N);
// Space Complexity: O(1);