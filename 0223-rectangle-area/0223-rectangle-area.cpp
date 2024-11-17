class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int totalArea = 0;
        int areaOverlap = 0;

        // calculate x overlap
        int startPoint = max(ax1, bx1); // max of start/left point
        int endPoint = min(ax2, bx2); // min end/right point

        int xOverlap = endPoint - startPoint;

        // calculate y overlap
        int bottomPoint = max(ay1, by1); // max of start/bottom point
        int topPoint = min(ay2, by2); // min end/top point

        int yOverlap = topPoint - bottomPoint;

        if(xOverlap > 0 && yOverlap > 0){
            areaOverlap = xOverlap * yOverlap;
        }

        // l =min(abs(ax2), abs(bx2)) - min(abs(ax1), abs(bx1));
        // b =min(abs(ay2), abs(by2)) - min(abs(ay1), abs(by1));

        // overlapArea = l*b;
        // cout<< "overlapArea : "<<overlapArea;

        int lengthA = abs(ax2 - ax1);
        int widthA = abs(ay2 - ay1);
        int areaA = lengthA * widthA;

        int lengthB = abs(bx2 - bx1);
        int widthB = abs(by2 - by1);
        int areaB = lengthB * widthB;

        // if(overlapArea != 0)
        // {
        //     totalArea = areaA + areaB - overlapArea;
        // } else {
        //     if((ax1 == bx1) && (ax2 == bx2) && (ay1 == by1) && (ay2 == by2))
        //     {
        //         totalArea = areaA;
        //     }
        //     else{
        //         totalArea = areaA + areaB;
        //     }
        // }

        totalArea = areaA + areaB - areaOverlap;

        return totalArea;
    }
};

/*
// wrong approch
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int totalArea = 0;
        int overlapArea = 0;

        int l = 0;
        int b = 0;

        l =min(abs(ax2), abs(bx2)) - min(abs(ax1), abs(bx1));
        b =min(abs(ay2), abs(by2)) - min(abs(ay1), abs(by1));

        overlapArea = l*b;
        cout<< "overlapArea : "<<overlapArea;

        int lengthA = abs(ax2 - ax1);
        int widthA = abs(ay2 - ay1);
        int areaA = lengthA * widthA;

        int lengthB = abs(bx2 - bx1);
        int widthB = abs(by2 - by1);
        int areaB = lengthB * widthB;

        if(overlapArea != 0)
        {
            totalArea = areaA + areaB - overlapArea;
        } else {
            if((ax1 == bx1) && (ax2 == bx2) && (ay1 == by1) && (ay2 == by2))
            {
                totalArea = areaA;
            }
            else{
                totalArea = areaA + areaB;
            }
        }

        return totalArea;
    }
};


*/
