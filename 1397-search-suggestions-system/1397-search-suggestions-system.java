import java.util.*;

class Solution {
    
    // TrieNode class represents each node in the Trie data structure
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>(); // Stores child nodes for each character
        List<String> suggestions = new ArrayList<>(); // Stores up to 3 lexicographically smallest suggestions
    }

    // Trie class to manage insertion and searching within the Trie structure
    class Trie {
        private TrieNode root;

        public Trie() {
            root = new TrieNode(); // Initialize the Trie with a root node
        }

        // Insert a product into the Trie
        public void insert(String product) {
            TrieNode node = root;
            for (char c : product.toCharArray()) {
                // Add a new TrieNode if the character is not present
                node.children.putIfAbsent(c, new TrieNode()); 
                // Move to the next node
                node = node.children.get(c); 
                if (node.suggestions.size() < 3) { 
                    // Store only the first 3 lexicographically sorted words
                    node.suggestions.add(product);
                }
            }
        }

        // Search for product suggestions based on searchWord
        public List<List<String>> search(String searchWord) {
            List<List<String>> result = new ArrayList<>();
            TrieNode node = root;
            for (char c : searchWord.toCharArray()) {
                // If the character is not found, break the loop
                if (!node.children.containsKey(c)) { 
                    break;
                }
                node = node.children.get(c); // Move to the next node
                // Add current node's suggestions to the result list
                result.add(node.suggestions); 
            }
            while (result.size() < searchWord.length()) {
                // Fill remaining searches with empty lists if no further matches
                result.add(new ArrayList<>()); 
            }
            return result;
        }
    }

    // Main function to generate product suggestions
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products); // Sort products lexicographically to maintain correct order
        Trie trie = new Trie();
        for (String product : products) {
            trie.insert(product); // Insert each product into the Trie
        }
        return trie.search(searchWord); // Perform search and return results
    }
}
