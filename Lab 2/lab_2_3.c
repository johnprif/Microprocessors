//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sp2AND(int input1sp, int input2sp); 				//Είναι η συνάρτηση από το πρώτο εργαστήριο
int sp1Inverter(int c);										//το μόνο που άλλαξα στην συνάρτηση sp2AND είναι απο void σε int
void compute_switches(int old_e, int old_f, int old_d, int new_e, int new_f, int new_d, int *switches_e, int *switches_f, int *switches_d, int i);																//όπως επίσης και τους τύπους των τιμών εισόδου απο float σε int
void printer(int *switches_e, int *switches_f, int *switches_d, int *inputLoops);	

int main()
{
	int inputLoops[3]={10, 100, 3321}; //Το πλήθος των επαναλήψεων 
	int a, b, c, old_e, new_e, old_f, new_f, old_d, new_d;
	int switches_e[3]={0,0,0};
	int switches_f[3]={0,0,0};	//Πίνακες που θα φιλοξενήσουν τα switches για την κάθε έξοδο 
	int switches_d[3]={0,0,0};

	srand(time(NULL));

	for(int i=0; i<3; i++)
	{
		a=rand()%2;			//Κάνω τον πρώτο υπολογισμό έξω απο την εμφωλιασμένη for-loop για να μπορέσω να βρω τις τιμές 
		b=rand()%2;				//των πρώτων εξόδων και να τις θέσω ως παλιές για να τις συγκρίνω με τις επόμενες
		c=rand()%2;

		old_e=sp2AND(a, b);
		old_f=sp1Inverter(c);
		old_d=sp2AND(old_e, old_f);

		for(int j=1; j<inputLoops[i]; j++)
		{
			a=rand()%2;
			b=rand()%2;
			c=rand()%2;

			new_e=sp2AND(a, b);
			new_f=sp1Inverter(c);
			new_d=sp2AND(new_e, new_f);

			compute_switches(old_e, old_f, old_d, new_e, new_f, new_d, switches_e, switches_f, switches_d, i);	

			old_e=new_e;
			old_f=new_f;
			old_d=new_d;	
		}
	}
	printer(switches_e, switches_f, switches_d, inputLoops);	//Η συνάρτηση της τελικής εκτύπωσης
	return 1;
}

int sp2AND(int input1sp, int input2sp)
{
	float esw;
	int s;	
	s=input1sp*input2sp;
	esw=2*s*(1-s);
	printf("2-AND Gate for input probabilities (%d %d): %d\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw); //Επιπλέον έχω αλλάξει τους τύπους εξόδου

	return s;	//η προσθήκη που έκανα
}

int sp1Inverter(int c)  //Η συνάρτηση που έπρεπε να φτιάξω για το κύκλωμα του inverter
{
	float esw;
	int s;
	s=1-c;
	esw=2*s*(1-s);
	printf("1-Inverter Gate for input probabilities (%d): %d\nAnd switching activity(esw) is: %f\n\n", c, s, esw);

	return s;
}
//Εδώ υπολογίζω τα switches των τριών εξόδων, όπου παίρνει τιμές των προηγούμενων και των επόμενων εξόδων e,f,d
void compute_switches(int old_e, int old_f, int old_d, int new_e, int new_f, int new_d, int *switches_e, int *switches_f, int *switches_d, int i)
{
	if(old_e!=new_e)
	{
		switches_e[i]+=1;
	}

	if(old_f!=new_f)
	{
		switches_f[i]+=1;
	}

	if(old_d!=new_d)
	{
		switches_d[i]+=1;
	}
}
//Εδώ γίνεται η τελική εκτύπωση των επιμέρους και του συνολικού switching activity
void printer(int *switches_e, int *switches_f, int *switches_d, int *inputLoops)
{
	for(int i=0; i<3; i++)
	{
		printf("For workload=%d, the switchingActivity of first AND is: %f\n", inputLoops[i], (float)switches_e[i]/inputLoops[i]);
		printf("For workload=%d, the switchingActivity of Inverter is: %f\n", inputLoops[i], (float)switches_f[i]/inputLoops[i]);
		printf("For workload=%d, the switchingActivity of complete circle is: %f\n", inputLoops[i], (float)switches_d[i]/inputLoops[i]);
		printf("---------------------------------------------------------------------------------\n");
	}
}
