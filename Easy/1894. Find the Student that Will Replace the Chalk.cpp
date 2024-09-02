// Problem Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0; for(auto &c:chalk)sum+=c;
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            if(k<chalk[i]) return i;
            else k-=chalk[i];
        }
        return 0;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);