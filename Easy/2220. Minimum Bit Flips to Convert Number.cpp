// Problem Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11

class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32>s(start),g(goal);
        string a=s.to_string(),b=g.to_string();
        int i=a.size()-1,j=b.size()-1;
        int cnt=0;
        while(i>0){
            if(a[i]!=b[j])cnt++;
            i--,j--;
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);