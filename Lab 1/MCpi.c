//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321
//Έβαλα τις τιμές των επαναλήψεων (10,100,1000,3321,10000) σε ένα πίνακα και μετά εκτελείται το πρόγραμμα 5 φορές, μία φορά για κάθε πλήθος επαναλήψεων
//ΣΗΜΕΙΩΣΗ
//Επειδή το ξεχνάω και ο ίδιος συχνά
//Το compile γίνετε με την εντολή gcc MCpi.c -lm λόγω του ότι χρησιμοποιώ την math.h

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	double x,y,temp=0.0;
	int countInCircle=0;
	int inputLoops[5]={10,100,1000,3321,10000};
	srand(time(NULL));

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<inputLoops[i]; j++)
		{
			x=(double)rand()/RAND_MAX;
			y=(double)rand()/RAND_MAX;

			temp=sqrt((x*x)+(y*y));	
		
			if(temp<=1.0)
			{
				countInCircle+=1;
			}
		}
		printf("\nFor inputLoops %d The estimate of pi is: %f\n\n",inputLoops[i], (double)countInCircle/inputLoops[i]*4);
		countInCircle=0;
	}
	return 1;
}