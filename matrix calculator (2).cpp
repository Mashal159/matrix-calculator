//Made by Mashal159 in april 2022



#include <iostream>
#include <math.h>
using namespace std;
 int determinat(int matrix[10][10],int d)
 {
     int det=0;
     if (d==1) return matrix[0][0];
     if (d==2)
     {
     return (matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1]);
     }
     if (d > 2)
     {
     int sub[10][10]={0};
     for (int i = 0 ;i < d;i++)
     {
       int a = 0;
       for (int j = 1 ;j < d;j++)
       {
           int b = 0;
           for (int k = 0;k < d;k++)
           {
               if (k==i)continue;
               sub[a][b]=matrix[j][k];
               b++;
           }
           a++;
       }
         det=det+(pow(-1,i)*matrix[0][i]*determinat(sub,d- 1));
     }
     return det;
     }
 }

int main()
{
    int i,j,operation,column_a,row_a,column_b,row_b;
    cout<<"Please enter dimensions of Matrix A:"<<"\n";
    cin>>row_a>>column_a;
    cout<<"Please enter dimensions of Matrix B:"<<"\n";
    cin>>row_b>>column_b;

    int matrixA[10][10],matrixB[10][10],matrixC[10][10],submat[10][10];
    cout<<"Please enter values of Matrix A:"<<"\n";
    for (int i=0;i<row_a;i++)
    {
        for (int j=0;j<column_a;j++)
        {
        cin>>matrixA[i][j];
        }

    }
    cout<< "Please enter values of Matrix B: "<<"\n";
       for (int i=0;i<row_b;i++)
    {
        for (int j=0;j<column_b;j++)
        {
        cin>>matrixB[i][j];
        }

    }
    operation=0;
     cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
    cin>>operation;

    while (operation!=7)
    {
    if (operation==1)
    {
        if (row_a!=row_b||column_a!=column_b)
        cout<<"The operation you chose is invalid for the given matrices."<<"\n";

        else
        {
          for (i=0;i<column_a;i++)
    {

        for (j=0;j<row_a;j++)
        {
                matrixC[i][j]=matrixA[i][j]+matrixB[i][j];

        cout<<matrixC[i][j]<<"  ";

        }
    cout<<"\n";
    }
        }
 cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
 cin>>operation;
    }
    else if (operation==2)
    {
         if (row_a!=row_b||column_a!=column_b)
        cout<<"The operation you chose is invalid for the given matrices."<<"\n";

        else
        {
          for (i=0;i<column_a;i++)
    {

        for (j=0;j<row_a;j++)
        {
                matrixC[i][j]=matrixA[i][j]-matrixB[i][j];

        cout<<matrixC[i][j]<<"  ";

        }
    cout<<"\n";
    }
        }
 cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
 cin>>operation;
    }
    else if (operation==3)
    {
        if (column_a!=row_b)
    {
        cout<<"The operation you chose is invalid for the given matrices."<<"\n";


    }
    else
    {
    int term =0,k;
     for (i=0;i<row_a;i++)
    {
        for (k=0;k<column_b;k++)
        {
        for (j=0;j<column_a;j++)
        {
                term=matrixA[i][j]*matrixB[j][k]+term;


        }
         matrixC[i][k]=term;
         term=0;
        cout<< matrixC[i][k] << " ";

        }
        cout<<"\n";
    }
   cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
 cin>>operation;
    }
    }

    else if (operation==5)
    {
        if (row_a!=column_a)
        {
        cout<<"The operation you chose is invalid for the given matrices."<<"\n";
          cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";

        }
        else
        {
          cout<< determinat(matrixA,row_a)<<"\n";
           cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
        }
        cin>>operation;
    }
     else if (operation==6)
    {
        if (row_b!=column_b)
        {
        cout<<"The operation you chose is invalid for the given matrices."<<"\n";
          cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";

        }
        else
        {
          cout<< determinat(matrixB,row_b)<<"\n";
           cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<"\n";
        }
        cin>>operation;
    }

    }
    cout<<"Thank you!";
}
