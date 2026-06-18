// Problem Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int degreeForHours=360/12;
        int degreeForMinute=360/(12*5);
        double hourMoveForMinute=1.0*degreeForHours/60;

        double hourDegree=(hour*degreeForHours)+(minutes*hourMoveForMinute);
        double minuteDegree=minutes*degreeForMinute;

        double angle=abs(hourDegree-minuteDegree);
        return min(angle,360-angle);
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);