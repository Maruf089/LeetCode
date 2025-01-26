// print-the-elements-of-a-linked-list hackerrank

public class solution{
    public class SinglyLinkedListNode{
        public Integer data;
        public SinglyLinkedListNode next;
        public SinglyLinkedListNode(Integer nodeData){
            this.data = nodeData;
            next = null;
        }
    }
    public class SinglyLinkedList{
        SinglyLinkedListNode head;
        SinglyLinkedListNode tail;
        public SinglyLinkedList(){
            this.head = null;
            this.tail = null;
        }
        public void InsertIntoList(Integer nodeData){
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);
            if(this.head==null){
                this.head = node;
            }else{
                this.tail.next = node;
            }
            this.tail = node;
        }
    }
    
}