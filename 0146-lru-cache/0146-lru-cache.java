class LRUCache {
    private final int capacity;
    private final Map<Integer,Node>map;
    private Node head,tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.head = new Node(0,0);
        this.tail = new Node(0,0);

        head.next = tail;
        tail.prev = head;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);
            node.value = value;
            remove(node);
            insertAtFront(node);
        }
        else{
            if(map.size()==capacity){
                // remove least recently used
                Node lru = tail.prev;
                remove(lru);
                map.remove(lru.key);
            }
            Node node = new Node(key,value);
            insertAtFront(node);
            map.put(key,node);
        } 
    }

    public void remove(Node node){
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    public void insertAtFront(Node node){
        Node prevNode = head;
        Node nextNode = head.next;
        prevNode.next = node;
        nextNode.prev = node;
        node.prev = head;
        node.next = nextNode;
    }

    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        Node node = map.get(key);
        remove(node);
        insertAtFront(node);
        return node.value;
    }
}

class Node{
    int key, value;
    Node next,prev;
    Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */