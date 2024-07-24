class Solution {
    func lengthOfLongestSubstringKDistinct(_ s: String, _ k: Int) -> Int {
        let s = Array(s)
        var freq: [Character: Int] = [:]
        var length = 0
        for end in s.indices {
            freq[s[end], default: 0] += 1
            if freq.keys.count > k {
                let prev = freq[s[end - length]] ?? 1
                if prev == 1 {
                    freq[s[end - length]] = nil
                } else {
                    freq[s[end - length]] = prev - 1
                }
            } else {
                length += 1
            }
            
        }
        return length
    }
}