// Problem Link: https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1])return 0;
        }
        return sentence[0]==sentence[sentence.size()-1];
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1); 