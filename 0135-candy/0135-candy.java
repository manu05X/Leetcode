class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int candy = n;
        int[] temp = new int[n];
        for(int i = 0; i < n; i++){
            temp[i] = 1;
        }

        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i]){
                temp[i] = temp[i-1]+1;
            }
        }
        
        for(int i = n-2; i >= 0; i--){
             if(ratings[i] > ratings[i+1] && temp[i] <= temp[i+1]){
                temp[i] = temp[i+1]+1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            //cout << cand[i] <<" ";
            sum += temp[i];
        }
        return sum;

        
    }
}

/*
1,3,2,2,1
1,1,1,1,1
1,2,1,1,1
1,2,1,2,1

 */