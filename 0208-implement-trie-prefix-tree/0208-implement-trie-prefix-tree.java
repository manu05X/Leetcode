class TrieNode {

    // R links to node children
    private TrieNode[] child;

    private final int R = 26;

    private boolean isEnd;

    public TrieNode() {
        child = new TrieNode[R];
    }

    public boolean containsKey(char ch) {
        return child[ch -'a'] != null;
    }
    public TrieNode get(char ch) {
        return child[ch -'a'];
    }
    public void put(char ch, TrieNode node) {
        child[ch -'a'] = node;
    }
    public void setEnd() {
        isEnd = true;
    }
    public boolean isEnd() {
        return isEnd;
    }
}



class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode node = root;

        for(int i = 0; i < word.length(); i++){
            char currChar = word.charAt(i);
            if(!node.containsKey(currChar)){
                node.put(currChar, new TrieNode());
            }

            node = node.get(currChar);
        }
        node.setEnd();
    }

    // search a prefix or whole key in trie and
    // returns the node where search ends
    private TrieNode searchPrefix(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
           char curLetter = word.charAt(i);
           if (node.containsKey(curLetter)) {
               node = node.get(curLetter);
           } else {
               return null;
           }
        }
        return node;
    }
    
    public boolean search(String word) {
        TrieNode node = searchPrefix(word);
       return node != null && node.isEnd();
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = searchPrefix(prefix);
        return node != null;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */