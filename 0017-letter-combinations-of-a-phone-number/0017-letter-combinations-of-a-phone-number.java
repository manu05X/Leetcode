class Solution {
    public List<String> letterCombinations(String digits) {
         List<String> result = new ArrayList<>(); // Result list to store combinations
        if (digits == null || digits.length() == 0) { // If input string is empty or null
            return result; // Return empty list
        }
        
        // Mapping of digits to corresponding letters
        String[] letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Call the backtrack function to generate combinations
        backtrack(result, letters, digits, "", 0);
        
        return result; // Return the list of combinations
    }
    
    // Backtracking function to generate combinations recursively
    private void backtrack(List<String> result, String[] letters, String digits, String current, int index) {
        // If the current combination is complete, add it to the result list
        if (index == digits.length()) {
            result.add(current);
            return;
        }
        
        // Get the corresponding letters for the current digit
        String letter = letters[digits.charAt(index) - '0'];
        
        // Iterate over each letter and append it to the current combination
        for (int i = 0; i < letter.length(); i++) {
            backtrack(result, letters, digits, current + letter.charAt(i), index + 1); // Recursive call
        }
    }
}