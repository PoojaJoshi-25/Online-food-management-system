#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#define MAX_YR  2022
#define MIN_YR  1980
void returnfunc(void);

void mainmenu(void);

void administration(void);
void customer(void);

void addrecord(void);
void deleterecord(void);
void searchrecord(void);
void viewrecord(void);

void vegetarian(void);
void nonvegetarian(void);
void details(void);
void aboutus(void);

int getdata();

struct employee
{

	char name[30];
	int id;
	char DOB[10];
	int dd; int mm; int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];
	
	int quantity;
};
struct employee e;

FILE *fp,*ft,*dp,*dt;

int s;
char findrecord;
int again;
int quantity;
double total=0;
int t;
int id=102;
int main()
{
	mainmenu();
	return 0;
}


void mainmenu(void)
{
	system("cls");
	printf("                                 **********\n");
	printf("                                                            \n");
	printf("                             WELCOME TO ONLINE FOOD ORDER SYSTEM\n");
	printf("                                                             \n");
	printf("                                 **********\n\n\n");

	printf("*FEELING HUNGRY ? CALL OR WALK IN FOODIE GOODIE KITCHEN***\n\n");
	printf("          1. ADMINISTRATION SECTION--> \n\n          2. CUSTOMER SECTION--> \n\n          3. ABOUT US--> \n\n          4. Exit--> \n\n\n             Enter Your Choice --->");
	char choice[10];
	int i=0,flag2=0;
		gets(choice);
		while(choice[i]!='\0')
		{
			if (((choice[i]>='0')&&(choice[i]<='9')))
			{
				i++;
			}
			else
			{
				printf("                          \nInavalid Input\n");
				int wait;
				printf("In progress :");
				for(wait=0;wait<=10000;wait++)
				{
					printf("\rIn progress : %d",wait/100);
				}
				flag2=1;
				break;
			}
		}
		if(flag2==1)
		{
			mainmenu();
		}
		int number = 0; 
		i=0;
    	while(choice[i]!='\0') { 
        
			int tmp=choice[i]-'0'; 
			number = number*10+tmp; 
			i++;
    } 
	int choice1=number;
	if(choice1==1)
	{
		administration();
	}
	else if(choice1==2)
	{
		customer();
	}
	else if(choice1==3)
	{
		aboutus();
	}
	else if(choice1==4)
	{
		system("cls");
		printf("\n\n\n");
		printf("***THANK YOU****\n");
		exit(0);
	}
	else
	{
		printf("Invalid Choice\n\n");
		int wait;
				printf("In progress :");
				for(wait=0;wait<=10000;wait++)
				{
					printf("\rIn progress : %d",wait/100);
				}
				printf("\n\n");
				system("cls");
				mainmenu();
	}
}

void administration(void)
{
	system("cls");
	printf("****WELCOME TO THE EMPLOYEE SECTION******\n\n");
	printf("          1. Add New Record\n\n          2. Search Record\n\n          3. Delete Record\n\n          4. View THe Records\n\n          5. View previous orders placed\n\n          6. Back To Main Menu \n\n             Enter Your Choice --->");
	char choice[10];
	int i=0,flag2=0;
	gets(choice);
	while(choice[i]!='\0')
	{
		if (((choice[i]>='0')&&(choice[i]<='9')))
		{
			i++;
		}
		else
		{
			printf("                          \nInavalid Input\n");
			int wait;
			printf("In progress :");
			for(wait=0;wait<=10000;wait++)
			{
				printf("\rIn progress : %d",wait/100);
			}
			flag2=1;
			break;

		}
	}
	if(flag2==1)
	{
		administration();
	}
	int number = 0; 
	i=0;
    while(choice[i]!='\0') { 
        
        int tmp=choice[i]-'0'; 
        number = number*10+tmp; 
		i++;
    } 
	int n=number;
	int wait;
	printf("In progress :");
	for(wait=0;wait<=10000;wait++)
	{
		printf("\rIn progress : %d",wait/100);
	}
	printf("\n\n");
	if(n==1)
	{
		addrecord();
	}
	else if(n==2)
	{
		searchrecord();
	}
	else if(n==3)
	{
		deleterecord();
	}
	else if(n==4)
	{
		viewrecord();
	}
		else if(n==5)
	{
		FILE *view;
		char viw;
		view = fopen("order.txt","r");
		while((viw=fgetc(view))!=EOF)
		{
			printf("%c",viw);
		}
		fclose(view);
	}
	else if(n==6)
	{
		
		system("cls");
		mainmenu();
	}
	else
	{
		printf("                   Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		administration();
	}
	
}

void addrecord(void)
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Save any more?(Y / N): ");
		if(getch()=='N')
	    {
	    	administration();
	    }
		else
		{
	    	system("cls");
	    	addrecord();
	    }
	}	
}

