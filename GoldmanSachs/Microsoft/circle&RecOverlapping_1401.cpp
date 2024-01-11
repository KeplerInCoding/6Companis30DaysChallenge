//medium

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        double v_x = abs(xCenter - (double) (x1 + x2) / 2) - (double) (x2 - x1) / 2;
        double v_y = abs(yCenter - (double) (y1 + y2) / 2) - (double) (y2 - y1) / 2;

        return max(0.0, v_x) * max(0.0, v_x) + max(0.0, v_y) * max(0.0, v_y) <= radius * radius;
    }
};