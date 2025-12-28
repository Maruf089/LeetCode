class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = 0 , col = matrix[0].length - 1;
        boolean present = false;
        while(row < matrix.length && col >= 0){
            if(matrix[row][col]==target){
                present = true;
                break;
            }
            if(matrix[row][col] > target) col--; // left
            else if(matrix[row][col] < target) row++; // down
        }
        return present;
        
    }
}