void deleterecord(void)
{
	system("cls");
    int d;
    char another='Y';
    while(another=='Y')  //infinite loop
    {
	system("cls");
	printf("                Enter The Employee ID To Delete :");
	scanf(" %d",&d);
	fp=fopen("record1.txt","r+");
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(e.id==d)
	    {
			printf("\n\n");
			printf("                           .....................The Employee Record Is Available....................\n\n");
			printf("               Employee Name Is %s\n\n",e.name);
			printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			findrecord='t';
	    }
	}
	if(findrecord!='t')
	{
	    printf("                                    .........................No record is found modify the search..........................\n\n");
	    if(getch())
	    administration();
	}
	if(findrecord=='t' )
	{
	    printf("Do You Want To Delete THe Record ? (Y/N) ");
	    if(getch()=='Y')
	    {
			ft=fopen("test1.txt","w");  //temporary file for delete
			rewind(fp);
			while(fread(&e,sizeof(e),1,fp)==1)
			{
		    	if(e.id!=d)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&e,sizeof(e),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			remove("record1.txt");
			rename("test1.txt","record1.txt"); //copy all item from temporary file to fp except that
			fp=fopen("record1.txt","r");    //we want to delete
			if(findrecord=='t')
			{
		    	printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
		    	printf("        Delete Another Record ? (Y/N) : ");
			}
	    }
		else
		administration();
		fflush(stdin);
		another=getch();
	}
}
administration();
}

void searchrecord(void)
{
	system("cls");
    int d;
    printf("                                          ***Search Employees Record*****\n\n");
    printf("                  1. Search By ID\n");
    printf("                  2. Search By Name\n\n");
    printf("                  Enter Your Choice---> ");
    fp=fopen("record1.txt","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
		{
	    	system("cls");
	    	printf("                                   **Search Record By Id**\n\n");
	    	printf("                Enter The Employee ID : ");
	    	scanf(" %d",&d);
	    	printf("\n\n");
			printf("Searching........");
	    	while(fread(&e,sizeof(e),1,fp)==1)
	    	{
				if(e.id==d)
				{
		    		printf("\n\n");
					printf("...........................The Record is available............................\n\n");
				    printf("       ID : %d\n\n",e.id);
				    printf("       Name : %s\n\n",e.name);
				    printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
				    printf("       Year Of Joining :%d\n\n",e.YOJ);
				    printf("       Department :%s\n\n",e.department);
				    printf("       Place :%s\n\n",e.place);
				    findrecord='t';
				}

	    }
	    if(findrecord!='t')  //checks whether conditiion enters inside loop or not
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (Y/N)");
	    if(getch()=='Y')
	    searchrecord();
	    else
	    administration();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    printf("                                   **Search Employees By Name***\n\n");
	    printf("               Enter Employee Name : ");
	    scanf(" %s",s);
	    int d=0;
	    while(fread(&e,sizeof(e),1,fp)==1)
	    {
		if(strcmp(e.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    printf("                               .........................The Record is available...........................\n\n\n");
			printf("       ID : %d\n\n",e.id);
			printf("       Name : %s\n\n",e.name);
			printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			printf("       Year Of Joining :%d\n\n",e.YOJ);
			printf("       Department :%s\n\n",e.department);
			printf("       Place :%s\n\n",e.place);
		    d++;
		}

	    }
	    if(d==0)
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (Y/N)");
	    if(getch()=='Y')
	    searchrecord();
	    else
	    administration();
	    break;
	}
	default :
	getch();
	searchrecord();
    }
    fclose(fp);
}

void viewrecord(void) 
{
    system("cls");
    printf("                              *** Employee Details***\n\n");
    printf("                 DEPARTMENT    ID        EMPLOYEE NAME        D.O.B        Y.O.J        PLACE\n\n");
    
    fp=fopen("record1.txt","r");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
		printf("                 %s",e.department);
		printf("        %d",e.id);
		printf("        %s",e.name);
		printf("        %d/%d/%d",e.dd,e.mm,e.yyyy);
		printf("        %d",e.YOJ);
		printf("        %s",e.place);
		printf("\n\n");
	}
      
      fclose(fp);
      returnfunc();
}

