#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	
	int c;
	cout<<"\t\t\t----------------------------------------------\n\n"<<endl;
	cout<<"\t\t\t---------------Welcome to Login page-----------\n\n"<<endl;
	cout<<"\t\t\t---------------------Menu----------------------\n\n"<<endl;
	
	cout<<"                                             \n\n";
	cout<<"\t|press 1 to login                     | "<<endl;
	cout<<"\t|press 2 to Register                  | "<<endl;
	cout<<"\t|press 3 if you forgot your password  | "<<endl;
	cout<<"\t|press 4 to Exit                      | "<<endl;
	cout<<"\n\t\t Please enter your choice:";
	cin>>c;
	cout<<endl;
	
	switch(c){
		case 1:
			login();
			break;
			
		case 2:
		registration();
		 break;
		 
		case 3:
		 forgot();
		 break; 
		
		case 4:
		  cout<<"\t\t\t thank you.";
		  break;
		
		default:
			cout<<"\t\t\t Please select from the options given above \n"<<endl;
			main();
	}
} 

void login(){
	int count;
	string userId, password, id, pass;
	system("cls");
	cout<<"\t\t\t Please enter the username and password: "<<endl;
	cout<<"\t\t\t USERNAME:";
	cin>>userId;
	cout<<"\t\t\t Password:";
	cin>>password;
	
	
	ifstream input("records.txt");
	
	while(input>>id>>pass){
		if(id ==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<userId<<"\n Your Login is succesful \n Thanks for logging in";
		main();
	}
	else{
		cout<<"\n Login error \n Please check your email \n";
		main();
	}
	
	
}

void registration()
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout<<"\t\t\t Enter the username:";
	cin>>ruserId;
	cout<<"\t\t\t Enter the password:";
	cin>>rpassword;
	
	ofstream f1("records.txt",ios::app);
	f1<<ruserId<<' '<<rpassword<<endl;
	system("cls");
	cout<<"\n Registration successful";
	main();
	
}

void forgot()
{
	int option;
	system("cls");
	cout<<"\t\t\t You forgot your password?? No worries\n";
	cout<<" press 1 to search your username"<<endl;
	cout<<" press 2 to go back to the main menu"<< endl;
	cin>>option;
	switch(option)
	{
		case 1:
		{
			int count=0;
			string suserId, sId, spass;
			cout<<"\n\t\t Enter the username which you remembered;";
			cin>>suserId;
			
			ifstream f2("records.txt");
			while(f2>>sId>>spass)
			{
				if(sId==suserId){
					count=1;
				}
			}
			f2.close();
			if(count==1)
			{
				cout<<"\n\n Your account is found! \n";
				cout<<"\n your password is :"<<spass;
				main();
			}
			else{
				cout<<"\n sorry your account is not found! \n";
				main();
			}
			break;
			
		}
			 case 2:
			 {
				main();
			 }
			 default:
			 	
				 cout<<"\n Wrong choice sorry! please try again"<<endl;
			 	forgot();
	}
}
