#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
//#include<iostream.h>

// program developed by Krzysztof Dziurawiec
// for HNC programing in C module
// date: 23/06/2015


//Program which is saving to the file up to 25 students and grades and is returning average grade

FILE*namefile;
FILE*printer;
char student[25][20];	//array of students
char group[25][10];     //array of student groups
int grade[25][3];		//array of student grades
char address1[25][30];   //first line of address
char address2[25][30];  //second line of address
char postcode[25][20];  //postcode
char phone[25][15];     //phone number
int choice;         //menu choice option
int i,j,k;			//counters
float tot;		    //total of grades
float ave[25];		//array of average of grades
int number;         //student number
number=0;


main()
{

menu();
return(0);

}

menu()
{
    char ch;
    printf("\n************************************");
    printf("\n*Developed by: Krzysztof Dziurawiec*");
    printf("\n*For: HNC programing in C module   *");
    printf("\n*Date: 23/06/2015                  *");
    printf("\n************************************\n\n");
    printf("\n\n\n\t\tSTUDENT GRADES");
    printf("\n\n\t\t   Main Menu");
    printf("\n****************************************");
    printf("\n\nPlease choose one of the following options:\n");

    printf("\n1. Enter student contact details");
    printf("\n2. Enter student grades");
    printf("\n3. Display all students grades");
    printf("\n4. Search options");
    printf("\n5. Help");
    printf("\n0. Exit the program");

    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
//-------------------------------switch case for main menu------------------------------------------
    switch(choice)
    {
        case 1:
            {
            system("cls");
            contact();
            }
            break;
        case 2:
            {
            system("cls");
            createfile();
            }
            break;
        case 3:
            {
            system("cls");
            readfile();
            }
            break;
        case 4:
            {
            system("cls");
            searchmenu();
            }
            break;
        case 5:
            {
            system("cls");
            system("HelpGrades.exe");
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("your choice is incorect, try again");
            getch();
            system("cls");
            menu();                 //back to main menu
            break;
    }
}

searchmenu()
{
    printf("SEARCH OPTIONS");
    printf("\n****************************************");
    printf("\n1. Search for student contact details");
    printf("\n2. Search for student grades");
    printf("\n3. Search for department");
    printf("\n0. Main menu");
        printf("\n\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            {
            system("cls");
            checkcontact();
            }
            break;
        case 2:
            {
            system("cls");
            checkstudent();
            }
            break;
        case 3:
            {
            system("cls");
            checkdep();
            }
            break;
        case 0:
            {
            system("cls");
            menu();
            }
            break;
    }
}

