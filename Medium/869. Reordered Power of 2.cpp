// Problem Link: https://leetcode.com/problems/reordered-power-of-2/description/?envType=daily-question&envId=2025-08-10

// class Solution {
// public:
//     int check(string s){
//         int n=stoi(s);
//         return (n&(n-1))==0;
//     }
//     bool reorderedPowerOf2(int n) {
//         string s=to_string(n);
//         sort(s.begin(), s.end());
//         if(s[0]!='0' && check(s))return 1;
//         while(next_permutation(s.begin(),s.end())){
//             if(s[0]=='0')continue;
//             if(check(s))return 1;
//         }
//         return 0;
//     }
// };

// // Time Complexity : O(KlogK + K*K!) => O(K*K!);
// // Space Complexity: O(1);
// // Here K is less than or equal 10;

// Way: 2 =>

class Solution {
public:
    int check(string s){
        int n=stoi(s);
        return (n&(n-1))==0;
    }
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(), s.end());
        for(int i=0;i<32;i++){
            int powOfTwo=1<<i;
            string t=to_string(powOfTwo);
            sort(t.begin(),t.end());
            if(s==t)return 1;
        }
        return 0;
    }
};

// Time Complexity : O(KlogK + 32*(KlogK)) => O(1);
// Space Complexity: O(1);
// Here K is less than or equal 10;


