//online shopping portal for clothing and footwear
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<bits/stdc++.h>
using namespace std;

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
void openportal();
void placeorder();
void deletecart();
void username();
void showacc();
void loggedin();
void costcalCloth();
void costcalFoot();
void editCart();
void showCart();

//global variables
string reguser,regpass,fname,lname,dob,email,ph_no,user,ru;
float totalam;
int exist=0,flag=0,islog=0;

ifstream item;
ofstream f1;
ifstream acc;

//main function
int main()
{
	system("cls");
	int choice;
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                      Welcome to our page!!                       \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n1.Signup";
	cout<<"\n2.Signin";
	cout<<"\n3.Forgot credentials";
	cout<<"\n4.Shop";
	cout<<"\n\n\nEnter your choice : ";
	cin>>choice;
	if(choice==1)
		signup();
	else if(choice==2)
		signin();
	else if(choice==3)
		forgot();
	else if(choice==4)
		shop();
	else
		exit;
}

//checking if username already exists or not
void username()
{
	ifstream check;
	check.open("data.txt",ios::in);
	
	while(!check.eof())
	{
		string ru;
		check>>ru;
		if(ru==reguser)
		{
			exist=1;
		}
		else
			{
				for(int j=0;j<6;j++)
					check>>ru;
			}
	}
	check.close();
}

//function for signup
void signup()
{
	
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                          Registration!!                         \n";
	cout<<"\n\n********************************************************************\n";
	f1.open("data.txt", ios::app);
	
	cout<<"Enter the username : ";
	cin>>reguser;
	f1<<reguser<<' ';
	
	username();
	if(exist==1)
	{
		cout<<"Username already exist!\n";
		username();
	}
	
	else{
		cout<<"Enter the password : ";
		cin>>regpass;
		f1<<regpass<<' ';
	}
	cout<<"Enter first name : ";
	cin>>fname;
	f1<<fname<<' ';

	cout<<"Enter last name : ";
	cin>>lname;
	f1<<lname<<' ';
	

	cout<<"Enter your date of birth in the format dd/mm/yyyy : ";
	cin>>dob;
	f1<<dob<<' ';

	cout<<"Enter your email id : ";
	cin>>email;
	f1<<email<<' ';

	cout<<"Enter your contact number : ";
	cin>>ph_no;
	f1<<ph_no<<'\n';

	f1.close();
	cout<<"Registration successfull!!\n";
	cout<<"\n\nPress 1 for Signin";
	cout<<"\n\n\nEnter your choice: ";
	int ch;
	cin>>ch;
	if(ch==1)
		signin();	
	
}

//function for sign in
void signin()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                              Login!!                             \n";
	cout<<"\n\n********************************************************************\n";
	int exist=0;
	string pass,u,p;
	int loginattempt = 0;
	while(loginattempt<5)
	{
		cout<<"Enter the username : ";
		cin>>user;
		cout<<"Enter the password : ";
		cin>>pass;
	
		ifstream fin;
		fin.open("data.txt",ios::in);

		while(fin>>u>>p)
		{
			if(u==user && p==pass)
			{
				exist = 1;
			}
			else
			{
				getline(fin,u);
			}
		}
		fin.close();
	
	 	if(exist==1)
		{
			system("cls");
			cout<<"********************************************************************\n";
			cout<<"\n\n                         Shopping Portal                          \n";
			cout<<"\n\n********************************************************************\n";
			string fn,ln;
			ifstream fdata;
			fdata.open("data.txt",ios::in);

			cout<<"\n\n\nHello ";
			while(!fdata.eof())
			{
				string u;
				fdata>>u;
				if(u==user)
				{
					fdata>>u>>fn;
					cout<<fn<<' ';
					fdata>>ln;
					cout<<ln;
					cout<<"\n\nWe're glad that you're here!\n";
					islog=1;
					fdata.close();
					cout<<"\n\nPress any key to continue...\n";
					cin.get();
					cin.get();
					openportal();
				}
				else
				{
					getline(acc,u);
				}
			}
			
		}
		else{
			cout<<"Invalid username or password.\n\n";
			loginattempt++;
			}
			
	}
	if(loginattempt==5)
	{
		cout<<"\nToo many attempts!\n\n";
		cout<<"Press any key to go back to home page...\n";
			cin.get();
			cin.get();
			main();
	}
	
}