///----------------------------------creating file function-------------------------------------------------------------------------
createfile()
{
    int num;
    char ans[3];
    printf("ENTERING STUDENT GRADES");
    printf("\n****************************************");
    printf("\n\nEnter number of records to be processed:  ");
    scanf("%d",&num);
//--------------------------reading file for last student number--------------------------------------------------------------
    int k,h;        //counters
	char *a;        //creating pointers to the file
	char *b;
	int c1,c2,c3,z;
	float d;
	//------------------------creating new variables for the pointers-------------------------------------------------
	int innumber;
	int grade1[3];
	float inave;

	namefile = fopen("Students.TXT","r");    //reading from the  file
	k=0;
    //--------------------------------------reading from the file and printing on the screen---------------------------
	do
	{
	    k=k+1;
	    z=fscanf(namefile,"%d",&innumber);
		a=fscanf(namefile,"%s",group);        //creating pointers to the file
		b=fscanf(namefile,"%s",student);
		c1=fscanf(namefile,"%d",&grade1[0]);
		c2=fscanf(namefile,"%d",&grade1[1]);
		c3=fscanf(namefile,"%d",&grade1[2]);
		d=fscanf(namefile,"%f",&inave);

	}while(a!=EOF);
    number=innumber;
    fclose(namefile);           //closing file

//--------------------------opening file and writing into the file------------------------------------------------------------------
    namefile=fopen("Students.TXT","a");         //creating file to write

	for(j=0;j<num;j++)
	{
        number=number+1;                        //counting number of students

        printf("\n\nPlease enter student group: ");
        scanf("%s",group[j]);
        group[j][0]=toupper(group[j][0]);   //changing first charackter to uppercase
		printf("\nPlease enter student name: ");
        scanf("%s",student[j]);
        student[j][0]=toupper(student[j][0]);
        printf("\nPlease enter grades from 0 to 100");
		tot=0;

            for(i=0;i<3;i++)        // loop for entering 3 grades
            {

                printf("\nEnter the grade %d = ",i+1);
                scanf("%d",&grade[j][i]);
                tot=tot+grade[j][i];

            }
        ave[j]=tot/i;       //calculating average of grades
        printf("\n****************************************");
        //--------------------------writing into the file----------------------------------------------------
        fprintf(namefile,"%d %s %s %d %d %d %6.2f\n",number,group[j],student[j],grade[j][0],grade[j][1],grade[j][2],ave[j]);
        //-------------------------printing student slip-----------------------------------------------------
        printf("\n\nWould you like to print grade slip? y/n: ");
        scanf("%s",ans);
            if((strcmp(ans,"y")==0)||(strcmp(ans,"Y")==0))
            {
                printf("\nprinting...");
                printing();
            }

	}

	printf("\n%d Records written to file\n\n",j);
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu
}
///----------------------------------reading from the file function------------------------------------------------------------
readfile()
{
    int k,h;        //counters
	char *a;        //creating pointers to the file
	char *b;
	int c1,c2,c3,z;
	float d;
	//------------------------creating new variables for the pointers-------------------------------------------------
	int innumber;
	int grade1[3];
	float inave;

	namefile = fopen("Students.TXT","r");    //reading from the  file

    printf("DISPLAYING ALL STUDENTS DETAILS");
    printf("\n*********************************\n");
	printf("Reading records from the file\n\n");
	k=0;
    //--------------------------------------reading from the file and printing on the screen---------------------------
	do
	{
	    k=k+1;
	    z=fscanf(namefile,"%d",&innumber);
		a=fscanf(namefile,"%s",group);        //creating pointers to the file
		b=fscanf(namefile,"%s",student);
		c1=fscanf(namefile,"%d",&grade1[0]);
		c2=fscanf(namefile,"%d",&grade1[1]);
		c3=fscanf(namefile,"%d",&grade1[2]);
		d=fscanf(namefile,"%f",&inave);

		if(a!=EOF)
		{
			printf("*********************************\n");
			printf("\n---------------------------------");
			printf("\nDepartment: \t\t%s\n",group);
			printf("Student number: \t%d\n",innumber);
			printf("Student name: \t\t%s\n",student);
			printf("\n---------------------------------");
                for(h=0;h<3;h++)
                    {
                        printf("\nGrade %d: \t\t%d%%\n",(h+1),grade1[h]);
                    }
			printf("\nAverage Grade:  \t%6.2f%%\n",inave);
			printf("\n---------------------------------");
//--------------------------------calculating final grade------------------------------------------------------------------------
        if ((inave>=40) && (inave<=63))
                printf("\nFinal mark: \t\tPASS");
            else if ((inave>63) && (inave<=80))
                printf("\nFinal mark: \t\tMERIT");
            else if (inave>80)
                printf("\nFinal mark: \t\tDISTINCTION");
            else
                printf("\nFinal mark: \t\tFail");
            printf("\n---------------------------------");
			printf("\n\n\n");

		}
	}while(a!=EOF);
    printf("Number of records read from the file: %d",k-1);
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu

}

