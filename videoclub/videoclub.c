#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

char adat[20],acust[20], atitle[20];
float acost;


void write()
{
	FILE *fp;
	char dat[20];
	char custname[20];
	char title[20];
	float cost;
	
	printf("\nEnter Date :: ");
	scanf("%s",&dat);
	printf("\nEnter Name of Customer :: ");
	scanf("%s",&custname);
	printf("\nEnter title of movie :: ");
	scanf("%s",&title);	
	printf("\nEnter Cost of Rent :: ");
	scanf("%f",&cost);
	
	fp=fopen("Record.txt", "a");
	
	fprintf(fp,"\n%s %s %s %.2f", dat, custname, title, cost);
	printf("\n          RECORD WRITTEN SUCCESSFULLY!!");
	fclose(fp);
}

void display(char da[])
{
	FILE *fp;
	int res;
	int check=0;
	
	fp=fopen("record.txt","r");
	printf("On %s we have the following rentals:\n\n ",da);
	while(fscanf(fp,"%s %s %s %f\n", adat,acust,atitle,&acost)!=EOF)
	{
		res=strcmp(adat,da);
		if(res==0)
		{
			printf("\n - %s",acust);
			printf("    %s",atitle);
			printf("    %.2f",acost);
			check=1;
		}

	}
	if(check==0)
	{
		printf("No rentals on %s", da);
	}
}

int main(void)
{
	char choice;
	char lm[20];
	do{
	printf("\n ************** VIDEO CLUB **************\n");
	printf("\n Press <1> to create an entry");
	printf("\n Press <2> to to display on specific date");
	printf("\n Press <0> to exit\n");
	printf("\n Your selection is: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:write();
		break;
		
		case 2:printf("\nENTER DATE::");
			scanf("%s", &lm);
			display(lm);
			break;
		
		case 0:exit(0);
		default:printf("\nInalid selection");
	}
		getch();
	}while(choice!=0);

	return(0);
}
	
