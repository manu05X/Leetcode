func maxCount(banned []int, n int, maxSum int) int {
     // Create a set to store banned numbers for quick lookup
    bannedSet := make(map[int]bool)
    for _, num := range banned {
        bannedSet[num] = true
    }

    count := 0 // Initialize count to track the number of valid numbers included

    // Iterate through numbers from 1 to n
    for i := 1; i <= n; i++ {
        // Skip the number if it's in the banned set
        if bannedSet[i] {
            continue
        }

        // If including the current number exceeds maxSum, return the count
        if maxSum-i < 0 {
            return count
        }

        // Deduct the current number from maxSum
        maxSum -= i

        // Increment the count
        count++
    }

    // Return the total count of valid numbers included
    return count
}