#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>


//!!!!!ask how to read last line from the file to update customer numbers correxcctly becouse currently is reading first customer number and incrementing it instead of reading last entry and increment it



//Program write into file car details and reads files
FILE*namefile;
char custnum[15];    //customer name
char reg[7];    // car registration
char lastservice[9];    //last service date
char nextservice[9];    //next service date
char motdate[9];        //MOT date
float servicecost;       //last service cost
float motcost;          //last MOT cost
int number;             //customer number
number=1;


int main()
{
    menu();
    return 0;
}

//main menu function
menu()
{
    int choice;

    printf("**********************************************\n\n");
    printf("          Welcome to Eastleigh Cars           \n\n");
    printf("**********************************************\n\n");
    printf("                Main Menu                     \n\n");
    printf("**********************************************\n\n");
    printf("Please choose one of the following options:\n\n");
    printf("\n1. Create a new set of records");
    printf("\n2. Display all cars details");
    printf("\n3. Look for registration number");
    printf("\n4. Look for customer surname");
    printf("\n0. To exit the program\n\n");
    printf("Enter your choice:");
    scanf("%d",&choice);


    switch(choice)
    {
    case 1:
        {
        system("cls");
        createfile();
        }
        break;
    case 2:
        {
        system("cls");
        readfile();
        }
        break;
    case 3:
        {
        system("cls");
        checkreg();
        }
        break;
    case 4:
        {
        system("cls");
        checkcust();
        }
        break;

    case 0:
        exit(0);
        break;
    default:
        printf("your choice is incorect, try again");
        break;
    }
}

    //function to input data into file;
createfile()
   {
        int j;
        int h;
        int num;

          printf("Enter number of records to be processed:  ");
		  scanf("%d",&num);

// until line 126 code for reading last line from file to get the last customer number written
    int i;
	char *a;        //creating pointers to the file
	char *b;
	char *c;
	char *d;
	char *e;
	float f;
	float g;

	namefile = fopen("CarsMOT.TXT","r");    //readding from the  file
	i=0;

	do
	{
		i=i+1;
		h=fscanf(namefile,"%d",&number);
		a=fscanf(namefile,"%s",custnum);        //creating pointers to the file
		b=fscanf(namefile,"%s",reg);
		c=fscanf(namefile,"%s",lastservice);
		d=fscanf(namefile,"%s",nextservice);
		e=fscanf(namefile,"%s",motdate);
		f=fscanf(namefile,"%f",&servicecost);
		g=fscanf(namefile,"%f",&motcost);


	}while(a!=EOF);
	fclose(namefile);











		  for(j=0;j<num;j++)        //loop for number of records
          {

              number=number+1;
              namefile=fopen("CarsMOT.TXT","a");        //creating file to write

              printf("\n\nEnter customer surname: ");
              scanf("%s",custnum);
              printf("\nEnter car registration: ");         //!!!!forsome reson is writing somtimes twice reg number!!!!
              scanf("%s",reg);
              printf("\nEnter last service date (dd.mm.yy): ");
              scanf("%s",lastservice);
              printf("\nEnter next service date (dd.mm.yy): ");
              scanf("%s",nextservice);
              printf("\nEnter next MOT date (dd.mm.yy): ");
              scanf("%s",motdate);
              printf("\nEnter last service cost: ");
              scanf("%f",&servicecost);
              printf("\nEnter last MOT cost: ");
              scanf("%f",&motcost);


                fprintf(namefile,"%d %s %s %s %s %s %6.2f %6.2f\n",number,custnum,reg,lastservice,nextservice,motdate,servicecost,motcost);

          }
        printf("\n%d Records written to file\n\n",j);
		fclose(namefile);           //remember to close the file
		getch();
		system("cls");
		menu();                 //back to main menu
    }
