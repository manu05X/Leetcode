class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};

/*
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();

        if(n != m){
            return false;
        }

        int p1 = 0, p2 = 0;

        while( p1 <= n && p2 <= n){

            while(p1 < n && target[p1] == '_'){
                p1++;
            }

            while(p2 < n && start[p2] == '_'){
                p2++;
            }

            if(p1 == n || p2 == n){
                return p1 == n && p2 == n;
            }

            if(target[p1] != start[p2]) return false;

            if(target[p1] == 'L'){
                if(p2 < p1) return false;
            } else {
                if(p1 < p2) return false;
            }

            p1++;
            p2++;

        }

        return true;

    }
};
*/


/*
_L__R__R_

L______RR


*/