#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;

double totalamount=0;

//functions declaration
void signin();
void signup();
void forgot();
void shop();
void account();
void men();
void women();
void clothMen();
void footMen();
void clothWomen();
void footWomen();
void nondisclMen();
void nondisclWomen();
void nondisftMen();
void nondisftWomen();
void disclMen();
void disclWomen();
void disftMen();
void disftWomen();
void printbill();
void cart();

map<string, int> cartitem;

int main()
{
	
	int choice;
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                      Welcome to our page!!                       \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n1.Signup";
	cout<<"\n2.Signin";
	cout<<"\n3.Forgot credentials";
	cout<<"\n4.Exit";
	cout<<"\n\n\nEnter your choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: signup();
				break;
		case 2: signin();
				break;
		case 3: forgot();
				break;
		case 4: exit;
				break;
		default: cout<<"Sorry, wrong choice selected";
				main();
	}
}

void signup()
{
	
	string reguser,regpass,name,dob;
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                          Registration!!                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"Enter your name : ";
	cin>>name;
	cout<<"Enter your date of birth in the format dd/mm/yyyy : ";
	cin>>dob;
	unique:
	cout<<"Enter the username : ";
	cin>>reguser;
	ofstream fout;
	fout.open("database.txt", ios::app);
	fout<<reguser<<' ';
	ifstream check;
	check.open("database.txt",ios::in);
	int exist=0;
	while(!check.eof())
	{
		string ru;
		check>>ru;
		if(ru==reguser)
		{
			exist=1;
		}
	}
	
	if(exist==1)
	{
		cout<<"Username already exist!\n";
		goto unique;
	}
	
	else{
		cout<<"Enter the password : ";
		cin>>regpass;	
		fout<<regpass<<endl;
		fout.close();
	
		cout<<"Registration successfull!!\n";
		cout<<"\n\nPress 1 for Signin";
		cout<<"\nPress 2 for Home page";
		cout<<"\nPress 3 for exit";
		cout<<"\n\n\nEnter your choice: ";
		int ch;
		cin>>ch;
		switch(ch)
		{
	
		case 1: signin();
				break;
		case 2: main();
				break;
		case 3: exit;
				break;
		default: {
					cout<<"Sorry, wrong choice selected";
					cin.get();
					cin.get();
					main();
					}
		}
	}
}

void signin()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                              Login!!                             \n";
	cout<<"\n\n********************************************************************\n";
	int exist=0;
	string user,pass,u,p;
	
	cout<<"Enter the username : ";
	cin>>user;
	cout<<"Enter the password : ";
	cin>>pass;
	
	ifstream fin;
	fin.open("database.txt",ios::in);
	
	while(!fin.eof())
	{
		fin>>u>>p;
		if(u==user && p==pass)
		{
			exist = 1;
		}
	}
	
	if(exist==1)
	{
		cout<<"Hello "<<user<<"\nWe're glad that you're here!\n";
		select:
		cout<<"\n\nSelect options...";
		cout<<"\n1.Account\n2.Shop\n3.Checkout";
		cout<<"\n\nEnter your choice : ";
		int option;
		cin>>option;
		switch(option)
		{
			case 1: account();
					break;
			case 2: shop();
					break;
			case 3: main();
					break;
			default: {cout<<"\nSorry, wrong choice selected"; goto select;}
		}
	}
	else{
		cout<<"No such registration found...\n";
		cout<<"Press any key to go back to home page...\n";
		cin.get();
		cin.get();
		main();
	}
	fin.close();
}

void forgot()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Forgot Credentials!!                         \n";
	cout<<"\n\n********************************************************************\n";
	int ch;
	
	cout<<"1.Search your account by username ";
	cout<<"\n2.Mainmenu";
	cout<<"\n\nEnter your choice : ";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
		{
			int ex = 0;
				string searchuser,su,sp;
				cout<<"\nEnter your username :";
				cin>>searchuser;
				ifstream searchu("database.txt");
				while(searchu>>su>>sp)
				{
					if(su==searchuser)
					{
						ex = 1;
						break;
					}
				}
				searchu.close();
				if(ex==1)
				{
					cout<<"\nCongratulations! Your account is found.";
					cout<<"\nYour password is "<<sp;
					cin.get();
					cin.get();
					main();
				}
				else{
					cout<<"\nSorry, your account is not found.\n";
					cin.get();
					cin.get();
					main();
				}
				break;
		}
		case 2: 
		{
				main();
				break;
		}
		default:
		{
		cout<<"\nyou have givin a wrong choice, press a key to try again";
				cin.get();
				cin.get();
				forgot();
		}
	}
	
}

void shop()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                      Select Shooping Option                        \n";
	cout<<"\n1.Men\n2.Women\n3.Home Page\n";
	cout<<"\n\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: men();
				break;
		case 2: women();
				break;
		case 3: main();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					shop();
					break;}
	}
}

