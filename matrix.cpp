using System;

namespace matrixspace
{
    public class matrix
    {
        public int X { get; set;}
        public int Y { get; set; }
        public int Dimension { get; set; } 
        public int[,] Matrix_Value { get; set; }
        public double Determinant(int Dimension, int[,] Matrix_Value)
        {
            double determinant = 0;
            int[,] Matrix_Extended = new int[Dimension, (Dimension * 2) - 1];
            for (int i = 0; i < Dimension; i++)
            {
                for (int j = 0; j < Dimension; j++)
                {
                    Matrix_Extended[i, j] = Matrix_Value[i, j];
                    if (j != Dimension-1)
                    {
                        Matrix_Extended[i, j + Dimension] = Matrix_Value[i, j];
                    }
                }
            }
            for (int i = 0; i < Dimension; i++)
            {
                int temp_det = 1;
                for (int j = 0; j < Dimension; j++)
                {
                    temp_det *= (Matrix_Extended[j, j + i]);
                }
                determinant += temp_det;
            }
            for (int i = 0; i < Dimension; i++)
            {
                int temp_det = 1;
                for (int j = 0; j < Dimension; j++)
                {
                    temp_det *= (Matrix_Extended[j, (Dimension * 2) - 2 - j - i]);
                }
                determinant -= temp_det;
            }
            return determinant;
        }
        // TODO: Проверка на -1.
        public void Print(int Dimension, int[,] Matrix_Value)
        {
            for (int i = 0; i < Dimension; i++)
            {
                for (int j = 0; j < Dimension; j++)
                {
                    Console.Write($"({Matrix_Value[i, j]}) ");
                }
                Console.WriteLine(" ");
            }
        }
        // TODO: Вывод через X,Y.
        public int[,] Composition(int alfa, int[,] Matrix_Value, int Dimension)
        {
            int[,] Matrix = Matrix_Value;
            for(int i = 0; i < Dimension; i++)
            {
                for (int j = 0; j < Dimension; j++)
                {
                    Matrix_Value[i, j] *= alfa;
                }
            }
            return Matrix;
        }
        // TODO: Умножение на альфа X,Y.
        public int[,] Composition(int[,] Matrix_Value, int[,] Matrix_B, int XA, int YA, int XB, int YB)
        {
            return 0; // TODO: A*B (matrix).
        }
        public matrix(int x, int y, int[,] matrix_value)
        {
            X = x;
            Y = y;
            Dimension = -1;
            Matrix_Value = matrix_value;
        }
        public matrix(int dimension, int[,] matrix_value)
        {
            X = dimension;
            Y = dimension;
            Dimension = dimension;
            Matrix_Value = matrix_value;
        }
    }

    public class TestClass
    {
        static void Main(string[] args)
        {

            int[,] matrix_value = new int[3,3] { 
                {3, 2, 3}, 
                {1, -1, 0}, 
                {1, 7, 3} };
            var abr = new matrix(3, matrix_value);
            abr.Print(3, matrix_value);
            Console.WriteLine($"detA = {abr.Determinant(3, matrix_value)}");
        }
    }
}
