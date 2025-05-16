class Solution {
    public String intToRoman(int num) {
        // Array of Roman numeral values and their corresponding symbols
        int[] values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        StringBuilder result = new StringBuilder();

        // Iterate through values and symbols
        for (int i = 0; i < values.length && num > 0; i++) 
        {
            while (num >= values[i]) 
            {
                result.append(symbols[i]);  // Append corresponding symbol
                num -= values[i];           // Subtract the value from number
            }
        }

        return result.toString();
    }
}