void men()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                         Select Category                         \n";
	cout<<"\n1.Clothing\n2.Footwear\n3.Home Page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: clothMen();
				break;
		case 2: footMen();
				break;
		case 3: main();
				break;
		case 4: shop();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					men();
					break;}
	}
}

void women()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                         Select Category                         \n";
	cout<<"\n1.Clothing\n2.Footwear\n3.Home Page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: clothWomen();
				break;
		case 2: footWomen();
				break;
		case 3: main();
				break;
		case 4: shop();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					women();
					break;}
	}
}

void account()
{
	system("cls");
}

void clothMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n1.Discounted\n2.Non-discounted\n3.Home page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: disclMen();
				break;
		case 2: nondisclMen();
				break;
		case 3: main();
				break;
		case 4: men();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					clothMen();
					break;}
	}
}

void footMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Footwear for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n1.Discounted\n2.Non-discounted\n3.Home page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: disftMen();
				break;
		case 2: nondisftMen();
				break;
		case 3: main();
				break;
		case 4: men();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					footMen();
					break;}
	}
}
void clothWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Clothing for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n1.Discounted\n2.Non-discounted\n3.Home page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: disclWomen();
				break;
		case 2: nondisclWomen();
				break;
		case 3: main();
				break;
		case 4: women();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					clothWomen();
					break;}
	}
}

void footWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Footwear for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n1.Discounted\n2.Non-discounted\n3.Home page\n4.Back\n";
	cout<<"\nEnter your choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: disftWomen();
				break;
		case 2: nondisftWomen();
				break;
		case 3: main();
				break;
		case 4: women();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					footWomen();
					break;}
	}
}

void nondisclMen()
{
	map<string, double> items = {
	{"men_non_discount_cloth_1",1000},{"men_non_discount_cloth_2",1400},{"men_non_discount_cloth_3",1500},{"men_non_discount_cloth_4",900}
	};
	map<string, int> selected_items;

	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n\n\n\nS.No\tItem\t\t\tCost\n";
	cout<<"1.\tMen_cloth-1\t\tRs.1000/-\n";
	cout<<"2.\tMen_cloth_2\t\tRs.1400/-\n";
	cout<<"3.\tMen_cloth_3\t\tRs.1500/-\n";
	cout<<"4.\tMen_cloth_4\t\tRs.900/-\n";
	cout<<"\n\nPress 5 for back";
	int selectednum;
	cout<<"\n\nSelect item to add in cart : ";
	cin>>selectednum;
	switch(selectednum)
	{
		case 1: 
				{
				
				totalamount += items["men_non_discount_cloth_1"];
				
				cartitem.insert({"men_non_discount_cloth_1",1000});
				break;
				}	
		case 2: 
				{
				totalamount +=  items["men_non_discount_cloth_2"];
				
				cartitem.insert({"men_non_discount_cloth_2",1400});
				break;
				}	
		case 3: 
				{
				totalamount += items["men_non_discount_cloth_3"];
				
				cartitem.insert({"men_non_discount_cloth_3",1500});
				break;
				}	
		case 4: 
				{
				
				totalamount += items["men_non_discount_cloth_4"];
				
				cartitem.insert({"men_non_discount_cloth_4",900});
				break;
				}	
		case 5: clothMen();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					nondisclMen();
					break;}
	}
	system("cls");
	cout<<"\n\nSelect options ";
	cout<<"\n\n1.To see cart\n2.Back\n";
	int ch;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cart();
				break;
		case 2: nondisclMen();
				break;
	}
}

void nondisclWomen()
{
	map<string, double> items = {
	{"women_non_discount_cloth_1",1000},{"women_non_discount_cloth_2",1400},{"women_non_discount_cloth_3",1500},{"women_non_discount_cloth_4",900}
	};
	map<string, int> selected_items;

	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n\n\n\nS.No\tItem\t\t\tCost\n";
	cout<<"1.\tWomen_cloth-1\t\tRs.1000/-\n";
	cout<<"2.\tWomen_cloth_2\t\tRs.1400/-\n";
	cout<<"3.\tWomen_cloth_3\t\tRs.1500/-\n";
	cout<<"4.\tWomen_cloth_4\t\tRs.900/-\n";
	cout<<"\n\nPress 5 for back";
	int selectednum;
	cout<<"\n\nSelect item to add in cart : ";
	cin>>selectednum;
	switch(selectednum)
	{
		case 1: 
				{
				
				totalamount +=  items["women_non_discount_cloth_1"];
				
				cartitem.insert({"women_non_discount_cloth_1",1000});
				break;
				}	
		case 2: 
				{
				
				totalamount +=  items["women_non_discount_cloth_2"];
				
				cartitem.insert({"women_non_discount_cloth_2",1400});
				break;
				}	
		case 3: 
				{
				
				totalamount += items["women_non_discount_cloth_3"];
				
				cartitem.insert({"women_non_discount_cloth_3",1500});
				break;
				}	
		case 4: 
				{
				
				totalamount += items["women_non_discount_cloth_1"];
				
				cartitem.insert({"women_non_discount_cloth_1",900});
				break;
				}	
		case 5: clothWomen();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					nondisclWomen();
					break;}
	}
	system("cls");
	cout<<"\n\nSelect options ";
	cout<<"\n\n1.To see cart\n2.Back\n";
	int ch;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cart();
				break;
		case 2: nondisclWomen();
				break;
	}
}

