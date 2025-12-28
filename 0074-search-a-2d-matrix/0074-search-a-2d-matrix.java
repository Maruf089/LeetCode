class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        boolean present = false;
        int low = 0 , high = rows * cols - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int row_idx = mid / cols;
            int col_idx = mid % cols;
            if(matrix[row_idx][col_idx]==target)
            {
                present = true; 
                break;
            }
            if(matrix[row_idx][col_idx] < target)
                low = mid + 1;
            else high = mid - 1;
        }
        return present;
        
    }
}