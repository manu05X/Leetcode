using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (m[s[i]] < m[s[i + 1]]) {
                result -= m[s[i]];
                continue;
            }
            result += m[s[i]];
        }
        return result;
    }
};
/*
MCMXCIV

(M)1000 -> (C) 1000-100 -> (M) 1900 -> (X) 1900-10 -> (C) 1890+100 -> (I) 1990-1 -> 1989+5 => 1994 



The algorithm works as follows:

Create a mapping of Roman numerals to their integer values:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000


Initialize a variable result to store the final integer value.
Iterate through each character in the Roman numeral string from left to right:

For each character at position i, compare its value with the value of the next character (i+1)
If current value is less than next value (e.g., IV where I=1 < V=5):

Subtract current value from result (as per Roman numeral rules)


Otherwise:

Add current value to result




Return the final result





Dry Run of romanToInt for Input: s = "MCMXCIV"
Initialization:
Input: s = "MCMXCIV"
Mapping:
m['I'] = 1
m['V'] = 5
m['X'] = 10
m['L'] = 50
m['C'] = 100
m['D'] = 500
m['M'] = 1000
Result: result = 0

-> Initialization: Input: s = "MCMXCIV"
Iteration with i = 0:
Current character: s = 'M'
Compare: m[s] (1000) >= m[s] (100), so we add:
Update:
result += m['M'] → result = 0 + 1000 = 1000
Result: result = 1000


Iteration with i = 1:
Current character: s = 'C'
Compare: m[s] (100) < m[s] (1000), so we subtract:
Update:
result -= m['C'] → result = 1000 - 100 = 900
Result: result = 900



Iteration with i = 2:
Current character: s = 'M'
Compare: m[s] (1000) >= m[s] (10), so we add:
Update:
result += m['M'] → result = 900 + 1000 = 1900
Result: result = 1900


Iteration with i = 3:
Current character: s = 'X'
Compare: m[s] (10) < m[s] (100), so we subtract:
Update:
result -= m['X'] → result = 1900 - 10 = 1890
Result: result = 1890


Iteration with i = 4:
Current character: s = 'C'
Compare: m[s] (100) >= m[s] (1), so we add:
Update:
result += m['C'] → result = 1890 + 100 = 1990
Result: result = 1990


Iteration with i = 5:
Current character: s = 'I'
Compare: m[s] (1) < m[s] (5), so we subtract:
Update:
result -= m['I'] → result = 1990 - 1 = 1989
Result: result = 1989


Iteration with i = 6:
Current character: s = 'V'
This is the last character, and since there is no next character to compare, we simply add its value.
Update:
Add the value of 'V':
Result update not necessary since it's already accounted for in previous steps.

*/