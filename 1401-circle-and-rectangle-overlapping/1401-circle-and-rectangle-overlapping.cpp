class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long closestX = max((long long)x1, min((long long)xCenter, (long long)x2));
        long long closestY = max((long long)y1, min((long long)yCenter, (long long)y2));
        long long dx = closestX - xCenter;
        long long dy = closestY - yCenter;
        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};