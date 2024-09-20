// Problem Link: https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i=0,j=n-1;
        while(j>=0) {
            if (s[i]== s[j])i++;
            j--;
        }
        
        string ex=s.substr(i); 
        
        if(ex.empty()) return s; 

        string rev=ex;
        reverse(rev.begin(), rev.end());
        
        return rev+shortestPalindrome(s.substr(0,i))+ex;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);