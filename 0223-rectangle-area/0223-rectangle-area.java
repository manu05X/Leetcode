class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
         // calculate x overlap
        int leftPoint = Math.max(ax1, bx1); // max of start/left point
        int rightPoint = Math.min(ax2, bx2); // min end/right point
        int xOverlap = rightPoint - leftPoint;

        // calculate y overlap
        int bottomPoint = Math.max(ay1, by1); // max of end/bottom point
        int topPoint = Math.min(ay2, by2); // min of start/top point
        int yOverlap = topPoint - bottomPoint;

        int areaOverlap = 0;
        // if the rectangles overlap each other, then calculate the area of the overlap
        if(xOverlap > 0 && yOverlap > 0){
            areaOverlap = xOverlap * yOverlap;
        }

        int areaA = (ay2 - ay1) * (ax2 - ax1);
        int areaB = (by2 - by1) * (bx2 - bx1);

        int totalArea = areaA + areaB - areaOverlap;

        return totalArea;
    }
}