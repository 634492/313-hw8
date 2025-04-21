#include <stdio.h>
#define MAXSIZE 10

void display(int matrix[][10], int row, int column);
void transpose(int matrix[][10], int transpose[][10], int length, int width);
void scalarMult(int matrix[][10], int row, int column, int scale);
void matrixMult(int first[][10], int second[][10], int output[][10], int r1, int c1, int r2, int \
		c2);
// the rows and columns are already assumed to be equal to one another
void matrixAdd(int first[][10], int second[][10], int output[][10], int r, int c);

int main()
{
  // hard coding the matricies/2d arrays for simplicity. it is what the assignment r\
  equests
  // if futher testing is required modify them.
  int matrixA[MAXSIZE][MAXSIZE] = {{6, 4}, {8, 3}};
  int matrixB[MAXSIZE][MAXSIZE] = {{1, 2, 3}, {4, 5, 6}};
  int matrixC[MAXSIZE][MAXSIZE] = {{1, 3, 5}, {2, 4, 6}};
  display(matrixA, 2, 2);
  display(matrixB, 2, 3);
  display(matrixC, 2 , 3);
  int transposeC[MAXSIZE][MAXSIZE];
  transpose(matrixC, transposeC, 2, 3);
  display(transposeC, 3, 2);
  scalarMult(matrixB, 2, 3, 3);
  display(matrixB, 2, 3);
  int BtimesC[MAXSIZE][MAXSIZE];
  matrixMult(matrixB, transposeC, BtimesC, 2, 3, 3, 2);
  display(BtimesC,2,2);
  int result[MAXSIZE][MAXSIZE];
  matrixAdd(matrixA, BtimesC, result, 2, 2);
  display(result,2 ,2);

  return 0;
}

void display(int matrix[][10], int rowFirst, int columnSecond)
{
  int i, j;

  for(i = 0; i < rowFirst; ++i)
    {
      for(j = 0; j < columnSecond; ++j)
	{
	  printf("%d ", matrix[i][j]);
	  if(j == columnSecond - 1)
	    printf("\n");
	}
    }
}

void transpose(int matrix[][10], int transpose[][10], int length, int width)
{
  for (int i = 0; i < length; ++i)
    for (int j = 0; j < width; ++j) {
      transpose[j][i] = matrix[i][j];
    }

}

void scalarMult(int matrix[][10], int row, int column, int scale)
{
  int i, j;

  for(i = 0; i < row; ++i)
    {
      for(j = 0; j < column; ++j)
	{
	  matrix[i][j]*= scale;
	}
    }
}

void matrixMult(int first[][10], int second[][10], int output[][10]\
		, int r1, int c1, int r2, int c2)
{
  int i, j, k;

  for(i = 0; i < r1; ++i)
    {
      for(j = 0; j < c2; ++j)
	{
	  output[i][j] = 0;
	}
    }

  for(i = 0; i < r1; ++i)
    {
      for(j = 0; j < c2; ++j)
	{
	  for(k=0; k<c1; ++k)
	    {
	      output[i][j] += first[i][k] * second[k][j];
	    }
	}
    }

}

void matrixAdd(int first[][10], int second[][10], int output[][10],\
	       int r, int c)
{
  int i, j;

  for(i = 0; i < r; ++i)
    {
      for(j = 0; j < c; ++j)
	{
	  output[i][j] = 0;
	}
    }
  for(i = 0; i < r; ++i)
    {
      for(j = 0; j < c; ++j)
	{
	  output[i][j] = first[i][j] + second[i][j];
	}
    }
}
