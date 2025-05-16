class Solution {
public:
    string intToRoman(int num) {
        // Vector of integer values and their corresponding Roman numeral symbols
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, 
            {900, "CM"}, 
            {500, "D"}, 
            {400, "CD"},
            {100, "C"},
            {90, "XC"},     // Missing in your code
            {50, "L"},      // Missing in your code
            {40, "XL"},     // Missing in your code
            {10, "X"},      // Missing in your code
            {9, "IX"},      // Missing in your code
            {5, "V"}, 
            {4, "IV"}, 
            {1, "I"}
        };

        string res;  // Resultant Roman numeral string

        // Iterate through each value-symbol pair
        for (const auto& [value, symbol] : valueSymbols) {
            // Early exit if number is already reduced to 0
            if (num == 0) break;

            // Append symbol to result while the number is greater than or equal to value
            while (num >= value) {
                res += symbol;   // Add corresponding Roman symbol
                num -= value;    // Subtract its value from number
            }
        }

        return res;  // Return the final Roman numeral
    }
};



/*
class Solution {
public:
    string intToRoman(int num) {
        string romans[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int numerals[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
        string s;
        while(num)
        {
            for(int i = 12; i >= 0; i--)
            {
                int x = num/numerals[i];
                if(x)
                {
                    while(x--)
                    {
                        s += romans[i];
                    }
                    num %= numerals[i];
                    break;
                }
            }
        }
        return s;
    }
};

*/