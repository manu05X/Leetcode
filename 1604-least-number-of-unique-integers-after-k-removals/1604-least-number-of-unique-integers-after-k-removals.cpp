class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counts;
        for (int num: arr) {
            counts[num]++;
        }
        
        vector<int> ordered;
        for (auto [key, val]: counts) {
            ordered.push_back(val);
        }
        
        sort(ordered.begin(), ordered.end(), greater<int>());
        while (k > 0) {
            int val = ordered.back();
            if (val <= k) {
                k -= val;
                ordered.pop_back();
            } else {
                break;
            }
        }
        
        return ordered.size();
    }
};

/*
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Create a hashmap to count the occurrence of each integer in the array
        unordered_map<int, int> frequencyMap;
        for (int number : arr) {
            ++frequencyMap[number];
        }

        // Extract the frequencies and sort them in ascending order
        vector<int> frequencies;
        for (auto& [number, count] : frequencyMap) {
            frequencies.push_back(count);
        }
        sort(frequencies.begin(), frequencies.end());

        // Determine the least number of unique integers by removing k occurrences
        int uniqueIntegers = frequencies.size(); // start with all unique integers
        for (int i = 0; i < frequencies.size(); ++i) {
            // Subtract the frequency of the current number from k
            k -= frequencies[i];

            // If k becomes negative, we can't remove any more numbers
            if (k < 0) {
                return uniqueIntegers - i; // Return the remaining number of unique integers
            }
        }

        // If k is non-negative after all removals, we've removed all duplicates
        return 0;
    }
};

*/