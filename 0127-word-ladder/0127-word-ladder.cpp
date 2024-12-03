class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Initialize the length of the transformation sequence
        int transformationLength = 0;

        // Create a set from the word list for quick lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If the endWord is not in the word list, no transformation is possible
        if (wordSet.find(endWord) == wordSet.end()) 
            return 0;

        // Queue for BFS traversal, starting with the beginWord
        queue<string> bfsQueue;
        bfsQueue.push(beginWord);

        // Perform BFS
        while (!bfsQueue.empty()) {
            // Increment transformation length for each level
            transformationLength++;

            // Process all words at the current level
            int levelSize = bfsQueue.size();
            for (int i = 0; i < levelSize; i++) {
                // Get the current word
                string currentWord = bfsQueue.front();
                bfsQueue.pop();

                // If the current word matches the endWord, return the length
                if (currentWord == endWord)
                    return transformationLength;

                // Try changing each character in the current word
                for (int pos = 0; pos < currentWord.size(); pos++) {
                    char originalChar = currentWord[pos];

                    // Replace the character with every possible lowercase letter
                    for (char replacementChar = 'a'; replacementChar <= 'z'; replacementChar++) {
                        // Skip if the character is the same
                        if (originalChar == replacementChar) 
                            continue;

                        // Form a new word by replacing the character
                        currentWord[pos] = replacementChar;

                        // If the new word exists in the word set
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            // Add the new word to the queue for further exploration
                            bfsQueue.push(currentWord);

                            // Remove the word from the set to prevent revisiting
                            wordSet.erase(currentWord);
                        }
                    }
                    // Restore the original character for the next iteration
                    currentWord[pos] = originalChar;
                }
            }
        }

        // If no transformation sequence is found, return 0
        return 0;
    }
};
