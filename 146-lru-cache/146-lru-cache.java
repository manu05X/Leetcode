

class LRUCache {
    // A double link list fits our purpose since we can
    // adjust the list (insert/delete) from any node with constant time complexity
    class Node {
        int key;
        int val;
        Node next;
        Node prev;
        
        public Node(int key, int val) {
            this.key = key;
            this.val = val;
            next = null;
            prev = null;
        }
    }
    
    // This map contains reference to node corresponding to a given key
    // Helps us search in the node in const time
    // We also track size of the cache with size of the map itself
    Map<Integer, Node> keyMap;
    // Initially these two nodes point to each other
    Node first; // Sentinel first node
    Node last; // Sentinel last node
    final int capacity; // Capacity of the cache
    
    // Any key inserted will be inserted at the FRONT of the list
    private Node insertAtFront(int key, int val) {
        Node node = new Node(key, val);
        // This node needs to point to the first sentinel node
        // Also, it points to the node that the first sentinel node
        // currently points at
        // Same adjustment needs to be made to the node it is now pointing to
        // Then the first sentinel node will point to this node
        
        Node temp = first.next;
        first.next = node;
        node.prev = first;
        node.next = temp;
        temp.prev = node;
        return node;
        
    }
    
    // Any key accessed will need to be moved to the FRONT of the list
    private void moveToFront(Node node) {
        // Here, we do total 6 adjustments
        // Node needs to point to the first sentinel node and vice-versa
        // Node points to the node first sentinel was pointing to and vice-versa
        // What node pointed to "before" will point to what was after the node, and vice-versa
        node.prev.next = node.next;
        node.next.prev = node.prev;
        Node temp = first.next;
        first.next = node;
        node.prev = first;
        node.next = temp;
        temp.prev = node;
    }
    
    // If the cache is full, then a node will need to be EVICTED
    private Node deleteFromLast() {
        if (last.prev == first) {
            // Safety check: do not delete sentinel nodes!
            return null;
        }
        Node node = last.prev;
        node.prev.next = last;
        last.prev = node.prev;
        return node;
    }
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        keyMap = new HashMap<>();
        first = new Node(-1, -1);
        last = new Node(-1, -1);
        first.next = last;
        last.prev = first;
    }
    
    public int get(int key) {
        // Use hashtable to access the node in O(1) complexity
        if (!keyMap.containsKey(key)) {
            return -1;
        }
        Node node = keyMap.get(key);
        // Since the node is accessed, needs to be moved to front
        moveToFront(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        // Update the LinkList and Hashtable
        if (keyMap.containsKey(key)) {
            // Node exists, so same as access
            Node node = keyMap.get(key);
            node.val = value;
            moveToFront(node);
        }
        else {
            // New node needs to be created
            keyMap.put(key, insertAtFront(key, value));
        }
        
        // Evict a node if necessary
        if (keyMap.size() > capacity) {
            Node node = deleteFromLast();
            keyMap.remove(node.key);
        }
    }
}
            
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
