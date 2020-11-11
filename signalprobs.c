//ΠΡΙΦΤΗ ΙΩΑΝΝΗΣ 3321
//PRIFTI JOANIS 3321
//Αν δωθεί κάποια λανθασμένη είσοδος πρέπει να ξεκινήσετε απο την αρχή το πρόγραμμα
//Δεν πήρα όλες τις περιπτπώσεις πχ να δώσει ο χρήστης κάποια γράμμα αντί για αριθμό 
//Θεώρησα ότι θα ήταν έξτρα κόπος χωρίς λόγο
//Έχω χωρήσει με σχόλια-παύλες τον κώδικα σε κομμάτια όπου γίνεται ο υπολογισμός με:
//Πύλες 2 εισόδων
//Πύλες 3 εισόδων
//Πύλες Ν εισόδων
//Οι Συναρτήσεις που υπολογίζουν τις πύλες Ν εισόδων παίρνουν 2 ορίσματα
//Το πλήθος των ορισμάτων που είναι τύπου int και ένα δείκτη σε πίνακα με τα ορίσματα 

#include <stdio.h>
#include <stdlib.h>

void sp2AND(float input1sp, float input2sp);
void sp2OR(float input1sp, float input2sp);
void sp2XOR(float input1sp, float input2sp);
void sp2NAND(float input1sp, float input2sp);
void sp2NOR(float input1sp, float input2sp);

void sp3AND(float input1sp, float input2sp, float input3sp);
void sp3OR(float input1sp, float input2sp, float input3sp);
void sp3XOR(float input1sp, float input2sp, float input3sp);
void sp3NAND(float input1sp, float input2sp, float input3sp);
void sp3NOR(float input1sp, float input2sp, float input3sp);

void spN_AND(int pars, float* matrix);
void spN_OR(int pars, float* matrix);
void spN_XOR(int pars, float* matrix);
void spN_NAND(int pars, float* matrix);
void spN_NOR(int pars, float* matrix);

int main()
{
	float inputArray[100]; //Θα μπορούσα να δεσμεύσω δυναμικά τον πίνακα με malloc αλλά χάρην συντομίας έφτιαξα έναν στατικό πίνακα
	int pars;			   //και έφιαξα έναν με 100 θέσεις για το πολύ 100 παραμέτρους
	
	printf("Give input1sp and input2sp for 2-input gates with space beetwen: ");
	scanf("%f%f", &inputArray[0], &inputArray[1]);
	sp2AND(inputArray[0], inputArray[1]);
	sp2OR(inputArray[0], inputArray[1]);
	sp2XOR(inputArray[0], inputArray[1]);
	sp2NAND(inputArray[0], inputArray[1]);
	sp2NOR(inputArray[0], inputArray[1]);

	printf("----------------------------------------------------------------------------------------------------------------\n");

	printf("Give input1sp and input2sp and input3sp for 3-input gates with space beetwen: ");
	scanf("%f%f%f", &inputArray[0], &inputArray[1], &inputArray[2]);
	sp3AND(inputArray[0], inputArray[1], inputArray[2]);
	sp3OR(inputArray[0], inputArray[1], inputArray[2]);
	sp3XOR(inputArray[0], inputArray[1], inputArray[2]);
	sp3NAND(inputArray[0], inputArray[1], inputArray[2]);
	sp3NOR(inputArray[0], inputArray[1], inputArray[2]);

	printf("----------------------------------------------------------------------------------------------------------------\n");

	printf("Give the number of parameters: ");
	scanf("%d", &pars);
	for(int i=0; i<pars; i++)
	{
		printf("\nGive the input%dsp: ", i+1);
		scanf("%f", &inputArray[i]);
	}
	spN_AND(pars, inputArray);
	spN_OR(pars, inputArray);
	spN_XOR(pars, inputArray);
	spN_NAND(pars, inputArray);
	spN_NOR(pars, inputArray);
	
	return 1;
}

