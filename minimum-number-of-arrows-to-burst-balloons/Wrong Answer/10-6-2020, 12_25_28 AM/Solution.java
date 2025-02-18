// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) {
            return 0;
        }
        // sort the array of balloons by ending position
        Arrays.sort(points, (a, b) -> (a[1] - b[1]));

        int arrowPos = points[0][1];
        int arrowCnt = 1;
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] <= arrowPos) {
                continue;
            }
            // if the balloon's starting position isn't in the range
            // then add the counter and update the arrowPos
            arrowCnt++;
            arrowPos = points[i][1];
        }

        return arrowCnt;
    }
}