//homepage for loggedin user
void openportal()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.Account\n2.Shop\n3.Checkout\n4.SignOut";
	int option1;
	cout<<"\n\nEnter your choice : "; 	cin>>option1;
	if(option1==1)
		account();
	else if(option1==2)
		shop();
	else if(option1==3)
		main();
	else if(option1==4)
		{
			//for sign out
			//deleting user details from data file
			ifstream edfile;
			edfile.open("data.txt");
			ofstream blank;
			blank.open("editdata.txt");
			while(!edfile.eof())
			{
				string x,line;
				edfile>>x;
				getline(edfile,line);
				if(x!=user)
				{
					blank<<x<<' ';
					
					blank<<line<<endl;
				}
			}
			blank.close();
				edfile.close();
				remove("data.txt");
				rename("editdata.txt","data.txt");
			main();
		}
	else
		{cout<<"\nSorry, wrong choice selected"; openportal();}
}

//finding password from username
void forgot()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Forgot Credentials!!                         \n";
	cout<<"\n\n********************************************************************\n";
	int chn;
	cout<<"\n\nSearch your account by username ";
	int ex = 0;
	string searchuser,su,sp;
	cout<<"\nEnter your username : "; cin>>searchuser;
	ifstream searchu("data.txt");
	while(searchu>>su>>sp)
	{
		if(su==searchuser)
		{ex = 1; break;}
		else
			getline(searchu,su);
	}
	searchu.close();
	if(ex==1)
	{
		cout<<"\n\nCongratulations! Your account is found.";
		cout<<"\n\nYour password : "<<sp;
		cout<<"\n\nPress any key to continue...";
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
	
}

//function for shopping
void shop()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                      Select Shooping Option                        \n";
	cout<<"\n1.Men\n2.Women\n";
	int ch;
	cout<<"\n\nEnter your choice : "; cin>>ch;
	if(ch==1)
		 men();
	else if(ch==2)
		women();
	else {cout<<"\nSorry, wrong choice selected"; shop();}
}

//shopping for men
void men()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                         Select Category                         \n";
	cout<<"\n1.Clothing\n2.Footwear\n";
	int ch;
	cout<<"\nEnter your choice : ";	cin>>ch;
	if(ch==1)
		clothMen();
	else if(ch==2)
		 footMen();
	else
		men();
}

//shopping for women
void women()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n                         Select Category                         \n";
	cout<<"\n1.Clothing\n2.Footwear\n";
	int ch;
	cout<<"\nEnter your choice : ";	cin>>ch;
	if(ch==1)
		clothWomen();
	else if(ch==2)	
		footWomen();
	else
		women();
}

//function for opening account of user
void account()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                             Account                         \n";
	cout<<"\n\n********************************************************************\n";
	
	acc.open("data.txt",ios::in);
	
	while(!acc.eof())
	{
		
		acc>>ru;
		if(ru==user)
		{
			flag=1;
			showacc();
		}
		else
			{
				getline(acc,ru);
			}
	}
}

//for displaying account details of user
void showacc()
{
	if(flag==1)
	{
	cout<<"\n\nUsername:\t\t\t";
	acc>>ru;
	cout<<ru;
	
	cout<<"\nFirst name:\t\t\t";
	string f;
	acc>>f;
	cout<<f;

	cout<<"\nLast name:\t\t\t";
	string l;
	acc>>l;
	cout<<l;
	
	cout<<"\nDate Of Birth:\t\t\t";
	string d;
	acc>>d;
	cout<<d;
	
	cout<<"\nEmail Id:\t\t\t";
	string em;
	acc>>em;
	cout<<em;

	cout<<"\nContact Number:\t\t\t";
	string ph;
	acc>>ph;
	cout<<ph;
	acc.close();
	cout<<"\n\n\nDo you want to see cart [y/n]?  ";
	char c;
	cin>>c;
	if(c=='y')
		cart();
	else
		openportal();
	}
}

//function for category of clothing for men
void clothMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.Discounted\n2.Non-discounted\n";
	int ch;
	cout<<"\nEnter your choice : ";	cin>>ch;
	if(ch==1)
		disclMen();
	else if(ch==2)
		nondisclMen();
	else
		men();
}

