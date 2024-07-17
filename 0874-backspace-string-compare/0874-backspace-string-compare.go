
// processString processes the input string by simulating backspace operations
func processString(str string) string {
    // Initialize an empty slice to hold the processed characters
	var processed []rune

    for _, c := range str{
        if c == '#' {
            if len(processed) > 0 {
                processed = processed[:len(processed)-1]
            }
        } else {
            processed = append(processed,c)
        }
    }

    return string(processed)
}

func backspaceCompare(s string, t string) bool {
    // Process both strings and compare their results
	return processString(s) == processString(t)
}