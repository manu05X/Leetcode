import java.util.*;

class Solution {
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        List<String> suggestions = new ArrayList<>();
    }

    class Trie {
        private TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        public void insert(String product) {
            TrieNode node = root;
            for (char c : product.toCharArray()) {
                node.children.putIfAbsent(c, new TrieNode());
                node = node.children.get(c);
                if (node.suggestions.size() < 3) { // Store up to 3 lexicographically smallest words
                    node.suggestions.add(product);
                }
            }
        }

        public List<List<String>> search(String searchWord) {
            List<List<String>> result = new ArrayList<>();
            TrieNode node = root;
            for (char c : searchWord.toCharArray()) {
                if (!node.children.containsKey(c)) {
                    break;
                }
                node = node.children.get(c);
                result.add(node.suggestions);
            }
            while (result.size() < searchWord.length()) {
                result.add(new ArrayList<>()); // Fill remaining searches with empty lists
            }
            return result;
        }
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products); // Sort lexicographically
        Trie trie = new Trie();
        for (String product : products) {
            trie.insert(product);
        }
        return trie.search(searchWord);
    }
}
