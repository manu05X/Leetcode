class TrieNode {
    TrieNode[] links = new TrieNode[26];
    int wordsEndingHere = 0;
    int wordsStartingHere = 0;
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                node.links[charIndex] = new TrieNode();
            }
            node = node.links[charIndex];
            node.wordsStartingHere++;
        }
        node.wordsEndingHere++;
    }

    public int countWordsEqualTo(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                return 0;
            }
            node = node.links[charIndex];
        }
        return node.wordsEndingHere;
    }

    public int countWordsStartingWith(String prefix) {
        TrieNode node = root;
        for (char w : prefix.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                return 0;
            }
            node = node.links[charIndex];
        }
        return node.wordsStartingHere;
    }

    public void erase(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            node = node.links[charIndex];
            node.wordsStartingHere--;
        }
        node.wordsEndingHere--;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * int param_2 = obj.countWordsEqualTo(word);
 * int param_3 = obj.countWordsStartingWith(prefix);
 * obj.erase(word);
 */