// Problem Link: https://leetcode.com/problems/walking-robot-simulation-ii/description/?envType=daily-question&envId=2026-04-07

class Robot {
public:
    vector<vector<int>>axis;
    vector<int>dir;
    int pos=0,flag=0;

    Robot(int width, int height) {
        for(int i=0;i<width;i++){
            axis.push_back({i,0});
            dir.push_back(0);
        }
        for(int i=1;i<height;i++){
            axis.push_back({width-1,i});
            dir.push_back(1);
        }
        for(int i=width-2;i>=0;i--){
            axis.push_back({i,height-1});
            dir.push_back(2);
        }
        for(int i=height-2;i>0;i--){
            axis.push_back({0,i});
            dir.push_back(3);
        }
        dir[0]=3;
    }
    
    void step(int num) {
        flag++;
        pos=(pos+num)%axis.size();
    }
    
    vector<int> getPos() {
        return axis[pos];
    }
    
    string getDir() {
        if(flag==0)return "East";
        return dir[pos]==0?"East":(dir[pos]==1?"North":(dir[pos]==2?"West":"South"));
    }
};

// Time Complexity : O(width+height)+ O(QueryCount) => O(N);
// Space Complexity: O(width+height) => O(N);

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */