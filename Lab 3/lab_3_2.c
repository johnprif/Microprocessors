#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
	char type[4];
	int inputs[2];
	int output;
}Element;

float sp2AND(float input1sp, float input2sp); //Είναι η συνάρτηση από το πρώτο εργαστήριο
float sp1Inverter(float c);
void process(float *SignalsTable, Element *element);
int testbench(float *SignalsTable, Element *element, int mode);
void readFromFile();

int main()
{

	char ElementTypes[2][4]={"NOT", "AND"};
	float SignalsTable[6];
	int topInputs[3]={0,1,2};

	Element E1;
	Element E2;
	Element E3;

	Element ElementsTable[3]={E1, E2, E3};

	strcpy(ElementsTable[0].type,ElementTypes[1]);
	ElementsTable[0].inputs[0]=0;
	ElementsTable[0].inputs[1]=1;
	ElementsTable[0].output=4;

	strcpy(ElementsTable[1].type,ElementTypes[0]);
	ElementsTable[1].inputs[0]=2;
	ElementsTable[1].inputs[1]=9.9;
	ElementsTable[1].output=5;

	strcpy(ElementsTable[2].type,ElementTypes[1]);
	ElementsTable[2].inputs[0]=4;
	ElementsTable[2].inputs[1]=5;
	ElementsTable[2].output=3;

	readFromFile();
/*	
	printf("\nGive input_a: ");
	scanf("%f", &SignalsTable[topInputs[0]]);
	printf("\nGive input_b: ");
	scanf("%f", &SignalsTable[topInputs[1]]);
	printf("\nGive input_c: ");
	scanf("%f", &SignalsTable[topInputs[2]]);
*/
	process(SignalsTable, ElementsTable);
	testbench(SignalsTable, ElementsTable, 1);
	
	SignalsTable[0]=0.5;
	SignalsTable[1]=0.5;
	SignalsTable[2]=0.5;
	process(SignalsTable, ElementsTable);
	testbench(SignalsTable, ElementsTable, 2);

	SignalsTable[0]=0.3321;
	SignalsTable[1]=0.3321;
	SignalsTable[2]=0.3321;
	process(SignalsTable, ElementsTable);
	testbench(SignalsTable, ElementsTable, 3);


	return 1;
}

float sp2AND(float input1sp, float input2sp)
{
	float esw, s=0;	
	s=input1sp*input2sp;
	esw=2*s*(1-s);
//	printf("2-AND Gate for input probabilities (%f %f): %f\nAnd switching activity(esw) is: %f\n\n",input1sp,input2sp, s, esw);

	return s;	//η προσθήκη που έκανα
}

float sp1Inverter(float c)  //Η συνάρτηση που έπρεπε να φτιάξω για το κύκλωμα του inverter
{
	float esw, s=0;
	s=1-c;
	esw=2*s*(1-s);
//	printf("1-Inverter Gate for input probabilities (%f): %f\nAnd switching activity(esw) is: %f\n\n", c, s, esw);

	return s;
}

void process(float *SignalsTable, Element *element)
{
	for(int i=0; i<3; i++)
	{
		if(strcmp(element[i].type,"AND")==0)
		{
			SignalsTable[element[i].output]=sp2AND(SignalsTable[element[i].inputs[0]], SignalsTable[element[i].inputs[1]]);
		}else if(strcmp(element[i].type,"NOT")==0)
		{
			SignalsTable[element[i].output]=sp1Inverter(SignalsTable[element[i].inputs[0]]);
		}
	}
}

int testbench(float *SignalsTable, Element *element, int mode)
{
	float input_a[]={0,0,0,0,1,1,1,1,0.5,0.3321};
	float input_b[]={0,0,1,1,0,0,1,1,0.5,0.3321};
	float input_c[]={0,1,0,1,0,1,0,1,0.5,0.3321};
	float output_input_e[]={0,0,0,0,0,0,1,1,0.25,0.110290};
	float output_input_f[]={1,0,1,0,1,0,1,0,0.5,0.667900};
	float output_d[]={0,0,0,0,0,0,1,0,0.125,0.073663};
	for(int i=0; i<10; i++)
	{
		if((SignalsTable[element[0].inputs[0]]-0.00001<input_a[i] && SignalsTable[element[0].inputs[0]]+0.00001>input_a[i]) && (SignalsTable[element[0].inputs[1]]-0.00001<input_b[i] && SignalsTable[element[0].inputs[1]]+0.00001>input_b[i]) && (SignalsTable[element[0].output]-0.00001<output_input_e[i] && SignalsTable[element[0].output]+0.00001>output_input_e[i]))
		{
			if((SignalsTable[element[1].inputs[0]]-0.00001<input_c[i] && SignalsTable[element[1].inputs[0]]+0.00001>input_c[i]) && (SignalsTable[element[1].output]-0.00001<output_input_f[i] && SignalsTable[element[1].output]+0.00001>output_input_f[i]))
			{
				if((SignalsTable[element[2].inputs[0]]-0.00001<output_input_e[i] && SignalsTable[element[2].inputs[0]]+0.00001>output_input_e[i]) && (SignalsTable[element[2].inputs[1]]-0.00001<output_input_f[i] && SignalsTable[element[2].inputs[1]]+0.00001>output_input_f[i]) && (SignalsTable[element[2].output]-0.00001<output_d[i] && SignalsTable[element[2].output]+0.00001>output_d[i]))
				{
					if(mode==1)
					{
						printf("\nIt works properly\n");
						return 1;
					}else if(mode==2)
					{
						printf("\nFor a=0.5, b=0.5, c=0.5");
						printf("\nThe average switching activity of first AND is: %f", 2*input_a[i]*input_b[i]*(1-input_a[i]*input_b[i]));
						printf("\nThe average switching activity of INVERTER is: %f", 2*(1-input_c[i])*input_c[i]);
						printf("\nThe average switching activity of ALL circuit is: %f\n", 2*input_a[i]*input_b[i]*(1-input_a[i]*input_b[i])*2*(1-input_c[i])*input_c[i]);
						return 1;
					}else if(mode==3)
					{
						printf("\nFor a=0.3321, b=0.3321, c=0.3321");
						printf("\nThe switching activity of first AND is: %f", 2*input_a[i]*input_b[i]*(1-input_a[i]*input_b[i]));
						printf("\nThe switching activity of INVERTER is: %f", 2*(1-input_c[i])*input_c[i]);
						printf("\nThe switching activity of ALL circuit is: %f\n", 2*input_a[i]*input_b[i]*(1-input_a[i]*input_b[i])*2*(1-input_c[i])*input_c[i]);
						return 1;
					}
				}
			}
		}
	}
	printf("Test Fail!\n");
	return 0;
}

void readFromFile()
{
	FILE *fp;
	char str[100];
	char path[100];
	char *token;

	printf("\nGive the input path: ");
	fgets(path,100,stdin);

	fp=fopen(path, "r");
	if(fp==NULL)
	{
		printf("Could not open file %s", path);
		return 1;
	}
	while (fgets(str, 100, fp)!=NULL)
	{
		token=strtok(str," ");
		//TELESTHS
		while(token!=NULL)
		{
			printf("%s\n", token);
			token=strtok(NULL," ");
			//ORISMATA
		}
		printf("\n%s\n",str);
	}
	fclose(fp);
	return 1;
}