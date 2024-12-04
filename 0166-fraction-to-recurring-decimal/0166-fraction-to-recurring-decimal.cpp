class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

    long long num = abs(numerator);
    long long den = abs(denominator);

    if(num ==0)return "0";
    string result = "";
    if(numerator>0 & denominator<0 || numerator<0 && denominator>0)
        result += "-";
    
    long long rem = num%den;
    result += to_string(num/den);
    if(rem ==0)
        return result;
    result += ".";

    unordered_map< long long , int> mp;
    while(rem!=0)
    {
        if( mp.find(rem)!=mp.end())    //!!! this is importnat
        {
            result.insert(mp[rem],"(");
            result += ")";
            break;
        }
        mp[rem] = result.size();
        rem = rem *10; 
        result += to_string(rem/den);
        rem = rem%den;

    }
    return result;; 
    }

};

/*
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string fraction;
        // If either one is negative (not both)
        if (numerator < 0 ^ denominator < 0) {
            fraction.append("-");
        }
        // Convert to Long long to prevent overflow
        long long dividend = labs((long long)numerator);
        long long divisor = labs((long long)denominator);
        fraction.append(to_string(dividend / divisor));
        long long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction;
        }
        fraction.append(".");
        unordered_map<long long, int> map;
        while (remainder != 0) {
            if (map.find(remainder) != map.end()) {
                fraction.insert(map[remainder], "(");
                fraction.append(")");
                break;
            }
            map[remainder] = fraction.length();
            remainder *= 10;
            fraction.append(to_string(remainder / divisor));
            remainder %= divisor;
        }
        return fraction;
    }
};
*/