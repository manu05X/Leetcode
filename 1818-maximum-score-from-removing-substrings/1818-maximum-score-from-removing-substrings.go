
func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i,j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }

    return string(runes)
}

func maximumGain(s string, x int, y int) int {
    n := len(s)

    if x < y {
        x,y = y, x
        s = reverseString(s)
    }

    aCount, bCount, totalCount := 0,0,0
    for i := 0; i < n; i++ {
        currChar := s[i]

        if currChar == 'a'{
            aCount++
        } else if currChar == 'b' {
            if aCount > 0 {
                aCount--
                totalCount += x
            } else {
                bCount++
            }
        } else {
            totalCount += min(aCount, bCount) * y
            aCount, bCount = 0,0;
        }

    }

    totalCount += min(aCount, bCount) * y

    return totalCount;
}