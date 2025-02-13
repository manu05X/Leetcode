class Solution {
    public int maximum69Number (int num) {
        // Since we start with the lowest digit, initialize currDigit = 0.
        int numCopy = num;
        int idxSix = -1;
        int currDigit = 0;

        // Check every digit of 'numCopy' from low to high.
        while(numCopy > 0){
            // If the current digit is '6', record it as the highest digit of 6.
            if(numCopy % 10 == 6){
                idxSix = currDigit;
            }
            // Move on to the next digit.
            numCopy = numCopy/10;
            currDigit++;
        }
         // If we don't find any digit of '6', return the original number,
        // otherwise, increment 'num' by the difference made by the first '6'.
        return idxSix == -1 ? num : num+3 * (int)Math.pow(10, idxSix);
    }
}


/*
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
*/


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