void returnfunc(void)
{
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    administration();
    else
    goto e;
}

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	if(e.id==c)
	
	return 0;  //returns 0 if employee exits
    
	return 1; //return 1 if it not
}
int getid()
{
	
	id=id+1;
	return id;
}
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
int isValidDate( int d,int m,int y)
{
    //check range of year,month and day
    if (y > MAX_YR ||
            y < MIN_YR)
        return 0;
    if (m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;
    //Handle feb days in leap year
    if (m == 2)
    {
        if (IsLeapYear(y))
            return (d <= 29);
        else
            return (d <= 28);
    }
    //handle months which has only 30 days
    if (m == 4 || m == 6 ||
            m == 9 || m == 11)
        return (d <= 30);
    return 1;
}

int getdata()
{
	int m;
	int t,flag=0,i=0,flag2=0;
	fflush(stdin);
	while(flag!=1)
	{
		printf("        Employee Name : ");
		gets(e.name);
		while(e.name[i]!='\0')
		{
			if (((e.name[i]>='A')&&(e.name[i]<='Z'))||((e.name[i]>='a')&&(e.name[i]<='z'))||((e.name[i]==' ')))
			{
				i++;
				flag2=0;
			}
			else
			{
				printf(".          \nInavalid Input\n");
				flag2=1;
				break;
			}
		}
		if(flag2==0)
		{
			break;
		}
	}
	int status=1;
	while(status!=0)
	{
		printf("           \n\n Date Of Birth (not less then year 1980)(dd/mm/yyyy) :");
		scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
		int status = isValidDate(e.dd,e.mm,e.yyyy);
		if(status !=1)
		{
			printf("\n Please enter a valid date!\n");
		}
		else
		{
			break;
		}
	}
	time_t td = time(NULL);
    struct tm tm = *localtime(&td);
    printf("             \n\nYour Date of Joining is : %d-%02d-%02d \n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
	e.YOJ=tm.tm_year + 1900;
	printf("           \n\n Place :");
	fflush(stdin);
	gets(e.place);
	printf("                \n\n Department :");
	fflush(stdin);
	gets(e.department);
	t=getid();
	printf("                                  \n\nYour Employee ID is :\t%d\n\n",t);
	e.id=t;
	return 1;
}
void customer(void)
{

	system("cls");
	printf("                    *****\n                                      WELCOME\n                    *******\n\n");
	printf("               YOU ARE--->\n\n               1. Vegetarian\n\n               2. Non Vegetarian\n\n                      OR\n\n               3. Back To Main Menu\n\n   Enter Your Choice  -->");
	int k;
	scanf("%d",&k);
		int wait;
	printf("In progress :");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	if(k==1)
	{
		system("cls");
		vegetarian();
	}
	else if(k==2)
	{
		system("cls");
		nonvegetarian();
	}
	else if(k==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}
}
void vegetarian(void)
{
	int choice;
	int again;
	int quantity;
	
	double price=0;
	
	printf("                    ****\n                                  VEGETARIAN MENU\n                    ******\n\n");
	printf("      1. Burger               Rs: 40/-\n      2. Noodles              Rs: 60/-\n      3. Sandwich             Rs: 45/-\n      4. Veg Roll            Rs: 35/-\n      5. Veg. Thaali          Rs: 150/-\n         -->Dal\n         -->Paneer\n         -->Chapati\n         -->Rice\n         -->Papad\n      6. Back To Main Menu\n\n Enter Your Choice-->  ");
	char v;
	FILE *vmenu;
	vmenu=fopen("vegmenu.txt","rt");
	while((v=getc(vmenu))!=EOF)
        {
        	printf("%c",v);
		}
         fclose(vmenu);
         
    printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity in Plates:  ");
		scanf("%d",&quantity);
		total=total + 40*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			printf(" Only Cash on Delivery Available\n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity in plates:");
		scanf("%d",&quantity);
		total=total + 60*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			printf(" Only Cash on Delivery Available\n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity in plates:  ");
		scanf("%d",&quantity);
		total=total + 45*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			printf(" Only Cash on Delivery Available\n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity in plates:");
		scanf("%d",&quantity);
		total=total + 35*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			printf(" Only Cash on Delivery Available\n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity in plates:");
		scanf("%d",&quantity);
		total=total + 150*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			printf(" Only Cash on Delivery Available\n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
			
	}
	else if(choice==6)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		vegetarian();
	}
}
void nonvegetarian(void)
{
	int choice;
	int again;
	int quantity;
	double price=0;
	printf("                                    ******\n");
	printf("                                                  Non Veg. Menu\n");
	printf("                                    ******\n");
    	printf("1. Dry Chicken            Rs: 100-\n\n2. Gravy Chicken          Rs: 120-\n\n3. Chicken Biryani        Rs: 85-\n\n4. Chicken Roll              Rs: 35-\n\n5. Back To Main Menu\n\n\nEnter Your Choice");
	char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c",n);
	}
	printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity in plates: ");
		scanf(" %d",&quantity);
		total=total + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity in plates:");
		scanf(" %d",&quantity);
		total=total + 120*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			printf(" Only Cash on Delivery Available \n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity in plates:");
		scanf(" %d",&quantity);
		total=total + 85*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			printf(" Only Cash on Delivery Available \n");
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity in plates:");
		scanf(" %d",&quantity);
		total=total + 35*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			printf(" Only Cash on Delivery Available \n");
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonvegetarian();
	}
}
void details(void)
{
	char ch;
	int count=0;
	int flag=0,flag2=0;;
	long long int phone;
	char address[40];
	char landmark[30], name1[20];
	printf("Please Give Your Contact Details \n");
	fflush(stdin);
	while(flag!=1)
	{
		int i=0;
		name1[20];
		printf("        Customer Name : ");
		fflush(stdin);
		gets(name1);
		while(name1[i]!='\0')
		{
			if(name1[i]>='0'&&name1[i]<='9')
			{
				printf(".          \nInavalid Input\n");
				flag2=1;
				break;
			}
			i++;
			flag2=0;
		}
		if(flag2==0)
		{
			break;
		}
	}
	while(flag!=1)
	{
		printf("        Phone Number : ");
		scanf("%lld",&phone);
		int phone1=phone;
		do
		{
			count++;
			phone1=phone1/10;
	}while(phone1!=0);
		if(count>10)
		{
			printf("\nplease enter valid number\n");
		}
		else{
			break;
		}
	}
	printf("\tAddress : ");
	scanf("%s",address);
	printf("Landmark : ");
	scanf("%s",landmark);
	printf("\n\n");
	printf("Your Entered Details Are --->\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s \nPhone number : %lld\n",name1,phone);
	fclose(cust);
	printf("    --> Name :  %s\n      -->Phone     :%lld \n    -->Address  :%s \n    -->Landmark  :%s \n",name1,phone,address,landmark);
	printf("\n\n\n");
	printf("                       ***********\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                      Please Pay the bill to delivery person");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       ***********\n");
	
	printf("Press Any To The MainMenu.");
	if(getch())
	customer();
}

void aboutus(void)
{
	system("cls");
	printf("PEOPLE BEHIND THIS PROJECT :\n\n   -->Sangeeta Chawla\n\n   -->Mahak Saxena\n\n   -->Pooja Joshi\n\n                         ***THANK YOU***");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");
	if(getch())
	mainmenu();
}
