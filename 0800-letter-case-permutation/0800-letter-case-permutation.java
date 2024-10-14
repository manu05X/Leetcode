class Solution {
    public List<String> letterCasePermutation(String S) {
        // Initialize a list with the original string S
        List<String> res = new ArrayList<>();
        res.add(S);

        // Iterate through each character in the string
        for (int i = 0; i < S.length(); i++) {
            // If the current character is a digit, skip it
            if (Character.isDigit(S.charAt(i))) {
                continue;
            }

            // Get the current size of the result list
            int len = res.size();

            // For each string in the list, toggle the case of the character at position i
            for (int j = 0; j < len; j++) {
                String tmp = res.get(j);

                // Convert the string to a char array to toggle the case
                char[] arr = tmp.toCharArray();
                
                // Toggle the case of the character at position i
                if (Character.isLowerCase(arr[i])) {
                    arr[i] = Character.toUpperCase(arr[i]);
                } else {
                    arr[i] = Character.toLowerCase(arr[i]);
                }

                // Add the modified string to the list
                res.add(new String(arr));
            }
        }

        return res;
    }
}

/*
Initial Input
    Input: S = "a1b2"
    Result list (res): Initially contains ["a1b2"].
Step-by-Step Dry Run
Iteration 1 (i = 0):
    Current character: S[0] = 'a' (a letter).
    We process the list res which currently contains ["a1b2"].
    The size of res is 1, so we iterate through it:
        For j = 0, we take "a1b2", toggle the case of S[0], making it "A1b2", and add "A1b2" to res.
        res is now: ["a1b2", "A1b2"].

Iteration 2 (i = 1):
    Current character: S[1] = '1' (a digit).
    Since it's a digit, we skip this iteration and move to the next character.
    res remains unchanged: ["a1b2", "A1b2"].

Iteration 3 (i = 2):
    Current character: S[2] = 'b' (a letter).
    We process the list res which now contains ["a1b2", "A1b2"].
    The size of res is 2, so we iterate through it:
        For j = 0, we take "a1b2", toggle the case of S[2], making it "a1B2", and add "a1B2" to res.
        For j = 1, we take "A1b2", toggle the case of S[2], making it "A1B2", and add "A1B2" to res.
        res is now: ["a1b2", "A1b2", "a1B2", "A1B2"].

Iteration 4 (i = 3):
    Current character: S[3] = '2' (a digit).
    Since it's a digit, we skip this iteration and move to the next character.
    res remains unchanged: ["a1b2", "A1b2", "a1B2", "A1B2"].

Final Result
After processing all characters of the input string S, the final result is:

["a1b2", "A1b2", "a1B2", "A1B2"].
*/