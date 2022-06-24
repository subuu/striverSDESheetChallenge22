#include<math.h>
  bool isNumValid(int board[9][9],int i,int j, int n,int num)
{
    //check num is present in either row/column
    for(int k=0;k<n;k++)
    {
        if(board[i][k] == num || board[k][j] == num)
            {return false;}
    }

    //check num is present in box or not
    n = sqrt(n);
    int si = (i/n) * n;
    int sj = (j/n) * n;

    for(int p=si;p< si+n;p++)
    {
        for(int q=sj;q< sj+n;q++)
        {
            if(board[p][q] == num)
            {
                return false;
            }
        }
    }

return true;
}


bool sodukuSolver(int board[9][9],int i,int j,int n)
{
    //base case
    if(i==n)
    {
        return true;      //to get all possible solutions
    }    

    //recursive case
    if(j==n)    //row completed
    {
        return sodukuSolver(board,i+1,0,n );
    }

    if(board[i][j] != 0) // filled cell
    {
        return sodukuSolver(board,i,j+1,n );
    }    

    //number needs to be filled 
    for(int num = 1 ; num <= 9; num++ )    
    {
           if(isNumValid(board,i,j,n,num))
           {    //If it is safe to put the number then place it.
                   board[i][j] = num;

                   //check rest can be solved or not.
                   bool isRestSolvable  = sodukuSolver(board,i,j+1,n);
                   if(isRestSolvable)
                       {return true;}

                   board [i][j] = 0;
           }
    }
    return false;
}  
  
bool isItSudoku(int board[9][9]) {
    // Write your code here.
     return sodukuSolver(board,0,0,9);
}
