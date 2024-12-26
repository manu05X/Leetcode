class Solution {
    public int reverse(int x) {
        long ans = 0; // Use long to handle potential overflow during reversal

        while (x != 0) {
            int rem = x % 10; // Extract the last digit
            ans = ans * 10 + rem; // Build the reversed number
            x = x / 10; // Remove the last digit
        }

        // Check if the reversed number is within the 32-bit signed integer range
        if (ans < Integer.MIN_VALUE || ans > Integer.MAX_VALUE) {
            return 0;
        }

        return (int) ans; // Cast the result back to int
    }
}


/*
class Solution {
    public int reverse(int x) {
        boolean flag = false;
        if(x < 0){
            flag = true;
            x = x*-1;
        }

        int ans = 0;

        while(x > 0){
            int rem = x % 10;

            ans = (ans*10 + rem);
            x = x/10;
        }

        if(flag){
            ans = ans*-1;
        }

        // Check if the reversed number is within the 32-bit signed integer range
        if (ans < Integer.MIN_VALUE || ans > Integer.MAX_VALUE) {
            return 0;
        }

        return ans;
    }
}
*/