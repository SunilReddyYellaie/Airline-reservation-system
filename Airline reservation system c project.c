#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h>
#include<string.h>
#include<Windows.h>

struct SRMAP_airline
{
	char passport[10];
	char name[20];
	int seat_num;
	char email[25];
	struct SRMAP_airline*following;
}

*begin,*stream;
struct SRMAP_airline*dummy;

void main()
{
	void reserve(int x),cancel(),display(),savefile();
	int choice;
    begin=stream=NULL;
    int num=1;
    do
    {
    	system("cls");
    	system("color B1");
    	printf("\n\n\t\t********************************************************************");
		printf("\n\t\t Welcome to SRMAP's Airline System ");
		printf("\n\n\t\t********************************************************************");
		printf("\n\n\t\t1.Reservation");
		printf("\n\n\t\t2.Cancel");
		printf("\n\n\t\t3.DISPLAY RECORDS");
		printf("\n\n\t\t4.EXIT");
		printf("\n\n\t\tChoose your option from 1 to 4:- ");
	    scanf("  %d",&choice);fflush(stdin);
		system("cls");
		switch(choice)
		{
			case 1:
				{
					reserve(num);
					num++;
					break;
				}
			case 2:
				{
					cancel();
					break;
			    }
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					savefile();
					break;
				}
			default:
				printf("\n\n\tSORRY INVALID CHOICE!");
				printf("\n\n\tPLEASE CHOOSE FROM 1-4");
		}
		getch();
	}while(choice!=4);				
}
void details()
{
	printf("\n\tEnter your passport number:");
	gets(stream->passport);fflush(stdin);
	printf("\n\tEnter your name:");
	gets(stream->name);fflush(stdin);
	printf("\n\tEnter your email address:");
	gets(stream->email);fflush(stdin);

}
//************************************srmap airlines************************************
void details();
void reserve(int x)
{
	system("color 75");
	stream=begin;
	if (begin==NULL)
	{
		//first user
		begin=stream=(struct SRMAP_airline*)malloc(sizeof(struct SRMAP_airline));
		details();
		stream->following=NULL;
		printf("\n\tSeat booking successful!");
		printf("\n\tyour seat number is:SeatA-%d",x);
		stream->seat_num=x;
		return;
	}
	else if(x>15)//FULLSEATS
	{
		printf("\n\t\tSeatFull.");
		return ;
    }
	else
	{
		//nextuser
		while(stream->following)
			stream=stream->following;
		stream->following=(struct SRMAP_airline*)malloc(sizeof(struct SRMAP_airline));
		stream=stream->following;
		details();	
		stream->following=NULL;
		printf("\n\tSeat booking succesful!");
		printf("\n\tyour seat number is:SeatA-%d",x);
		stream->seat_num=x;
		return;
	}
}
//************************srmap airlines********************************
void savefile()
{
	system("color C0");
	FILE*fpointer=fopen("SRMAPrecords","w");
	if(!fpointer)
	{
		printf("\nError in opening file!");
		return;
		Sleep(800);
	}
	stream=begin;
	while(stream)
	{
		fprintf(fpointer,"%-6s",stream->passport);
		fprintf(fpointer,"%-15s",stream->name);
		fprintf(fpointer,"%-15s",stream->email);
		stream=stream->following;
	}
	printf("\n\n\n\n\n\n\t\t\tDetails have been saved to a file");//SRMAP RECORDS
	printf("\n\n\n\t\t\tTHANKS FOR VISITING US :)");
	fclose(fpointer);
}
//********************************srm ap airlines***************************************

void display()
{
	system("color F4");
	stream=begin;
	while(stream)
	{
		printf("\n\n\nPassport Number:%-5s",stream->passport);
		printf("\n name:%-15s",stream->name);
		printf("\n email address:%-15s",stream->email);
		printf("\n Seat Number:A-%d",stream->seat_num);
		printf("\n\n++*=====================================================*++");
		stream=stream->following;
	}
}
//*****************************srmap airlines*************************************

void cancel()
{
	system("color E6");
	stream=begin;
	system("cls");
	char passport[6];
	printf("\n\nEnter passort number followed by name to delete record?:");
    gets(passport);fflush(stdin);
	if(strcmp(begin->passport,passport)==0)
	{
		dummy=begin;
		begin=begin->following;
		free(dummy); 
		printf("booking has been deleted");
		Sleep(800);
		return;
   }
	while(stream->following) 
	{
		
		if(strcmp(stream->following->passport,passport)==0)
		{
			dummy=stream->following;
			stream->following=stream->following->following;
			free(dummy);
			printf("has been deleted");
			getch();
			Sleep(800);
			return;
		}	
		stream=stream->following;
	}
	printf("passport number is wrong please check your passport");
}
//************************************srmap airlines**********************************
