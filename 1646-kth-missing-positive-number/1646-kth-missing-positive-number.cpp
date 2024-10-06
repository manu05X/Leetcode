class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        int l = 0;
        int r = n-1;

        // Binary search to find the lowest index such that the number of
        // positive integers missing before arr[index] is at least k.
        while(l <= r){
            int mid = l + (r-l)/2;// Prevents potential overflow.
            int missing = arr[mid]-(mid+1); //This tells us how many positive integers are missing before arr[mid].
            // If the number of missing numbers up to arr[mid] is at least k,
            // we need to search on the left side (including mid).
            if(missing >= k){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return l + k;
    }
};

/*

Key Ideas:
1 > Finding Missing Numbers:

- The array arr is sorted and contains distinct integers. However, not all positive integers are present in this array.
- For example, if arr = [2, 3, 4, 7, 11], some of the missing positive integers are 1, 5, 6, 8, 9, 10,....
- The task is to find the k-th missing positive integer.

2> Tracking Missing Numbers:
- For each element in arr, we can compute how many positive integers are missing up to that element by comparing the index of the element and its actual value.

- If there were no missing numbers, the element at index i would be i + 1. For example, at index 0, we expect 1, at index 1, we expect 2, and so on.

- The difference between the value of the element arr[mid] and the expected value (mid + 1) gives the count of how many numbers are missing up to that point.
        missing = arr[mid] - (mid + 1)
- This tells us how many positive integers are missing before arr[mid].

3> Binary Search Approach:
- Instead of scanning through the entire array, which would take O(n) time, we use binary search to quickly find the position where the k-th missing positive integer lies.
- We are trying to find the first position in the array where the number of missing integers up to that position is greater than or equal to k.

4> Binary Search Logic:

    - We initialize two pointers l and r:
        l = 0 (left pointer at the beginning of the array).
        r = n - 1 (right pointer at the end of the array).
    - Then, we repeatedly calculate the middle index mid and determine how many positive integers are missing up to arr[mid]:
    int missing = arr[mid] - (mid + 1);
- Based on the value of missing:
    - If missing >= k, it means the k-th missing integer is either at mid or to the left of it, so we move the right pointer r = mid - 1.
    - If missing < k, it means there aren't enough missing integers up to mid, so we move the left pointer l = mid + 1.
- This process continues until we narrow down the position where the k-th missing number is.

5> Return the k-th Missing Integer:

- Once the binary search finishes, the left pointer l gives us the position where the k-th missing integer occurs.
- The formula l + k is used to calculate the k-th missing positive integer:
    - l tells us how many elements from the original array arr have been "skipped" by the missing numbers.
    - k is the number of missing integers we need to find.
- Adding them together gives the k-th missing number.



__________________
arr = [2, 3, 4, 7, 11], k = 5

Let’s walk through the example using only numbers with arr = [2, 3, 4, 7, 11] and k = 5.

Initial Setup:
l = 0 (left pointer)
r = 4 (right pointer)
n = 5 (size of the array)


1. First Iteration:
    - mid = (l + r) / 2 = (0 + 4) / 2 = 2
    - arr[mid] = arr[2] = 4
    - Calculate the number of missing integers up to arr[mid]:
        arr[mid] - (mid + 1) = 4 - (2 + 1) = 4 - 3 = 1
        So, there is 1 missing number up to arr[2].
    - Since missing = 1 is less than k = 5, we move l = mid + 1 = 3.

2. Second Iteration:
    - mid = (l + r) / 2 = (3 + 4) / 2 = 3
    - arr[mid] = arr[3] = 7
    - Calculate the number of missing integers up to arr[mid]:
            arr[mid] - (mid + 1) = 7 - (3 + 1) = 3
        So, there are 3 missing numbers up to arr[3]
    Decision:
    Since missing = 3 is less than k = 5, we move the left pointer l to the right of mid:
        we move l = mid + 1 = 4

3. Third Iteration:
    - mid = (l + r) / 2 = (4 + 4) / 2 = 4
    - arr[mid] = arr[4] = 11
    - Calculate the number of missing integers up to arr[mid]: 
        arr[mid] - (mid + 1) = 11 - (4 + 1) = 6
        So, there are 6 missing numbers up to arr[4]
    Decision:
    Since missing = 6 is greater than or equal to k = 5, we move the right pointer r to the left of mid: r = mid - 1 = 3


End of Binary Search:
At this point, the condition l <= r is no longer true because l = 4 and r = 3. The loop terminates.

Final Calculation:
The answer is l + k = 4 + 5 = 9.

Thus, the 5th missing positive integer is 9.



Recap of Key Points:
- We used binary search to find the first index where the number of missing integers is at least k.
- We calculated missing integers by comparing the actual value at an index (arr[mid]) with the expected value (mid + 1).
- After exiting the binary search, the left pointer l helps us determine the k-th missing integer using the formula l + k.

*/