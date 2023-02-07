//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sp2AND(float input1sp, float input2sp); 				//Είναι η συνάρτηση από το πρώτο εργαστήριο
int sp1Inverter(float c);										//το μόνο που άλλαξα στην συνάρτηση sp2AND είναι απο void σε int
void printer(int *a, int *b, int *c, int *e, int *f, int *d);		//γιατί θέλω να μου επιστρέφει το αποτέλεσμα

int main()
{
	int input_a[8]={0,0,0,0,1,1,1,1};
	int input_b[8]={0,0,1,1,0,0,1,1};
	int input_c[8]={0,1,0,1,0,1,0,1};
	int output_input_e[8];
	int output_input_f[8];
	int output_d[8];

	for(int i=0; i<8; i++)			//Σε αυτό το κομμάτι γίνεται ο υπολογισμός τωνεξόδων e και f που αποτελούν εισόδους 
	{									//στο κύκλωμα του τελικού AND όπου και τέλος γίνεται ο υπολογισμός της εξόδου d
		output_input_e[i]=sp2AND(input_a[i], input_b[i]);
		output_input_f[i]=sp1Inverter(input_c[i]);

		output_d[i]=sp2AND(output_input_e[i],output_input_f[i]);	
	}
	printer(input_a, input_b, input_c, output_input_e, output_input_f, output_d);
	return 1;
}

void printer(int *a, int *b, int *c, int *e, int *f, int *d)	//τυπώνει τον πίνακα αληθείας
{
	printf("a|b|c|e|f|d\n");
	for(int i=0; i<8; i++)
	{
		printf("%d|%d|%d|%d|%d|%d\n", a[i], b[i], c[i], e[i], f[i], d[i]);
	}
}

int sp2AND(float input1sp, float input2sp)
{
	float esw, s=0;	
	s=input1sp*input2sp;
	esw=2*s*(1-s);
	printf("2-AND Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);

	return s;	//η προσθήκη που έκανα
}

int sp1Inverter(float c)  //Η συνάρτηση που έπρεπε να φτιάξω για το κύκλωμα του inverter
{
	float esw, s=0;
	s=1-c;
	esw=2*s*(1-s);
	printf("1-Inverter Gate for input probabilities (%f): %f\nAnd switching activity(esw) is: %f\n\n", c, s, esw);

	return s;
}
