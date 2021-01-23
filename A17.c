//COMPUTER PROJECT
//E-BUS TICKET RESERVATION
/*INCLUDING HEADER CLASSES*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
/*STRUCTURE TO INPUT DETAILS OF THE PASSENGERS*/
struct bus
{
char busnumber[20];
char name[50];
char pname[50];
float amount;
char destination[20];
char source[20];
char departuretime[10];
char arrivaltime[11];
char seat[10];
int i;
}s;



/*CALLING ALL THE FUNCTIONS*/

void bookticket();
void listofticket();
void updateticket();
void searchticket();
void cancelticket();
char get;


/*MAIN*/
int main()
{ 
 char choice;
 int i;
 while (1)
 {
 	printf("\n\n\n\n\n\n\n\n\n\t\t\t##############################################################");
 printf("\n\t\t\t  -------------WELCOME TO BUS RESESRVATION SYSTEM-----------");
 printf("\n\t\t\t----------made by:-yatish khandelwal  ---------------------");
 printf("\n\t\t\t----------roll no.:-A17  ----------------------------------");
 printf("\n\t\t\t##############################################################");
 printf("\n\n\n\t\t\tBus Number for:-\n\t\t\tDELHI TO JAIPUR-1\n\t\t\tJAIPUR TO DELHI-2\n\t\t\tAMRITSAR TO JAMMU-3\n\t\t\tGOA TO CHENNAI-4\n\t\t\tMUMBAI TO AHMEDABAD-5");
  printf("\n\n\t\t\t\t Enter your choice:-\n\n\t\t\t\t C : Book a Ticket");
  printf("\n\t\t\t\t D : List of Tickets");
  printf("\n\t\t\t\t E : Search Ticket");
  printf("\n\t\t\t\t F : Update Ticket");
  printf("\n\t\t\t\t G : Delete Ticket");
  printf("\n\t\t\t\t H : Exit");
  printf("\n\n\t\t\t\t\t");
  choice=getche();
  choice=toupper(choice);
  switch(choice)
  {
    case 'C': 
    bookticket();break;
    case 'D':
    listofticket();break;
    case 'E':
    searchticket();break;
    case 'F':
    updateticket();break;
    case 'G':
    cancelticket();break;
    case 'H':
    system("cls");
    printf("\n\n\t\t     THANK YOU");
    printf("\n\n\t\tFOR USING OUR BUS SERVICE");
    exit(0);
    break;
   default:
    system("cls");
    printf("WRONG INPUT");
    printf("\nAny key to continue");
    getch();
    system("cls");
  }
 }
}



/*FUNCTION TO BBOK TICKET*/
void bookticket()
{	char busnumber[20];
 FILE *f;

 f=fopen("ticket.txt","a+");
  system("cls");
 bus:
  printf("\n Enter Bus number:");
  scanf("%s",&s.busnumber);
  printf("\n Enter Passenger Name:");
  fflush(stdin);
  scanf("%s",&s.pname);
  printf("\n Enter your mobile number:");
  scanf("%s",&s.name);
  printf("\n Enter Source:");
  scanf("%s",&s.source);
  printf("\n Enter Destination:");
  scanf("%s",&s.destination);
  printf("\n Seat to be Alloted:");
  scanf("%s",s.seat);
  fwrite(&s,sizeof(s),1,f);
  fflush(stdin);
  printf("\n Ticket Successfully Booked");
  system("pause");
 fclose(f);
 system("cls");
}



/*FUNCTION TO DISPLAY LIST OF TICKET*/
void listofticket()
{
 FILE *f;
 FILE *n;
 int i;
 if((f=fopen("ticket.txt","r"))==NULL)
  exit(0);
 system("cls");
 n=fopen("display.txt","r");
 printf("Bus Number\tPassenger Name\tMobile number\tSource\t\tDestination\tAlloted Seat\tFare\n");
 for(i=0;i<100;i++)
  printf("-");
 while(fread(&s,sizeof(s),1,f)==1)
 {	
  printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tRs %.2f/-",s.busnumber,s.pname,s.name,s.source,s.destination,s.seat,atof(s.busnumber)*1000);
 }
 printf("\n");
 for(i=0;i<100;i++)
  printf("-");
fclose(n);
fclose(f);
getch();
system("cls");
}



/*FUNCTION TO SEARCH A BOOKED TICKET*/
void searchticket()
{
 FILE *f;
 char pname[20];
 int flag=1;
 int i;
 f=fopen("ticket.txt","r+");
 if(f==0)
  exit(0);
 fflush(stdin);
 system("cls");
 printf("Enter Passenger name to search in our database\n");
 scanf("%s",&pname);
 while(fread(&s,sizeof(s),1,f)==1)
 {
  if(stricmp(s.pname,pname)==0)
  { system("cls");
   printf(" Record Found ");
   printf("\n");
 for(i=0;i<100;i++)
  printf("-");
  printf("\nBus Number\tPassenger Name\tMobile number\tSource\t\tDestination\tAlloted Seat\tFare\n");
    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tRs %.2f/-\n",s.busnumber,s.pname,s.name,s.source,s.destination,s.seat,atof(s.busnumber)*1000);
   flag=0;
 for(i=0;i<100;i++)
  printf("-");
  break;
  }
  else if(flag==1)
  { system("cls");
   printf("Requested Ticket Not found in our database");
  }
 }
 getch();
 fclose(f);
 system("cls");
}



/*FUNCTION TO UPDATE TICKET*/
void updateticket()
{
 FILE *f;
 
 char pname[20];
 long int size=sizeof(s);
 if((f=fopen("ticket.txt","r+"))==NULL)
  exit(0);
 system("cls");
 printf("Enter Passenger name to modify:\n");
 scanf("%s",&pname);
 fflush(stdin);
 while(fread(&s,sizeof(s),1,f)==1)
 {
  if(stricmp(s.pname,pname)==0)
  {
   system("cls");
   printf("\n Enter bus number:");
   scanf("%s",&s.busnumber);
   printf("\n Enter Passenger name: ");
   fflush(stdin);
   scanf("%s",&s.pname);
   printf("\n Enter your mobile number:");
  scanf("%s",&s.name);
   printf("\n Enter Source:");
  scanf("%s",&s.source);
  printf("\n Enter Destination:");
  scanf("%s",s.destination);
  printf("\n Enter seat number:-");
  scanf("%s",s.seat);
   fseek(f,-size,SEEK_CUR);
   fwrite(&s,sizeof(s),1,f);
   break;
  }
  else
  {
  	printf("\nRequested Ticket Not found in our database");
  	break;
  }
 }
 fclose(f);
 system("cls");
}



/*FUNCTION TO CANCELL A BOOKED TICKET*/
void cancelticket()
{
	FILE *f;
	FILE *p;
    char pname[50];
    int found=0;
    p=fopen("ticket.txt","r");
    f=fopen("temp.txt","w+");
    system("cls");
    printf("\nEnter Passenger name to be deleted:");
    scanf("%s",&pname);
    rewind(p);
    while(fread(&s,sizeof(s),1,p)!=0)
    {
    	if(stricmp(s.pname,pname)!=0)
    	{
    		fwrite(&s,sizeof(s),1,f);
    	}
    }
    printf("\nTICKET DELETED");
	fclose(p);
	fclose(f);
	remove("ticket.txt");
	rename("temp.txt","ticket.txt");
	getch();
	system("cls");
}
