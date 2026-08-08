// Problem Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<int> last(m,-1);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
        }

        vector<int> ans;
        int used=0;
        j=0;

        for(int i=0;i<n;i++){
            if(j==m) break;
            if(word1[i]==word2[j] || (used==0 && (j==m-1 || i<last[j+1]))){
                used+=(word1[i]!=word2[j]);
                ans.push_back(i);
                j++;
            }
        }
        return j==m?ans:vector<int>();
    }
};

// Time Complexity : O(N) + O(N+M) => O(N);
// Space Complexity: O(M) + O(M) => O(M);
// M < N;