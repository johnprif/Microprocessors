//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float sp2AND(float input1sp, float input2sp); 				//Είναι η συνάρτηση από το πρώτο εργαστήριο
float sp1Inverter(float c);										//το μόνο που άλλαξα στην συνάρτηση sp2AND είναι απο void σε float
																//γιατί θέλω να μου επιστρέφει το αποτέλεσμα
int main()
{
	float input_a=0.5;
	float input_b=0.5;
	float input_c=0.5;
	float output_input_e, output_input_f, output_d, esw;

	output_input_e=sp2AND(input_a, input_b);
	output_input_f=sp1Inverter(input_c);

	output_d=sp2AND(output_input_e, output_input_f);

	esw=2*output_d*(1-output_d); //Υπολογισμός του switching activity της εξόδου d

	printf("The switching activity for complete circuit is: %f\n", esw);
	return 1;
}

float sp2AND(float input1sp, float input2sp)
{
	float esw, s=0;	
	s=input1sp*input2sp;
	esw=2*s*(1-s);
	printf("2-AND Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);

	return s;	//η προσθήκη που έκανα
}

float sp1Inverter(float c)  //Η συνάρτηση που έπρεπε να φτιάξω για το κύκλωμα του inverter
{
	float esw, s=0;
	s=1-c;
	esw=2*s*(1-s);
	printf("1-Inverter Gate for input probabilities (%f): %f\nAnd switching activity(esw) is: %f\n\n", c, s, esw);

	return s;
}
