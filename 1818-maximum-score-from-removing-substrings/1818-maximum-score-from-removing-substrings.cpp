class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        // Ensure "ab" always has more points than "ba"
        if(x < y){
            int t = x;
            x = y;
            y = t;
            // Reverse the string to maintain logic
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, totalPoints = 0;
        for(int i = 0; i < n; i++){
            char currChar = s[i];

            if(currChar == 'a'){
                aCount++;
            } else if(currChar == 'b'){
                if(aCount > 0){
                    // Can form "ab", remove it and add points
                    aCount--;
                    totalPoints += x;
                } else {
                    // Can't form "ab", keep 'b' for potential future "ba"
                    bCount++;
                }
            }
            else{
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                totalPoints += min(aCount, bCount)*y;
                // Reset counters for next segment
                aCount = 0;
                bCount = 0;
            }
        }
         // Calculate points for any remaining "ba" pairs at the end
        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};