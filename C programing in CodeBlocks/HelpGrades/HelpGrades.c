#include <stdio.h>
#include <stdlib.h>

int choice;

int main()
{
    printf("\n\n\n\t\tHELP SECTION");
    printf("\n****************************************");
    printf("\n\nPlease choose one of the following options:\n");

    printf("\n1. How to enter student details");
    printf("\n2. How to display all students details");
    printf("\n3. How to use Search options");
    printf("\n4. FAQ");
    printf("\n5. Support");
    printf("\n0. Back to the main program");

    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);

     switch(choice)
    {
        case 1:
            {
            system("cls");
            printf("\n\n\n\n----------How to enter student details---------");
			printf("\n\n\nIn the main menu please enter option 1 and press enter key.\nIn following screen please select number of records you want to create\nEnter department for first student\nEnter name of the student\nEnter the grades for the student\nAverage grade and final grade is calculated aoutomaticly\nAfter creating record(s) go back to main menu by pressing enter");
			printf("\n\n");
			getch();
			system("cls");
			main();
            }
            break;
        case 2:
            {
            system("cls");
            printf("\n\n\n\n----------How to display all students details---------");
			printf("\n\n\nIn the main menu please enter option 2 and press enter key.\nNext screen would display list of all students with relevant student information\nTo go back to main menu press enter");
			printf("\n\n");
			getch();
			system("cls");
			main();
            }
            break;
        case 3:
            {
            system("cls");
            printf("\n\n\n\n----------How to use Search options--------");
			printf("\n\n\nIn the main menu please enter option 2 and press enter key.\nNext screen would display two options for search:\nAfter choosing option 1 you can search for student name\nAfter choosing option 2 you can search for specific department\nAs an additional feture department searched\nwould display averege grade for whole department");
			printf("\n\n");
			getch();
			system("cls");
			main();
            }
            break;
        case 4:
            {
            system("cls");
            printf("\n\n\n\n----------FAQ----------");
			printf("\n\n\n\nWhat will happene if I choose wrong option?");
			printf("\n\nYou will see messega that the option is unaveilable \nand console would ask you to enter your choice again.");
			printf("\n\n\nHow I know that the student details are saved?");
			printf("\n\nYou will see massega at the bottom of the screen telling \nyou how many records were written into the file");
			printf("\n\n");
			getch();
			system("cls");
			main();
            }
            break;
        case 5:
            {
            system("cls");
            printf("\n\n\n\n---------Support---------");
			printf("\n\n\nFor support please contact:");
			printf("\n\nKrzysztof Dziurawiec\nHNC Computing Dep\nNewbury College\ne-mail: Chris-newbury@college.com\nphone: 07540000001");
			printf("\n\n");
			getch();
			system("cls");
			main();
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("your choice is incorect, try again");
            getch();
            system("cls");
			main();                //back to main menu
            break;
    }
    return 0;
}
