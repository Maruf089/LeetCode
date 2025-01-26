class Solution {
    public int[] twoSum(int[] arr, int target) {
        int[] res = new int[2];
        HashMap<Integer, Integer> mpp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.containsKey(moreNeeded)) {
                res[0] = mpp.get(moreNeeded);
                res[1] = i;
            }

            mpp.put(arr[i], i);
        }
        return res;
    }
}