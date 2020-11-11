//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321
//Όμοια με πριν, δηλαδή έχω βάλει τα πλήθει των επαναλήψεων σε ένα πίνακα και εκτελώ το πρόγραμμα 4 φορές

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int OR_1, OR_2, OR_3, OR_4, OR_out, OR_old, switchesNumber=0;
	int inputLoops[4]={10,20,30,3321};
	float switchingActivity;
	srand(time(NULL));
	
	for (int i=0; i<4; i++)
	{
		OR_1=rand()%2;			//Αρχικοποιώ τυχαία τις εισόδους έξω απο την for-loop για να πάρω την 
		OR_2=rand()%2;			// πρώτη έξοδο και να την συγκρίνω παρακάτω με την επόμενη έξοδο
		OR_3=rand()%2;			
		OR_4=rand()%2;
		OR_out=OR_1 || OR_2 || OR_3 || OR_4;
		OR_old=OR_out;

		for(int j=1; j<inputLoops[i]; j++)	//Ξεκινάει απο το 1 και όχι απο το μηδέν διότι υπολογίστηκε παραπάνω η
		{									// η προηγούμενη (πρώτη) έξοδος
			OR_1=rand()%2;
			OR_2=rand()%2;
			OR_3=rand()%2;
			OR_4=rand()%2;

			OR_out=OR_1 || OR_2 || OR_3 || OR_4;
			
			if(OR_old!=OR_out)
			{
				switchesNumber+=1;
			}

			OR_old=OR_out;
		}
		switchingActivity=(float)switchesNumber/inputLoops[i];
		printf("For workload=%d, the switchingActivity is: %f\n", inputLoops[i], switchingActivity);
		switchesNumber=0;
	}
	return 1;
}