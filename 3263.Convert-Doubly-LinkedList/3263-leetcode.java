    // Definition for a Node.
    class Node {
        public int val;
        public Node prev;
        public Node next;
    };
    
    class Solution {
        public int[] toArray(Node head) {
            List<Integer>res = new ArrayList<>();
            while(head != null){
                res.add(head.val);
                head = head.next;
            }
            return res.stream().mapToInt(i -> i).toArray();
        }
        
    }