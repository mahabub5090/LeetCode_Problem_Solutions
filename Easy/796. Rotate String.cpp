// Problem Link: https://leetcode.com/problems/rotate-string/submissions/1441648636/?envType=daily-question&envId=2024-11-03

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         queue<char>q,q2;
//         for(int i=s.size()-1;i>=0;i--)
//             q.push(s[i]);
//         for(int i=goal.size()-1;i>=0;i--)
//             q2.push(goal[i]);
//         for(int i=0;i<s.size();i++){
//             if(q==q2)return 1;
//             q2.push(q2.front());
//             q2.pop();
//         }
//         return 0;
//     }
// };

// Time Complexity : O(2*N) + O(N*N) => O(N^2);
// Space Complexity: O(2*N) => O(N);

// Way: 2 =>

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return 0;
        return (s+s).find(goal)!=string::npos;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1)