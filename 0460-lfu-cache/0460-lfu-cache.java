// Node class for storing key-value-frequency
    class Node {
        int key, value, frequency;
        Node prev, next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.frequency = 1; // Every new node starts with frequency 1
        }
    }

    // Doubly linked list for each frequency level
    class DoublyLinkedList {
        Node head, tail;
        int size;

        public DoublyLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        // Adds node to the front of the list (Most recently used at this frequency)
        public void addNode(Node node) {
            Node nextNode = head.next;
            head.next = node;
            node.prev = head;
            node.next = nextNode;
            nextNode.prev = node;
            size++;
        }

        // Removes a given node
        public void removeNode(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        // Returns whether the list is empty
        public boolean isEmpty() {
            return size == 0;
        }
    }


class LFUCache {
    int capacity;
    int minFrequency;  // Tracks the least frequency in the cache
    Map<Integer, Node> cache;  // Stores key -> Node mappings
    Map<Integer, DoublyLinkedList> frequencyMap;  // Stores freq -> DoublyLinkedList mappings

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFrequency = 0;
        cache = new HashMap<>();
        frequencyMap = new HashMap<>();
    }

    public int get(int key) {
        if (!cache.containsKey(key)) return -1;

        Node node = cache.get(key);
        updateFrequency(node);  // Increase the node frequency
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value;  // Update the value
            updateFrequency(node);
        } else {
            if (cache.size() >= capacity) {
                // Remove least frequently used node
                DoublyLinkedList list = frequencyMap.get(minFrequency);
                Node nodeToRemove = list.tail.prev; // Get LRU node from min frequency list
                cache.remove(nodeToRemove.key);
                list.removeNode(nodeToRemove);
                if (list.isEmpty()) {
                    frequencyMap.remove(minFrequency);
                }
            }

            // Insert the new node
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            minFrequency = 1; // New nodes always start at frequency 1
            frequencyMap.putIfAbsent(1, new DoublyLinkedList());
            frequencyMap.get(1).addNode(newNode);
        }
    }

    private void updateFrequency(Node node) {
        int freq = node.frequency;
        frequencyMap.get(freq).removeNode(node);
        if (frequencyMap.get(freq).isEmpty()) {
            frequencyMap.remove(freq);
            if (minFrequency == freq) {
                minFrequency++;
            }
        }

        // Increase frequency and reinsert into new list
        node.frequency++;
        frequencyMap.putIfAbsent(node.frequency, new DoublyLinkedList());
        frequencyMap.get(node.frequency).addNode(node);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */