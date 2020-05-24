#include<stdio.h>
#include<stdlib.h>
#define GRN	"\x1B[32m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
int cnt=81;
struct Memory
{
    int x[9];
}m[81];
int s[9][9];
int check(int,int);
int display();

void main()
{
   
    int r,c,e;
    printf("Enter the row, coloumn and element and 100 after you have completed entering the data:\n");
	printf("Please ensure that you enter atleast 17 elements\n");
    while(1)
    {
        scanf("%d",&r);
        if(r==100)
        break;
        else
        {
            scanf("%d%d",&c,&e);
            if(r>9||c>9||e>9||r<1||c<1||e<1)
            {
            	printf("Invalid entry!!\n");
              	continue;
            }
            else
            {
            	s[r-1][c-1]=e;
            	cnt--;
            }
        }
    }
	if(cnt>64)
	{
		printf("Number of elements entered is less than 17 cannot solve the sudoku please try again\n");
		exit(1);
	}
    display();
    while(cnt>0)
    {
    	for(r=0;r<9;r++)
    	{
        	for(c=0;c<9;c++)
        	{
        	    if(s[r][c]==0)
        	       { check(r,c);
        	   			if(cnt%5==0)
        	    		display();
					}
        	}
    	}
   	}

   
   
}
int display()
{	
	static int step=0;
	printf(RED"\n\n\t\t\t\t\t\t   * SUDOKU SOLVER STEP NO. %d *\n"RESET,step++);
    int i,j;
    printf(GRN"\t\t\t\t\t\t _______________________________\n\n"RESET);
    for(i=0;i<9;i++)
    {   
		printf(GRN"\t\t\t\t\t\t |"RESET);
        for(j=0;j<9;j++)
        {
            if(s[i][j]==0)
                printf("   ");
            else
                printf( " %d ",s[i][j]);
			if((j+1)%3==0)
				printf(GRN"|"RESET);          
        }
            if((i+1)%3==0)
            	printf(GRN"\n\t\t\t\t\t\t _______________________________\n"RESET);   
            printf("\n");
    }
   
    return 0;   
}
int check(int r,int c)
{
    int i,j,k,n=9,a=r/3,b=c/3,l;  //a,b are grid index elements
    for(i=0;i<9;i++)
    {
        m[9*r+c].x[i]=i+1;        //to store 1 to 9 in the address array
    }
    for(j=0;j<9;j++)
    {
        if(s[r][j]!=0)
        {
            for(i=0;i<n;i++)
            {
                if(s[r][j]==m[9*r+c].x[i])   //comparison logic for column
                {
                    for(k=i;k<n;k++)     //delete element r
                        m[9*r+c].x[k]=m[9*r+c].x[k+1];
                    n=n-1;
                   
                }
            }
        }
    }
    if(n==1)
    {
    	s[r][c]=m[9*r+c].x[0];
    	cnt--;
    	return 0;
    }
    for(j=0;j<9;j++)
    {
        if(s[j][c]!=0)
        {
            for(i=0;i<n;i++)
            {
                if(s[j][c]==m[9*r+c].x[i])   //comparison logic
                {
                    for(k=i;k<n;k++)//delete element from c
                         m[9*r+c].x[k]=m[9*r+c].x[k+1];
                    n=n-1;
                   
                }
            }
        }
    }
    if(n==1)
    {
    	s[r][c]=m[9*r+c].x[0];
    	cnt--;
    	return 0;
    }
    for(i=a*3;i<(a*3)+3;i++)            //delete element from grid
    {
        for(j=b*3;j<(b*3)+3;j++)
        {
            if(s[i][j]!=0)
            {
                for(l=0;l<n;l++)
                {
                    if(s[i][j]==m[9*r+c].x[l])
                    {
                        for(k=l;k<n;k++)
                            m[9*r+c].x[k]=m[9*r+c].x[k+1];
                        n=n-1;
                    }
                }
            }
        }
    }
    if(n==1)
    {
    	s[r][c]=m[9*r+c].x[0];
    	cnt--;
    	return 0;
    }
    return 0;
}
