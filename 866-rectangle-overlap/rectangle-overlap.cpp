class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if either rectangle is just a line (area = 0)
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }

        // If one rectangle is completely on one side of the other, they don't overlap.
        // rec[0] = x1 (left), rec[1] = y1 (bottom)
        // rec[2] = x2 (right), rec[3] = y2 (top)
        
        bool isLeft = rec1[2] <= rec2[0];
        bool isRight = rec1[0] >= rec2[2];
        bool isBottom = rec1[3] <= rec2[1];
        bool isTop = rec1[1] >= rec2[3];
        
        // If it is NOT on the left, right, bottom, or top, it overlaps.
        return !(isLeft || isRight || isBottom || isTop);
    }
};