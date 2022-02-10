#include<stdio.h>
#include<string.h>
#include<stdlib.h>

	struct Customer_details
	{
		char name[30];
		 char gender;
		 char _grp[4];
		char city[10];
		char address[100];
		int id;
		long long contact_no;
		char _bank[30];
	}Customer;
void insert()
	{	system("clear");
		printf("===============================Welcome To Customer Registration Page==============================================\n");
		FILE *fp1;	
		fp1=fopen("details.dat","a");
		if(fp1==NULL)
		{	printf("Sorry, Techincal fault, Try later!\n");
			return;	
		}
		printf("Enter your Name\n");
		gets(Customer.name);
		gets(Customer.name);

		printf("Enter your gender\n Press M for Male and F for Female\n");
		scanf(" %c",&Customer.gender);

		printf("Enter your Bank Branch\n");
		scanf("%s",Customer._grp);

		printf("Enter your City Name\n");
		scanf(" %s",Customer.city);

		printf("Enter your Permanent Address \n");
		gets(Customer.address);
		gets(Customer.address);
		
		printf("Enter your Customer ID\n");
		scanf("%d",&Customer.id);

		printf("Enter your Contact Number\n");
		scanf("%lld",&Customer.contact_no);
		
		printf("Enter the name of the Bank you would affiliate \n");
		gets(Customer._bank);
		gets(Customer._bank);
		
		fwrite(&Customer,sizeof(Customer),1,fp1);
		fclose(fp1);
		
	}

void search()
{		
			
			char sname[3];
			FILE* fp;
			int flag=0;
			fp=fopen("details.dat","r");
			if(fp==NULL)
			{	printf("Sorry, can't Open this file\n");
				return;
			}         	   	
                   	 printf("ENTER THE Bank Branch :->");
                    	scanf("%s",sname);
                    	while(fread(&Customer,sizeof(Customer),1,fp))
                    	{	
                        	if(strcmp(sname,Customer._grp)==0)
                        	{	flag=1;
                        	 printf("\n\t\t%s\t\t%lld\t\t%s\t\t%s\n",Customer.name,Customer.contact_no,Customer.city,Customer._bank);
			    
                        	}

                    	}
			fclose(fp);
			if(flag==0)
				{	printf("No Such Customer exists\n");
				}                    
  		return;                  
                  	
}
void display()
{	printf("==================================Customer DETAILS=========================================\n");	
	FILE* fp;
	fp=fopen("details.dat","r");
	if(fp==NULL)
	{	printf("Sorry, can't Open this file\n");
		return;
	}
	
	while(fread(&Customer,sizeof(Customer),1,fp))
		{
		printf("%s\t\t%d\t\t%s\t\t%s\t\t%lld\t\t%s\n",Customer.name,Customer.id,Customer._grp,Customer.city,Customer.contact_no,Customer._bank);
		}
	fclose(fp);
	printf("\n");
	return;
}
int main()
{
	int ch;
	do
	{	
		printf("---------------------------------- WELCOME TO BANK MANAGEMENT SYSTEM--------------------------------------");
		printf("\n\n");
		printf("Press 1 for New Customer registration.\n");
		printf("Press 2 to Display All Records of Customers.\n");
		printf("Press 3 to Search Customer of a particular Branch.\n"); 
		printf("Press 4 to exit.\n ");
		printf("Enter your choice.\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			insert();	
			break;
			case 2:				
			display();
			break;
			case 3:
			search();
			break;
			default:
			break;

		}
	}while(ch!=4);
}
