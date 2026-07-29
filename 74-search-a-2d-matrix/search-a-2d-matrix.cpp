class Solution {
public:
    bool searchRow(vector<vector<int>>&matrix, int midRow, int target){
        int n=matrix[midRow].size();
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=start+((end-start)/2);
            if (matrix[midRow][mid]==target){
                return true;
            }
            else if(matrix[midRow][mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int startRow=0;
        int endRow=m-1;
        while(startRow<=endRow){
        int midRow=startRow+((endRow-startRow)/2);
        if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
             return searchRow(matrix, midRow, target );
        }
        else if(target>matrix[midRow][n-1]){
            startRow=midRow+1;
        }
        else{
            endRow=midRow-1;
        }


        
    }
    return false;
    }
};