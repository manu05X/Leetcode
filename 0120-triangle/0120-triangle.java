class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        for(int r = 1; r < n; r++){
            for(int c = 0; c <= r; c++){
                int smallestAbove = Integer.MAX_VALUE;

                if(c > 0){ // this cover the case of col == row
                    smallestAbove = triangle.get(r-1).get(c-1);
                }

                if(c < r){
                    smallestAbove = Math.min(smallestAbove, triangle.get(r-1).get(c));
                }

                int path = smallestAbove + triangle.get(r).get(c);

                triangle.get(r).set(c,path);
            }
        }

        int minVal = triangle.get(n-1).get(0);

        for(int i = 0; i < triangle.get(n-1).size(); i++){
            if(triangle.get(n-1).get(i) < minVal){
                minVal = triangle.get(n-1).get(i);
            }
        }

        return minVal;
    }
}