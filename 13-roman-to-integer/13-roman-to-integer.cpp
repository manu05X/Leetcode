class Solution {
public:
    int romanToInt(string s) {
        int total = 0, prev = INT_MAX;
        unordered_map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        for(char c : s)
        {
            // prev is less than next ex. IX, XL
            if(prev < roman[c])
                total -= 2*prev;
            // get total from map roman
            total += roman[c];
            prev = roman[c];
        }
        return total;
        
    }
};