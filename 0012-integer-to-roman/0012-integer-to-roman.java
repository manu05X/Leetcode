/*
class Solution {
    public String intToRoman(int num) {
        int[] base = new int[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] chars = new String[]{"M","CM","D","CD","C","XC","L","XL","X","IX", "V", "IV", "I"};
        //expand the "base" char to make sure that the roman numeric can be only the 1 - 3 appearance of the characters above
        String result = "";
        for (int i = 0; i < base.length; i ++) {
            if (num / base[i] > 0) {
                for (int j = 0; j < num/base[i]; j ++) {
                    result = result + chars[i];
                }
                num = num - (num / base[i]) * base[i];
            }
        }
        return result;
    }
}
*/

class Solution {
    public String intToRoman(int num) {
        // Map to store integer values and their corresponding Roman numeral symbols
        Map<Integer, String> romanMap = new LinkedHashMap<>();
        romanMap.put(1000, "M");
        romanMap.put(900, "CM");
        romanMap.put(500, "D");
        romanMap.put(400, "CD");
        romanMap.put(100, "C");
        romanMap.put(90, "XC");
        romanMap.put(50, "L");
        romanMap.put(40, "XL");
        romanMap.put(10, "X");
        romanMap.put(9, "IX");
        romanMap.put(5, "V");
        romanMap.put(4, "IV");
        romanMap.put(1, "I");

        StringBuilder result = new StringBuilder(); // To build the resulting Roman numeral string

        // Iterate through the map and construct the Roman numeral
        for (Map.Entry<Integer, String> entry : romanMap.entrySet()) {
            while (num >= entry.getKey()) { // While the number is greater than or equal to the key
                result.append(entry.getValue()); // Append the corresponding Roman numeral
                num -= entry.getKey(); // Decrease the number by the key value
            }
        }

        return result.toString(); // Return the final Roman numeral string
    }
}