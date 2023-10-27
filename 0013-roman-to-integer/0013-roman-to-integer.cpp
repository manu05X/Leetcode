class Solution {
public:
    int romanToInt(string input_str) {
        map<char, int> values = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

	int total = 0;
	int i = 0;
	while (i < input_str.length()) {
		// If this is the subtractive case.
		if (i + 1 < input_str.length() && (values.find(input_str.at(i))->second < values.find(input_str.at(i + 1))->second)) {
			total += values.find(input_str.at(i + 1))->second - values.find(input_str.at(i))->second;
			i += 2;
		}

		// Else this is NOT the subtractive case.
		else {
			total += values.find(input_str.at(i))->second;
			i += 1;
		}
	}
	return total;
        
    }
};