class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length;
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            // Total number of subarrays that include arr[i]
            int totalSubarrays = (i + 1) * (n - i);

            // Only odd-length subarrays count
            int oddSubarrays = (totalSubarrays + 1) / 2;

            // Contribution of arr[i] to the total sum
            totalSum += arr[i] * oddSubarrays;
        }

        return totalSum;
    }
}


// class Solution {
//     public int sumOddLengthSubarrays(int[] arr) {
//         int n = arr.length;
//         if(n ==1){
//             return arr[0];
//         }

//          int oddSum = arr[0];

//         for(int i = 1; i < n; i++){
//             oddSum += arr[i];
//             arr[i] += arr[i-1];
//         }
//         if(n == 2){
//             return oddSum;
//         }

//         if(n == 3){
//             oddSum += arr[n-1];
//             return oddSum;
//         }
//          oddSum += arr[n-1];

//         int l = 0;
//         for(int i = 2; i < n; i++){
//             if(i != 2){
//                 arr[i] -= arr[l];
//                 l++;
//             }
//             oddSum += arr[i];
            
//         }

//         return oddSum;
//     }
// }

/*

[1,4,2,5,3]

[1,5,7,12,15]

15+7

*/