void nondisftMen()
{
	map<string, double> items = {
	{"men_non_discount_footwear_1",1000},{"men_non_discount_footwear_2",1400},{"men_non_discount_footwear_3",1500},{"men_non_discount_footwear_4",900}
	};
	map<string, int> selected_items;

	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n\n\n\nS.No\tItem\t\t\tCost\n";
	cout<<"1.\tMen_footwear-1\t\tRs.1000/-\n";
	cout<<"2.\tMen_footwear_2\t\tRs.1400/-\n";
	cout<<"3.\tMen_footwear_3\t\tRs.1500/-\n";
	cout<<"4.\tMen_footwear_4\t\tRs.900/-\n";
	cout<<"\n\nPress 5 for back";
	int selectednum;
	cout<<"\n\nSelect item to add in cart : ";
	cin>>selectednum;
	switch(selectednum)
	{
		case 1: 
				{
				
				totalamount += items["men_non_discount_footwear_1"];
				
				cartitem.insert({"men_non_discount_footwear_1",1000});
				break;
				}	
		case 2: 
				{
				totalamount +=  items["men_non_discount_footwear_2"];
				
				cartitem.insert({"men_non_discount_footwear_2",1400});
				break;
				}	
		case 3: 
				{
				totalamount += items["men_non_discount_footwear_3"];
				
				cartitem.insert({"men_non_discount_footwear_3",1500});
				break;
				}	
		case 4: 
				{
				
				totalamount += items["men_non_discount_footwear_4"];
				
				cartitem.insert({"men_non_discount_footwear_4",900});
				break;
				}	
		case 5: clothMen();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					nondisclMen();
					break;}
	}
	system("cls");
	cout<<"\n\nSelect options ";
	cout<<"\n\n1.To see cart\n2.Back\n";
	int ch;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cart();
				break;
		case 2: nondisclMen();
				break;
	}
}

void nondisftWomen()
{
	map<string, double> items = {
	{"women_non_discount_footwear_1",1000},{"women_non_discount_footwear_2",1400},{"women_non_discount_foootwear_3",1500},{"women_non_discount_foootwear_4",900}
	};
	map<string, int> selected_items;

	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\nSelect option...";
	cout<<"\n\n\n\nS.No\tItem\t\t\tCost\n";
	cout<<"1.\tWomen_footwear-1\t\tRs.1000/-\n";
	cout<<"2.\tWomen_footwear_2\t\tRs.1400/-\n";
	cout<<"3.\tWomen_footwear_3\t\tRs.1500/-\n";
	cout<<"4.\tWomen_footwear_4\t\tRs.900/-\n";
	cout<<"\n\nPress 5 for back";
	int selectednum;
	cout<<"\n\nSelect item to add in cart : ";
	cin>>selectednum;
	switch(selectednum)
	{
		case 1: 
				{
				
				totalamount +=  items["women_non_discount_footwear_1"];
				
				cartitem.insert({"women_non_discount_footwear_1",1000});
				break;
				}	
		case 2: 
				{
				
				totalamount +=  items["women_non_discount_footwear_2"];
				
				cartitem.insert({"women_non_discount_footwear_2",1400});
				break;
				}	
		case 3: 
				{
				
				totalamount += items["women_non_discount_footwear_3"];
				
				cartitem.insert({"women_non_discount_footwear_3",1500});
				break;
				}	
		case 4: 
				{
				
				totalamount += items["women_non_discount_footwear_1"];
				
				cartitem.insert({"women_non_discount_footwear_1",900});
				break;
				}	
		case 5: clothWomen();
				break;
		default: {cout<<"\nSorry, wrong choice selected";
					nondisclWomen();
					break;}
	}
	system("cls");
	cout<<"\n\nSelect options ";
	cout<<"\n\n1.To see cart\n2.Back\n";
	int ch;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cart();
				break;
		case 2: nondisclWomen();
				break;
	}
}

void disclMen()
{}

void disclWomen()
{}

void disftMen()
{}

void disftWomen()
{}

void printbill()
{}

void cart()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                           Cart Items                          \n";
	cout<<"\n\n********************************************************************\n";
	map<string, int>::iterator itr;
	cout<<"\n\nCart items are : \n\n\n";
	cout<<"Item\t\t\t\tCost\n\n";
	for(itr = cartitem.begin();itr!=cartitem.end();itr++)
	{
		cout<<itr->first<<"\t"<<itr->second<<"\n";
	}
	cout<<"\nTotal amount : "<<totalamount<<endl;
	cout<<"\n\nPress 1 to Place order\n";
	cout<<"Press 2 to go back\n";
	int ch;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"\n\nThank you for shopping\nHave a nice day!\n\n";
				break;
		case 2: cart();
				break;
	}
}