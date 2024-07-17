class Solution {
    func isPalindrome(_ s: String) -> Bool {
        if s.count < 2 {
            return true
        }

        let s = Array(s)
        var leftPtr = 0
        var rightPtr = s.count-1

        while leftPtr < rightPtr {
            let leftChar = s[leftPtr]
            let rightChar = s[rightPtr]

            if !leftChar.isNumber, !leftChar.isLetter {
                leftPtr += 1;
                continue
            }

            if !rightChar.isLetter, !rightChar.isNumber {
                rightPtr -= 1
                continue
            }

            if leftChar.lowercased() != rightChar.lowercased() {
                return false
            }

            leftPtr += 1
            rightPtr -= 1
        }

        return true
    }
}