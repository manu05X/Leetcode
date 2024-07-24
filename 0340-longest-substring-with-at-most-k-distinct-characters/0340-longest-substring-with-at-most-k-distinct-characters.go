func lengthOfLongestSubstringKDistinct(s string, k int) int {
    n := len(s)
    mp := make(map[byte]int)
    maxLength := 0
    left := 0

    for right := 0; right < n; right++ {
        mp[s[right]]++
        for len(mp) > k {
            mp[s[left]]--
            if mp[s[left]] == 0 {
                delete(mp, s[left])
            }
            left++
        }
        if right-left+1 > maxLength {
            maxLength = right - left+1
        }
    }

    return maxLength
}