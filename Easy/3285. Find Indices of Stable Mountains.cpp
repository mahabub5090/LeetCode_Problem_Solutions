// Problem Link: https://leetcode.com/problems/find-indices-of-stable-mountains/submissions/1390188409/

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>vc;
        for(int i=1;i<height.size();i++){
            if(height[i-1]>threshold)vc.push_back(i);
        }
        return vc;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);