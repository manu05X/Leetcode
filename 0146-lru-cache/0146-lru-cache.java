class ListNode {
    int key;
    int val;
    ListNode next;
    ListNode prev;

    // Constructor for ListNode
    public ListNode(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    int capacity;  // Maximum capacity of the cache
    Map<Integer, ListNode> dictionary; // HashMap to store key-node mapping
    ListNode head; // Dummy head of the doubly linked list
    ListNode tail; // Dummy tail of the doubly linked list

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dictionary = new HashMap<>();
        head = new ListNode(-1, -1); // Dummy head
        tail = new ListNode(-1, -1); // Dummy tail

        // Connect head and tail
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        // If the key is not found in the cache, return -1
        if (!dictionary.containsKey(key)) {
            return -1;
        }

        // Fetch the node from the map
        ListNode node = dictionary.get(key);

        // Move the accessed node to the most recently used position (end of the list)
        remove(node);
        add(node);

        return node.val; // Return the value of the node
    }
    
    public void put(int key, int value) {
        // If the key already exists in the cache, remove it
        if (dictionary.containsKey(key)) {
            ListNode oldNode = dictionary.get(key);
            remove(oldNode);
        }

        // Create a new node and insert it into the cache
        ListNode node = new ListNode(key, value);
        dictionary.put(key, node);
        add(node);

        // If cache exceeds capacity, remove the least recently used node
        if (dictionary.size() > capacity) {
            ListNode nodeToDelete = head.next; // LRU node is next to head
            remove(nodeToDelete);
            dictionary.remove(nodeToDelete.key); // Remove it from the map
        }
    }

    // Function to add a node at the end (Most Recently Used position)
    public void add(ListNode node) {
        ListNode prevEnd = tail.prev; // Node before tail
        prevEnd.next = node;
        node.prev = prevEnd;
        node.next = tail;
        tail.prev = node;
    }

    // Function to remove a node from the doubly linked list
    public void remove(ListNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */