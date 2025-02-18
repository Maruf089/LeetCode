// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

public class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new C());
        long last = Long.MIN_VALUE;
        int count = 0;
        for (int i = 0; i < points.length; i++) {
            if (last < points[i][0]) {
                last = points[i][1];
                count++;
            }
        }
        return count;
    }
    
    class C implements Comparator<int[]> {
        public int compare(int[] a1, int[] a2) {
            return Integer.compare(a1[1], a2[1]);
        }
    }
}