void sp2AND(float input1sp, float input2sp)
{
	float esw, s=0;	
	s=input1sp*input2sp;
	esw=2*s*(1-s);
	printf("2-AND Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);
}

void sp2OR(float input1sp, float input2sp)
{
	float esw, s=0;
	s=1-(1-input1sp)*(1-input2sp);
	esw=2*s*(1-s);
	printf("2-OR Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);	
}

void sp2XOR(float input1sp, float input2sp)
{
	float esw, s=0;
	s=(1-input1sp)*input2sp+input1sp*(1-input2sp);
	esw=2*s*(1-s);
	printf("2-XOR Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);
}

void sp2NAND(float input1sp, float input2sp)
{
	float esw, s=0;
	s=(1-input1sp)*(1-input2sp)+(1-input1sp)*input2sp+input1sp*(1-input2sp);
	esw=2*s*(1-s);
	printf("2-NAND Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);
}

void sp2NOR(float input1sp, float input2sp)
{
	float esw, s=0;
	s=(1-input1sp)*(1-input2sp);
	esw=2*s*(1-s);
	printf("2-NOR Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);
}
//----------------------------------------------------------------------------------------------------------
void sp3AND(float input1sp, float input2sp, float input3sp)
{
	float esw, s=0;
	s=input1sp*input2sp*input3sp;
	esw=2*s*(1-s);
	printf("3-AND Gate for input probabilities (%f %f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, input3sp, s, esw);
}
void sp3OR(float input1sp, float input2sp, float input3sp)
{
	float esw, s=0;
	s=1-(1-input1sp)*(1-input2sp)*(1-input3sp);
	esw=2*s*(1-s);
	printf("3-OR Gate for input probabilities (%f %f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, input3sp, s, esw);
}
void sp3XOR(float input1sp, float input2sp, float input3sp)
{
	float esw, s=0;
	s=(1-input1sp)*(1-input2sp)*input3sp+(1-input1sp)*input2sp*(1-input3sp)+input1sp*(1-input2sp)*(1-input3sp)+input1sp*input2sp*input3sp;
	esw=2*s*(1-s);
	printf("3-XOR Gate for input probabilities (%f %f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, input3sp, s, esw);
}
void sp3NAND(float input1sp, float input2sp, float input3sp)
{
	float esw, s=0;
	s=1-input1sp*input2sp*input3sp;
	esw=2*s*(1-s);
	printf("3-NAND Gate for input probabilities (%f %f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, input3sp, s, esw);
}
void sp3NOR(float input1sp, float input2sp, float input3sp)
{
	float esw, s=0;
	s=(1-input1sp)*(1-input2sp)*(1-input3sp);
	esw=2*s*(1-s);
	printf("3-NOR Gate for input probabilities (%f %f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, input3sp, s, esw);
}
//--------------------------------------------------------------------------------------------------------------
void spN_AND(int pars, float* matrix)
{
	float esw;
	float s=1;

	for(int i=0; i<pars; i++)
	{
		s*=matrix[i];
	}
	esw=2*s*(1-s);
	printf("N-AND Gate for input probabilities (%d, ...): %f\nAnd switching activity(esw) is: %f\n\n", pars, s, esw);
}

void spN_OR(int pars, float* matrix)
{
	float s=1;
	float esw;
	float temp=1;

	for(int i=0; i<pars; i++)
	{
		temp*=(1-matrix[i]);	
	}
	s-=temp;
	esw=2*s*(1-s);
	printf("N-OR Gate for input probabilities (%d, ...): %f\nAnd switching activity(esw) is: %f\n\n", pars, s, esw);
}

void spN_XOR(int pars, float* matrix)
{
	float s=0;
	float esw;
	float temp_out=1;
	if (pars>2)
	{
		temp_out=(1-matrix[0])*matrix[1]+matrix[0]*(1-matrix[1]);
		for(int i=2; i<pars; i++)
		{
			s=(1-temp_out)*matrix[i]+temp_out*(1-matrix[i]);
			temp_out=s;
		}
	}else
	{
		s=temp_out;
	}
	esw=2*s*(1-s);
	printf("N-XOR Gate for input probabilities (%d, ...): %f\nAnd switching activity(esw) is: %f\n\n", pars, s, esw);
}

void spN_NAND(int pars, float* matrix)
{
	float s=1;
	float temp=1;
	float esw;

	for(int i=0; i<pars; i++)
	{
		temp*=matrix[i];	
	}
	s-=temp;
	esw=2*s*(1-s);
	printf("N-NAND Gate for input probabilities (%d, ...): %f\nAnd switching activity(esw) is: %f\n\n", pars, s, esw);
}

void spN_NOR(int pars, float* matrix)
{
	float esw;
	float s=1;

	for(int i=0; i<pars; i++)
	{
		s*=(1-matrix[i]);	
	}
	esw=2*s*(1-s);
	printf("N-NOR Gate for input probabilities (%d, ...): %f\nAnd switching activity(esw) is: %f\n\n", pars, s, esw);
}