//function for category of footwear for men
void footMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Footwear for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.Discounted\n2.Non-discounted\n";
	int ch;
	cout<<"\nEnter your choice : "; cin>>ch;
	if(ch==1)
		disftMen();
	else if(ch==2)	
		nondisftMen();
	else
		men();	
}

//function for category of clothing for women
void clothWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Clothing for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.Discounted\n2.Non-discounted\n";
	int ch;
	cout<<"\nEnter your choice : "; cin>>ch;
	if(ch==1)
		disclWomen();
	else if(ch==2)
		nondisclWomen();
	else
		women();
}

//function for category of footwear for women
void footWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Footwear for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.Discounted\n2.Non-discounted\n";
	int ch;
	cout<<"\nEnter your choice : "; cin>>ch;
	if(ch==1)
		disftWomen();
	else if(ch==2)
		nondisftWomen();
	else
		women();
}

void loggedin()
{
	cout<<"\nYou are not logged in. Please login first.";
						cout<<"\nPress any key to continue...\n";
						cin.get();
						cin.get();
						main();
}

//function for displaying non-discounted clothing items for men
void nondisclMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="136";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();
	
	cout<<"\n\n5% GST on goods that does not exceed Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted clothing items for women
void nondisclWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Clothing for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="236";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();
	
	cout<<"\n\n5% GST on goods that does not exceed Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted footwear items for men
void nondisftMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                         Footwear for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="146";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\n* represents the price is printing on footwear";
	cout<<"\n\n5% GST on goods that does not exceed Rs.500 per price and 18% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted footwear items for women
void nondisftWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Footwear for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="246";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\n* represents the price is printing on footwear";
	cout<<"\n\n5% GST on goods that does not exceed Rs.500 per price and 18% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted clothing items for men
void disclMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Clothing for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="135";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();
	
	cout<<"\n\n5% GST on goods that does not exceed Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted clothing items for women
void disclWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Clothing for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="235";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();
	
	cout<<"\n\n5% GST on goods that does not exceed Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted footwear items for men
void disftMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Footwear for men                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="145";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\n* represents the price is printing on footwear";
	cout<<"\n\n5% GST on goods that does not exceed Rs.500 per price and 18% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted footwear items for women
void disftWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                        Footwear for women                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="245";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\n* represents the price is printing on footwear";
	cout<<"\n\n5% GST on goods that does not exceed Rs.500 per price and 18% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//calculating gst and cost price for clothing
void costcalCloth()
{
    int i=0;
    while(i<4){
    int id;
    item>>id;
    cout<<id<<"\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t";
    float cost;
    item>>cost;
    cout<<cost<<"\t\t";
    float dis;
    item>>dis;
    cout<<dis<<"\t\t";
    float dis_cost;
    dis_cost = cost - ((cost * dis)/100);
    cout<<dis_cost<<"\t\t\t";
    float gst;
    if(dis_cost>1000)
        gst = 12;
    else
        gst = 5;
    cout<<gst<<"\t\t";
    float buy;
    buy = dis_cost + ((dis_cost * gst)/100);
    cout<<buy<<endl;
    string temp;
    getline(item,temp);
    i++;}
}

//calculating gst and cost price for footwear
void costcalFoot()
{
    int i=0;
    while(i<4){
    int id;
    item>>id;
    cout<<id<<"\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t";
    float cost;
    item>>cost;
    cout<<cost<<"\t\t";
    float dis;
    item>>dis;
    cout<<dis<<"\t\t";
    float dis_cost;
    dis_cost = cost - ((cost * dis)/100);
    cout<<dis_cost<<"\t\t\t";
    float gst;
    if(dis_cost>500)
        gst = 18;
    else
        gst = 5;
    cout<<gst<<"\t\t";
    float buy;
    buy = dis_cost + ((dis_cost * gst)/100);
    cout<<buy<<endl;
    string temp;
    getline(item,temp);
    i++;}
}

