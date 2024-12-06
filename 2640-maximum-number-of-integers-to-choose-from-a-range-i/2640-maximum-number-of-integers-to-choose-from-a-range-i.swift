class Solution {
    func maxCount(_ banned: [Int], _ n: Int, _ maxSum: Int) -> Int {
        // Create a set to store banned numbers for quick lookup
        let bannedSet = Set(banned)
        var count = 0 // Initialize count to track the number of valid numbers included
        var currentSum = maxSum // Track the remaining sum

        // Iterate through numbers from 1 to n
        for i in 1...n {
            // Skip the number if it's in the banned set
            if bannedSet.contains(i) {
                continue
            }

            // If including the current number exceeds maxSum, return the count
            if currentSum - i < 0 {
                return count
            }

            // Deduct the current number from currentSum
            currentSum -= i

            // Increment the count
            count += 1
        }

        // Return the total count of valid numbers included
        return count
    }
}