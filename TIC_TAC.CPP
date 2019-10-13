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
void wonboard()
  {    }
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