///----------------------------------looking up for students function--------------------------------------------------------------------
checkstudent()
{
    int k,h;        //counters
	char *a;        //creating pointers to the file
	char *b;
	int c1,c2,c3,z;
	float d;
	//------------------------creating new variables for the pointers-------------------------------------------------
	char checkstu[20];
	int innumber;
	int grade1[3];
	float inave;
	char found;

	namefile = fopen("Students.TXT","r");    //reading from the  file

    printf("STUDENT SEARCH");
    printf("\n*********************************\n");
	printf("Please enter the name of student: ");
	scanf("%s",checkstu);
	checkstu[0]=toupper(checkstu[0]);   //changing first charackter to uppercase
	k=0;
	found=0;
    //--------------------------------------reading from the file and printing on the screen---------------------------
	do
	{
	    k=k+1;
	    z=fscanf(namefile,"%d",&innumber);
		a=fscanf(namefile,"%s",group);        //creating pointers to the file
		b=fscanf(namefile,"%s",student);
		c1=fscanf(namefile,"%d",&grade1[0]);
		c2=fscanf(namefile,"%d",&grade1[1]);
		c3=fscanf(namefile,"%d",&grade1[2]);
		d=fscanf(namefile,"%f",&inave);

		if(b!=EOF)
		{
		    if(strcmp(student,checkstu)==0)

               {
                    found=found+1;
                    printf("*********************************\n");
                    printf("\n---------------------------------");
                    printf("\nDepartment: \t\t%s\n",group);
                    printf("Student number: \t%d\n",innumber);
                    printf("Student name: \t\t%s\n",student);
                    printf("\n---------------------------------");
                        for(h=0;h<3;h++)
                            {
                                printf("\nGrade %d: \t\t%d%%\n",(h+1),grade1[h]);
                            }
                    printf("\nAverage Grade:  \t%6.2f%%\n",inave);
                    printf("\n---------------------------------");
        //--------------------------------calculating final grade------------------------------------------------------------------------
                            if ((inave>=40) && (inave<=63))
                                    printf("\nFinal mark: \t\tPASS");
                                else if ((inave>63) && (inave<=80))
                                    printf("\nFinal mark: \t\tMERIT");
                                else if (inave>80)
                                    printf("\nFinal mark: \t\tDISTINCTION");
                                else
                                    printf("\nFinal mark: \t\tFail");
                                    printf("\n---------------------------------");
                                    printf("\n\n\n");
               }
		}
	}while(b!=EOF);
    printf("Number of records read from the file: %d",(found));
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu

}

