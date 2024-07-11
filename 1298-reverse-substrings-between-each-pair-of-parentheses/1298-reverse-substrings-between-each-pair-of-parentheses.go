func reverseParentheses(s string) string {
    n := len(s)
    bracketIndex := []int{}
    pair := make([]int, n)

    for i := 0; i < n; i++ {
        if s[i] == '(' {
            bracketIndex = append(bracketIndex, i)
        }
        if s[i] == ')' {
            j := bracketIndex[len(bracketIndex)-1]
            bracketIndex = bracketIndex[:len(bracketIndex)-1]
            pair[i] = j;
            pair[j] = i;
        }
    }

    result := make([]byte, 0, n)
    for currIndex, direction := 0,1; currIndex < n; currIndex += direction {
        if s[currIndex] == '(' || s[currIndex] == ')' {
            currIndex = pair[currIndex]
            direction = -direction
        } else {
            result = append(result, s[currIndex])
        }
    }

    return string(result)
}