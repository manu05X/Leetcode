class Solution {
    public int maximum69Number (int num) {
        // Convert the input 'num' to a string builder 'numSB'.
        StringBuilder numSB = new StringBuilder();
        numSB.append(num);

        for(int i = 0; i < numSB.length(); i++){
            // If we find the first '6', replace it with '9' and break the loop.
            if(numSB.charAt(i) == '6'){
                numSB.setCharAt(i,'9');
                break;
            }
        }

        // Convert the modified string builder to integer and return it.
        return Integer.parseInt(numSB.toString());
    }
}

/*

class Solution {
    public int maximum69Number (int num) {
        // Convert the input 'num' to the string 'numString'.
        String numString = "" + num;

        // Use the built-in function to replace the first '6' with '9'.
        // Return the integer converted from the modified 'numString'.
        return Integer.parseInt(numString.replaceFirst("6", "9"));
    }
}

*/