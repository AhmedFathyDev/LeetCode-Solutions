public class Solution {
    public int[][] DiagonalSort(int[][] mat) {
        for (var i = mat.Length - 1; i >= 0; --i)
        {
            var matrixDiagonal = new List<int>();
            
            for (int j = 0, k = i; j < mat[0].Length && k < mat.Length; ++j, ++k)
            {
                matrixDiagonal.Add(mat[k][j]);
            }

            matrixDiagonal.Sort();
            
            for (int j = 0, k = i; j < mat[0].Length && k < mat.Length; ++j, ++k)
            {
                mat[k][j] = matrixDiagonal[j];
            }
        }

        for (var j = 1; j < mat[0].Length; ++j)
        {
            var matrixDiagonal = new List<int>();

            for (int i = 0, k = j; i < mat.Length && k < mat[0].Length; ++i, ++k)
            {
                matrixDiagonal.Add(mat[i][k]);
            }
            
            matrixDiagonal.Sort();
            
            for (int i = 0, k = j; i < mat.Length && k < mat[0].Length; ++i, ++k)
            {
                mat[i][k] = matrixDiagonal[i];
            }
        }

        return mat;
    }
}   