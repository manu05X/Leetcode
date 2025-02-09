class ListNode{
    int key;
    int val;
    ListNode next;
    ListNode prev;

    public ListNode(int key, int val){
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    int capacty;
    Map<Integer, ListNode> dictionary;
    ListNode head;
    ListNode tail;

    public LRUCache(int capacity) {
        this.capacty = capacity;
        dictionary = new HashMap<>();
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);

        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(!dictionary.containsKey(key)){
            return -1;
        }

        ListNode node = dictionary.get(key);
        remove(node);
        add(node);

        return node.val;
    }
    
    public void put(int key, int value) {
        if(dictionary.containsKey(key)){
            ListNode oldNode = dictionary.get(key);
            remove(oldNode);
        }

        ListNode node = new ListNode(key, value);
        dictionary.put(key, node);
        add(node);

        if(dictionary.size() > capacty){
            ListNode nodeToDelete = head.next;
            remove(nodeToDelete);
            
            dictionary.remove(nodeToDelete.key);
        }
    }

    public void add(ListNode node){
        ListNode prevEnd = tail.prev;
        prevEnd.next = node;

        node.prev = prevEnd;
        node.next = tail;

        tail.prev = node;
    }

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