//adding item in cart
void editCart()
{
    string selectid;
	cout<<"\n\nEnter ItemId to add corresponding item in cart : ";
	cin>>selectid;
    if(islog!=1)
	{
		loggedin();
	}
	else
	{
		ifstream addcart;
        addcart.open("cart.txt",ios::in);
		f1.open("usercart.txt",ios::app);
       
		int check_selectid = 0;
        string xi;
        while(!addcart.eof())
        {
            addcart>>xi;
            if(xi==selectid)
            {
				f1<<user<<' ';
        		f1<<selectid<<' ';
				check_selectid = 1;
                string item_name;
				addcart>>item_name;
                f1<<item_name<<' ';
    			float cost;
    			addcart>>cost;
   				float dis;
    			addcart>>dis;
    			float dis_cost;
    			dis_cost = cost - ((cost * dis)/100);
    			float gst;
    			if(dis_cost>1000)
        			gst = 12;
    			else
        			gst = 5;
    			float price;
    			price = dis_cost + ((dis_cost * gst)/100);
				f1<<price<<endl;
				cout<<"\nItem is added to cart.\n";
            }
            getline(addcart,xi);
        }
        addcart.close();
	    if(check_selectid!=1)
			cout<<"\nWrong choice entered.\n";
        f1.close();
	}
}

//printing bill of purchasing items
void printbill()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                              Bill                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nItems are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
            showCart();
	    }
       getline(item,x);
    }
    item.close();
	totalam = 0;
	ifstream total;
	total.open("usercart.txt",ios::in);
	string check_user,tid,tiname;
	float tcost;
	while(!total.eof())
	{
		total>>check_user;
	    if(check_user==user)
		{
			total>>tid>>tiname>>tcost;
			totalam += tcost;
		}
		getline(total,check_user);
	}
	
	cout<<"\nTotal amount : Rs."<<totalam<<"/-"<<endl;
	total.close();
	cout<<"\n\nDo you want to place order [y/n]?  ";
	char choice1;
	cin>>choice1;
	if(choice1=='y')
		placeorder(); 
	else
		openportal();
}

//function for placing order
void placeorder()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n********************************************************************\n";
	ifstream placein;
	placein.open("usercart.txt");
	ofstream temp;
	temp.open("temp1.txt");
	while(!placein.eof())
	{
		string x,y;
		placein>>x;
		getline(placein,y);
		if(x!=user)
		{
			temp<<x;
			temp<<y<<endl;
		}
	}
	temp.close();
		placein.close();
		remove("usercart.txt");
		rename("temp1.txt","usercart.txt");
	
	cout<<"\n\nYour order is placed...";
	cout<<"\n\nThank you for shopping\nHave a nice day!\n\n";
	exit(0);
}

//function to open cart
void cart()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                           Cart Items                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nCart items are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
		    showCart();
	    }
       getline(item,x);
    }
    item.close();
	cout<<"\n\nPress 1 to print bill\n";
	cout<<"Press 2 to delete item from cart\n";
	cout<<"Press 3 to go back\n";
	int print;
	cout<<"\nEnter your choice : "; cin>>print;
	if(print==1)
		printbill();
	else if(print==2)
		deletecart();
	else if(print==3)
		openportal();
	else{
		cout<<"\nWrong choice entered.";
		cout<<"\nPress any key to continue...\n";
		cin.get();
		cin.get();
		cart();}
}

//displaying cart items
void showCart()
{
	string id;
	item>>id;
    cout<<id<<"\t\t\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t\t\t";
    float cost;
    item>>cost;
    cout<<cost<<endl;
}

//deleting item from cart
void deletecart()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         Shopping Portal                          \n";
	cout<<"\n\n                       Deleting Cart Items                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nCart items are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
            showCart();
	    }
       getline(item,x);
    }
    item.close();
	
	cout<<"\n\nEnter ItemId of item that you want to delete from cart : ";
	string delId,line;
	cin>>delId;
	ifstream del1;
	del1.open("usercart.txt");
	ofstream temp;
	temp.open("temp.txt");
	while(!del1.eof())
	{
		string x;
		del1>>x;
		if(x==user)
		{
			string y,it;
			float cit;
			del1>>y>>it>>cit;
			if(y != delId)
			{
				temp<<x<<' '<<y<<' '<<it<<' '<<cit<<endl;
			}
		}
		else{
			temp<<x<<' ';
		    getline(del1,line);
			temp<<line<<endl;
		}
	}
	temp.close();
		del1.close();
		remove("usercart.txt");
		rename("temp.txt","usercart.txt");
	cart();
}