///----------------------------------looking up for department--------------------------------------------------------------
checkdep()
{
    int k,h;        //counters
	char *a;        //creating pointers to the file
	char *b;
	int c1,c2,c3,z;
	float d;
	//------------------------creating new variables for the pointers-------------------------------------------------
	char dep[10];
	int innumber;
	int grade1[3];
	float inave;
	char found;
	float avedep;   //adding average
	float totave;   //calculating average for department

	namefile = fopen("Students.TXT","r");    //reading from the  file

    printf("DEPARTMENT SEARCH");
    printf("\n*********************************\n");
	printf("Please enter the name of department: ");
	scanf("%s",dep);
	dep[0]=toupper(dep[0]);
	k=0;
	found=0;
	avedep=0;
	totave=0;
    //--------------------------------------reading from the file and printing on the screen---------------------------
	do
	{
	    k=k+1;
	    z=fscanf(namefile,"%d",&innumber);
		a=fscanf(namefile,"%s",group);        //creating pointers to the file
		b=fscanf(namefile,"%s",student);
		c1=fscanf(namefile,"%d",&grade1[0]);
		c2=fscanf(namefile,"%d",&grade1[1]);
		c3=fscanf(namefile,"%d",&grade1[2]);
		d=fscanf(namefile,"%f",&inave);

		if(a!=EOF)
		{
		    if(strcmp(group,dep)==0)

               {
                    found=found+1;
                    printf("*********************************\n");
                    printf("\n---------------------------------");
                    printf("\nDepartment: \t\t%s\n",group);
                    printf("Student number: \t%d\n",innumber);
                    printf("Student name: \t\t%s\n",student);
                    printf("\n---------------------------------");
                        for(h=0;h<3;h++)
                            {
                                printf("\nGrade %d: \t\t%d%%\n",(h+1),grade1[h]);
                            }
                    printf("\nAverage Grade:  \t%6.2f%%\n",inave);
                    printf("\n---------------------------------");
                    avedep=avedep+inave;
        //--------------------------------calculating final grade------------------------------------------------------------------------
                            if ((inave>=40) && (inave<=63))
                                    printf("\nFinal mark: \t\tPASS");
                                else if ((inave>63) && (inave<=80))
                                    printf("\nFinal mark: \t\tMERIT");
                                else if (inave>80)
                                    printf("\nFinal mark: \t\tDISTINCTION");
                                else
                                    printf("\nFinal mark: \t\tFail");
                                printf("\n---------------------------------");
                                printf("\n\n\n");
               }
		}
	}while(a!=EOF);
	totave=avedep/found;
	printf("The average grade for this department is: %6.2f%%",totave);
	printf("\n---------------------------------");
    printf("\nNumber of records read from the file: %d",(found));
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu

}
///----------------------------------creating student contact details--------------------------------------------------------------
contact()
{
    int num;
    printf("ENTERING STUDENT CONTACT DETAILS");
    printf("\n****************************************");
    printf("\n\nEnter number of records to be processed:  ");
    scanf("%d",&num);
    namefile=fopen("Addresses.TXT","a");         //creating file to write

	for(j=0;j<num;j++)
	{
        number=number+1;                        //counting number of students

        printf("\n\nPlease enter student name: ");
        scanf("%s",student[j]);
        student[j][0]=toupper(student[j][0]);
		printf("\nPlease enter student address: \n\n");
		printf("Please use underscore instead of space bar to input data example: 21_Newtown_Rd\n\n");
		printf("\nHouse number and street name: ");
        scanf("%s",address1[j]);
        address1[j][0]=toupper(address1[j][0]);
        printf("\nTown name: ");
        scanf("%s",address2[j]);
        address2[j][0]=toupper(address2[j][0]);
        printf("\nPost Code: ");
        scanf("%s",postcode[j]);
        printf("\nPhone number: ");
        scanf("%s",phone[j]);
        printf("\n****************************************");
        //--------------------------writing into the file----------------------------------------------------
        fprintf(namefile,"%s %s %s %s %s\n",student[j],address1[j],address2[j],postcode[j],phone[j]);
	}

	printf("\n%d Records written to file\n\n",j);
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu
}
///----------------------------------looking up for student contact details--------------------------------------------------------------
checkcontact()
{
    char checkstudent[20];
	char inaddress1[30];
	char inaddress2[20];
	char inpostcode[20];
	char inphone[20];
	int k;
	int found;
	char *a;//pointers
	char *b;
	char *c;
	char *d;
	char *e;




	namefile = fopen("Addresses.TXT","r");    //reading from the  file

    printf("STUDENT CONTACT DETAILS SEARCH");
    printf("\n*********************************\n");
	printf("Please enter the name of student: ");
	scanf("%s",checkstudent);
	checkstudent[0]=toupper(checkstudent[0]);   //changing first charackter to uppercase
	k=0;
	found=0;

    //--------------------------------------reading from the file and printing on the screen---------------------------
	do
	{
	    k=k+1;
	    a=fscanf(namefile,"%s",student);
		b=fscanf(namefile,"%s",inaddress1);        //creating pointers to the file
		c=fscanf(namefile,"%s",inaddress2);
		d=fscanf(namefile,"%s",inpostcode);
		e=fscanf(namefile,"%s",inphone);

		if(a!=EOF)
		{
		    if(strcmp(student,checkstudent)==0)

               {
                    found=found+1;
                    printf("*********************************\n");
                    printf("\n---------------------------------");
                    printf("\nStudent name: \t\t%s\n",checkstudent);
                    printf("Student address:\n");
                    printf("\t\t%s\n",inaddress1);
                    printf("\t\t%s\n",inaddress2);
                    printf("\t\t%s\n",inpostcode);
                    printf("\t\t%s\n",inphone);
                    printf("\n---------------------------------");

               }
		}
	}while(a!=EOF);
	printf("\n---------------------------------");
    printf("\nNumber of records read from the file: %d",(found));
    fclose(namefile);           //closing file
    getch();                     //waiting for user
    system("cls");              //clearing screen
    menu();                 //back to main menu

}
printing()
{
    printer=fopen("//SWD\PRINTENUM\{60F2452C-D297-4524-BB17-4508E978AE55}","w");
    fprintf(printer,"------- %s's Grade Slip -------",student[j]);
    fprintf(printer,"\nDepartment: \t\t%s\n",group[j]);
    fprintf(printer,"Student number: \t%d\n",number);
    fprintf(printer,"Student name: \t\t%s\n",student[j]);
    fprintf(printer,"\n---------------------------------");
    fprintf(printer,"\nGrade %d: \t\t%d%%\n",grade[j][0]);
    fprintf(printer,"\nGrade %d: \t\t%d%%\n",grade[j][1]);
    fprintf(printer,"\nGrade %d: \t\t%d%%\n",grade[j][2]);
    fprintf(printer,"\nAverage Grade:  \t%6.2f%%\n",ave[j]);
    fprintf(printer,"\n---------------------------------");
            if ((ave>=40) && (ave<=63))
                fprintf(printer,"\nFinal mark: \t\tPASS");
            else if ((ave>63) && (ave<=80))
                fprintf(printer,"\nFinal mark: \t\tMERIT");
            else if (ave>80)
                fprintf(printer,"\nFinal mark: \t\tDISTINCTION");
            else
                fprintf(printer,"\nFinal mark: \t\tFail");
    fprintf(printer,"\n---------------------------------");
    printf("\n\nYour grade slip is printed.\n\n");

}
