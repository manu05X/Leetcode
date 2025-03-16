class TrieNode {
    Map<Character, TrieNode> children;
    boolean endOfWord;

    TrieNode() {
        children = new HashMap<>();
        endOfWord = false;
    }
}

class Trie {
    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        node.endOfWord = true;
    }

    String getShortestPrefix(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        for (char c : word.toCharArray()) {
            if (!node.children.containsKey(c)) {
                return word; // No matching prefix found, return original word
            }
            prefix.append(c);
            node = node.children.get(c);
            if (node.endOfWord) {
                return prefix.toString(); // Found the shortest prefix
            }
        }
        return word;
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String word : dictionary) {
            trie.insert(word);
        }

        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = trie.getShortestPrefix(words[i]);
        }

        return String.join(" ", words);
    }
}