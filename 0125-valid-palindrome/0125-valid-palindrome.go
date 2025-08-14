func isPalindrome(s string) bool {
	runes := []rune(s) // convert string to slice of runes for safe indexing
	left, right := 0, len(runes)-1

	for left < right {
		l, r := runes[left], runes[right]

		// Skip non-alphanumeric from left
		if !unicode.IsLetter(l) && !unicode.IsDigit(l) {
			left++
			continue
		}

		// Skip non-alphanumeric from right
		if !unicode.IsLetter(r) && !unicode.IsDigit(r) {
			right--
			continue
		}

		// Compare lowercase forms
		if unicode.ToLower(l) != unicode.ToLower(r) {
			return false
		}

		left++
		right--
	}

	return true
}