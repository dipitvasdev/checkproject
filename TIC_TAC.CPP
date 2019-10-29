#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
char a[3][3] = { '*','*','*','*','*','*','*','*','*'} ;
int l=0 , m=0 ;
int movetoss()
  {
      int toss = random(2);
      return toss;
  }
int indexconvert(int i,int j)
  {
     return 3*i+j ;
  }
void reverseindex(int place)
  {
      if (place < 3 )
	{
	   l = 0; m = place;
	}
      else if ( place < 6)
	{
	   l = 1 ; m = place - (3*l) ;
	}
      else
	 { l = 2 ; m = place - (3*l); }
   }
void chooseintial()
  {
	   int place ;
      n:   place = random(9);
	   if (place == 1 || place == 3 || place == 5 || place == 7)
	       goto n;
	   else
	       {
		   reverseindex(place);
		   a[l][m] = 'O';
	       }
  }

void drawboard()
  {
     for ( int i=0 ; i < 3 ; i++ )
       {
	 for (int j=0 ; j <3  ; j++ )
	   {
	      if ( a[i][j] != '*' )
		  cout << a[i][j] << " " << " | " << " " ;
	      else
		  cout << "  " << " | " << " " ;
	   }
	 cout << endl ;
       }
  }
void append(int x[],int N,int element){
  int i=0 ;
  for(i=0;i<N;i++)
  {
    if(x[i]==-1)
      break ;
  }
  x[i]=element ;
}
int wonboard(char a[][2])
  {
    int xcount=0,ocount=0 ;  
    int xfill[]={-1,-1,-1,-1,-1},ofill[]={-1,-1,-1,-1,-1} ; // -1 indicates that the xfill array is empty  
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        if(a[i][j]=='X'){
          append(xfill,5,indexconvert(i,j)) ;
          xcount++ ;
        }
        else
        {
          append(ofill,5,indexconvert(i,j)) ;
          ocount++ ;
        }
      }
    }
    if(xcount>=3){
      for(int i=0;i<xcount;i++)
        for(int j=i+1;j<xcount;i++)
          for(int k=j+1;k<xcount;k++)
            if(xfill[i]+xfill[k]-2*xfill[j]==0)
              return 0  ; // Returning 0 if X wins
    }
    else if(ocount>=3){
      for(int i=0;i<ocount;i++)
        for(int j=i+1;j<ocount;i++)
          for(int k=j+1;k<ocount;k++)
            if(xfill[i]+xfill[k]-2*xfill[j]==0)
              return 1  ;  // Returning 1 if X wins
    }
    else
      return 2 ;
  }
void checkboard(int lastmove)
  {
     int place
     reverseindex(lastmove);
     /* if conditions to be added */
     else
      { 	n:  place = random(9);
		    reverseindex(place);
		    if ( (a[l][m] != '*')  ||  (place == 1) || (place == 3) || (place == 5 ) || (place == 7) )
		       goto n ;
		    else
		       a[l][m] = 'O' ;
      }
  }