//reading from the file function
readfile()
{
    int i;
	char *a;        //creating pointers to the file
	char *b;
	char *c;
	char *d;
	char *e;
	float f;
	float g;
	int h;

	namefile = fopen("CarsMOT.TXT","r");    //readding from the  file

	printf("Reading records from the file\n\n");
	i=0;

	do
	{
		i=i+1;
		h=fscanf(namefile,"%d",&number);
		a=fscanf(namefile,"%s",custnum);        //creating pointers to the file
		b=fscanf(namefile,"%s",reg);
		c=fscanf(namefile,"%s",lastservice);
		d=fscanf(namefile,"%s",nextservice);
		e=fscanf(namefile,"%s",motdate);
		f=fscanf(namefile,"%f",&servicecost);
		g=fscanf(namefile,"%f",&motcost);


		if(a!=EOF)
		{
			printf("************************\n");
			printf("Customer number:                %d\n",number);
			printf("Customer surname:               %s\n",custnum);
			printf("Car registration:              \t%s\n",reg);
			printf("Last service date (dd.mm.yy):\t %s\n",lastservice);
			printf("Next service date (dd.mm.yy):\t %s\n",nextservice);
			printf("MOT date (dd.mm.yy):\t\t %s\n",motdate);
			printf("Service cost:\t\t        %6.2f\n",servicecost);
			printf("MOT cost          \t     %6.2f\n",motcost);
			printf("\n");

		}
	}while(a!=EOF);

	printf("\n%d records read from file\n\n",i-1);      //i-1 becouse its reading end of the file as as another record
	getch();
	fclose(namefile);
	system("cls");
	menu();
}

//creating function for finding reg number
checkreg()
{
    int i;
	char *a;        //creating pointers to the file
	char *b;
	char *c;
	char *d;
	char *e;
	float f;
	float g;
	char regsearch[7];
	int found;

	namefile = fopen("CarsMOT.TXT","r");    //reading from the  file

	printf("Enter registration number which you want to find:  \n\n");
	scanf("%s",regsearch);
	i=0;
	found=0;

	do
	{
		i=i+1;
		a=fscanf(namefile,"%s",custnum);        //creating pointers to the file
		b=fscanf(namefile,"%s",reg);
		c=fscanf(namefile,"%s",lastservice);
		d=fscanf(namefile,"%s",nextservice);
		e=fscanf(namefile,"%s",motdate);
		f=fscanf(namefile,"%f",&servicecost);
		g=fscanf(namefile,"%f",&motcost);


		if(a!=EOF)
		{
		    if(strcmp(reg,regsearch)==0)
            {

            found=found+1;
			printf("************************\n");
			printf("Customer surname:             \t%s\n",custnum);
			printf("Car registration:            \t%s\n",reg);
			printf("Last service date (dd.mm.yy):\t %s\n",lastservice);
			printf("Next service date (dd.mm.yy):\t %s\n",nextservice);
			printf("MOT date (dd.mm.yy):\t\t %s\n",motdate);
			printf("Service cost:\t        %6.2f\n",servicecost);
			printf("MOT cost     \t     %6.2f\n",motcost);
			printf("\n");
            }

		}
	}while(a!=EOF);

    printf("\n%d records found",found);
	printf("\n%d records read from file\n\n",i-1);      //i-1 becouse its reading end of the file as as another record
	getch();
	fclose(namefile);
	system("cls");
	menu();
}

//function looking for customer
checkcust()
{
    int i;
	char *a;        //creating pointers to the file
	char *b;
	char *c;
	char *d;
	char *e;
	float f;
	float g;
	char surname[15];
	int found;

	namefile = fopen("CarsMOT.TXT","r");    //reading from the  file

	printf("Enter customer surname which you want to find:  \n\n");
	scanf("%s",surname);
	i=0;
	found=0;

	do
	{
		i=i+1;
		a=fscanf(namefile,"%s",custnum);        //creating pointers to the file
		b=fscanf(namefile,"%s",reg);
		c=fscanf(namefile,"%s",lastservice);
		d=fscanf(namefile,"%s",nextservice);
		e=fscanf(namefile,"%s",motdate);
		f=fscanf(namefile,"%f",&servicecost);
		g=fscanf(namefile,"%f",&motcost);


		if(a!=EOF)
		{
		    if(strcmp(custnum,surname)==0)
            {

            found=found+1;
			printf("************************\n");
			printf("Customer surname:             \t%s\n",custnum);
			printf("Car registration:            \t%s\n",reg);
			printf("Last service date (dd.mm.yy):\t %s\n",lastservice);
			printf("Next service date (dd.mm.yy):\t %s\n",nextservice);
			printf("MOT date (dd.mm.yy):\t\t %s\n",motdate);
			printf("Service cost:\t        %6.2f\n",servicecost);
			printf("MOT cost     \t     %6.2f\n",motcost);
			printf("\n");
            }

		}
	}while(a!=EOF);

    printf("\n%d records found",found);
	printf("\n%d records read from file\n\n",i-1);      //i-1 becouse its reading end of the file as as another record
	getch();
	fclose(namefile);
	system("cls");
	menu();
}

