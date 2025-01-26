public class Main{
    public static void main(String[] args){
        List<String>lst = new ArrayList<>();
        lst.add("maruf");
        lst.remove(0);// by indx
        lst.remove("maruf");
        lst.get(1);
        for(String ele : lst){
            System.out.println(ele);
        }

        Stack<String> st = new Stack<>();
        st.push("A");
        System.out.println(st.peek());
        st.pop();

        HashSet<String> hashSet = new HashSet<>();
        hashSet.add("A");
        hashSet.remove("A");
        hashSet.add("A");
        hashSet.add("B");
        System.out.println("HashSet after removal: " + hashSet);

        Queue<String> queue = new PriorityQueue<>();
        queue.add("a");
        queue.remove();
        queue.peek();

        Deque<String> deque = new ArrayDeque<>();
        deque.add("A");
        deque.addFirst("AA");
        deque.addLast("CC");
        deque.peek();
        deque.removeFirst();
        deque.removeLast();

        HashMap<String,Integer> mp = new HashMap<>();
        mp.put("a" , 1);
        mp.get("a");
        mp.containsKey("a");
        mp.containsValue(1);
        mp.keySet();
        mp.values();
        mp.forEach((key,value) -> {

        });
    }
}