// Problem Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22

class Solution {
public:
    void rotate(auto &vc){
        int n=vc.size();
        for(int i=0;i<n;i++){                       // O(N^2);
            for(int j=i+1;j<n;j++){
                swap(vc[i][j],vc[j][i]);
            }
        }
        for(auto &c:vc)reverse(c.begin(),c.end());  // O(N^2);
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)return 1;        // O(N^2);
        for(int i=1;i<4;i++){           // O(3);
            rotate(mat);                // O((N^2)+(N^2));
            if(mat==target)return 1;    // O(N^2);
        }
        return 0;
    }
};

// Time Complexity : 4*(N^2) + 3*O((N^2)+(N^2)) => 10*O(N^2) => O(N^2);
// Space Complexity: O(1);