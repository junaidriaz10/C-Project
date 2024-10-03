#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//receipt function
void receiptFun(string arr[], int parr[],int quantity[], int size, double cash,int total,int discount)
{

    //printing of top head of reciept
    cout<<"\n\n\n\x1B[34mYOUR RECEIPT:\033[0m"<<"\n\n\n";      //"https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c" this link was used for colouring code segment.
    cout<<"\x1B[34m"<<setw(48)<<"* J.F ENTERPRISES *"<<"\033[0m"<<endl;
    cout<<"\x1B[34m*************************************************************************************\033[0m\n\n";
    cout<<"\x1B[34mNAME\033[0m"<<"\x1B[34m"<<setw(25)<<"UNIT PRICE"<<"\033[0m"<<"\x1B[34m"<<setw(26)<<"QUANTITY"<<"\033[0m"<<"\x1B[34m"<<setw(26)<<"TOTAL PRICE"<<"\033[0m"<<"\n\n";
    
    //setting set width using the number of characters in item to improve visuality
    for(int a =0;a<size;a++)
    {
	    if(quantity[a]>0 )
        {
	    	int price = parr[a];
	    	int quantitycheck = quantity[a];              
	    	int pricewid=0;
            int quantwid=0;
	    	while(price>0)
            {
		    	price = price/10;
		    	pricewid = pricewid + 1;
		    }
		    while(quantitycheck>0)                                   
            {
		    	quantitycheck = quantitycheck/10;
		    	quantwid = quantwid + 1;
		    }

            cout<<"\x1B[34m"<<arr[a]<<"\033[0m"<<"\x1B[34m"<<setw(23-arr[a].length())<<"RS "<<"\033[0m"<<"\x1B[34m"<<parr[a]<<"\033[0m"<<"\x1B[34m"<<setw(27-pricewid)<<quantity[a]<<"\033[0m"<<"\x1B[34m"<<setw(26-quantwid)<<"RS "<<"\033[0m"<<"\x1B[34m"<<parr[a]*quantity[a]<<"\033[0m"<<"\n";
	    }
    }

    // printing main contents of reciepts showing items, thier prices,total bill,discount,cash paid and cash returned.
    cout<<"\n\n"<<"\x1B[34mTotal\033[0m"<<"\x1B[34m"<<setw(69)<<"RS "<<"\033[0m"<<"\x1B[34m"<<total<<"\033[0m";
    cout<<"\n\n"<<"\x1B[34mDiscount\033[0m"<<"\x1B[34m"<<setw(66)<<"RS "<<"\033[0m"<<"\x1B[34m"<<discount<<"\033[0m";
    cout<<"\n\n"<<"\x1B[34mNet amount\033[0m"<<"\x1B[34m"<<setw(64)<<"RS "<<"\033[0m"<<"\x1B[34m"<<total-discount<<"\033[0m";
    cout<<"\n\n\x1B[34mCash recieved\033[0m"<<"\x1B[34m"<<setw(61)<<"RS "<<"\033[0m"<<"\x1B[34m"<<cash<<"\033[0m";
    cout<<"\n\x1B[34mCash returned\033[0m"<<"\x1B[34m"<<setw(61)<<"RS "<<"\033[0m"<<"\x1B[34m"<<cash-(total-discount)<<"\033[0m";
    cout<<"\n\x1B[34m*************************************************************************************\033[0m";
    //Ending parts of reciept including Thank you note.
    cout<<"\n\n\n\n\n\n";
    cout<<"                        \x1B[34mTHANK YOU\033[0m\n";                                                          
    cout<<"                        \x1B[34mFOR COMING\033[0m\n";
    cout<<"                     \x1B[34mTO OUR SHOWROOM\033[0m\n";
    cout<<"                       \x1B[34mPLEASE COME\033[0m\n";
    cout<<"                        \x1B[34mBACK SOON\033[0m\n\n\n\n\n\n";
}


//file reading function for integer values
void ireadFun(ifstream &file, string file_name, int sarr[],int &size,int &type )
{
    file.open(file_name);
    //condition will be true if file does not exist.
    if (file.fail())
    {
        cerr<<"Error in file opening "<<endl;
        exit (1);
    }
    //loops runs uotil the file ends.
    while (!file.eof())
    {
        file>>type;
        sarr[size]=type;
        size++;
    }
    file.close();
}  

//file reading function for strings 
void sreadFun(ifstream &file, string file_name, string array[],int &counter2,string &type )
{ 
    file.open(file_name);
    //condition will be true if file does not exist.
    if (file.fail())
    {
        cerr<<"Error in file opening "<<endl;
        exit (1);
    }
    //loops runs uotil the file ends.
    while (!file.eof())
    {
        file>>type;
        array[counter2]=type;
        counter2++;
    }
    file.close();
}  

//file writing function for integer values
void writeFun(ofstream &file, string file_name, int array[], int &size)
{              
    file.open(file_name);  
    //writing values in file from arrays
    for (int s=0;s<size-1;s++)
    {
        int c=array[s];
        file<<c<<endl;
    } 
    file.close();
}                                 


int main()
{

    //reading inventory file  
    int sale =0;        
    int counter2=0;
    int sarr[100]={0};
    ifstream sfile;
    ireadFun(sfile,"inventory.txt",sarr,counter2,sale);

    //reading credentials file
    int counter1=0;
    string carr[100];
    string credentials;
    ifstream cfile;
    sreadFun(cfile,"credentials.txt",carr,counter1,credentials);
    
    // reading items file
    string item;
    string arr[100];
    int count=0;
    ifstream infile;
    sreadFun(infile,"items.txt",arr,count,item);

    // reading prices file
    int price;
    int parr[100];
    int counter=0;
    ifstream pfile;
    ireadFun(pfile,"price.txt",parr,counter,price);

    // reading membership file
    string id;
    string marr[100];
    int counter3=0;
    ifstream mfile;
    sreadFun(mfile,"membership.txt",marr,counter3,id);

    //interface for our items detail to inform about items and thier repective prices, with color coding.
    string i= "ITEMS";
    string r="RATE";
    cout<<"\n"<<"\x1B[34m"<<setw(42)<<"* WELCOME TO J.F ENTERPRISES *"<<"\033[0m"<<endl;
    cout<<"\x1B[34m"<<setw(46)<<"--------------------------------------"<<"\033[0m\n"<<"\x1B[34m"<<setw(18)<<i<<"\033[0m"<<"\t"<<"\x1B[34m"<<setw(16)<<r<<"\033[0m"<<endl<<"\x1B[34m"<<setw(46)<<"--------------------------------------"<<"\033[0m"<<endl<<endl;
    for (int f= 0; f<count;f++)
    {
        cout<<"\x1B[34m"<<setw(10)<<"("<<"\033[0m"<<"\x1B[34m"<<arr[f]<<"\033[0m"<<"\t"<<"\x1B[34m"<<" Rs. "<<"\033[0m"<<"\x1B[34m"<<parr[f]<<"\033[0m"<<endl<<endl;
       
    }

    //Checking if the user is an employee or not by validating email and password

    cout<<"Are you an employee? [Y/N]\n";
    string add=" ";
    string employee=" ";
    cin>>employee;
    string email;
    int valid1=1;
    int valid2=0;
    if (employee=="Y")
    {
        do
        {
            cout<<"Enter your email: ";                 
            cin>>email;
            if (email.substr(email.length()-4)!=".com")     //validating the email of an employee for".com"
            {
              valid1=1;
            }
            else
            {
                valid1=0;
            }
            for (int i=0;i<email.length();i++)
            {
               if (email.substr(i,1)=="@")                  //validating the email of an employee for"@"
                {
                    valid2=0;
                }
            }
            if (valid2==1)
            {
                cout<<"missing @"<<endl;
            }  
        } while (valid1||valid2);

        //validating the password of an employee

        string password=" ";
        bool matched=false;
        int g;
        for(g=0;g<counter1;g++)
        {
            //prompting user to enter password if email matches with database
            if(email==carr[g])     
            {
                cout<<"email matched! \n "<<endl;
                cout<<"Enter your password: ";
                cin>>password;
                matched=true;
                break;
            } 
            g++;
        }
        bool matched1=false;
        if (matched==false)
        {
            cout<<"Wrong email \nEntry denied!"<<endl;
        }
        if(password==carr[g+1])
        {
          cout<<"You are verified \n"<<endl;
          matched1=true;
        }
        //Programs asks for willingness to add inventory after both email and corresponding password is matched.
        
        if(matched && matched1)
        {
        cout<<"Do you want to add something in the inventory [Y/N]?\n";
        string add2="Y";
        cin>>add;
        //Program only enters the loop if user enters "Y" for willingness to enter and exits when user enter "N" for add1
        while(add=="Y" && add2=="Y")
        {
            cout<<"\nEnter the corresponding number of item you want to add\n";
            string item2;
            cin>>item2;
            cout<<"\nEnter the quantity\n";
            int quantity2;
            cin>>quantity2;
            for (int f=0; f<count; f++)
            {
                if (arr[f].substr(0,1)==item2)
                {   

                    sarr[f]=sarr[f]+quantity2;
                }
            }
            cout<<"\nDo you want to add something else in the inventory [Y/N]\n";
            cin>>add2;    
        }
        }
    }

    
    //Option for the user to enter the items and its quantity he wants to buy

    if(add=="N" || employee=="N")            //if statement so that if employee wants to add inventory and doesn't want to bill something. Also if user is a customer and not an employee
    {

        string item1=" ";
        cout<<"\nEnter the corresponding number of item you want to buy otherwise 'Nothing'"<<endl;
    
        cin>>item1;
        int qarr[100]={0};
        int quantity1;
        int totalbill=0;
        int price1=0;

        for (int i=0;i<count;i++)                       //this for loop allows us to continue taking more number of inputs for items and their respective quantities 
        {
            while (item1==arr[i].substr(0,1))           //this line of code of while matches the entered item with our inventory items and continues to taking quantity and calculating the bill.
            {  
                cout<<"\nEnter quantity"<<endl;
               cin>>quantity1;
               //checking whether user is entering quantity 
               if (quantity1>sarr[i])
                {
                    cout<<"Out of stock"<<endl;
                    cout<<"Enter new item\n";
                    cin>>item1;
                    i=0;
                    continue;
                }
                // to add two quantities of same item.
                qarr[i]=qarr[i]+quantity1;
                //Substr command is used to simplify the process of choosing an item by the user. Inventory of the item is reduced in the array.
                for (int f=0; f<count; f++)       
                {
                    if (arr[f].substr(0,1)==item1)
                    {   

                      sarr[f]=sarr[f]-quantity1;
                    }
               }    
               //corresponding prices are put into a variable to ease calculation of total bill
                for (int f= 0; f<count;f++)          
                {
                   if (arr[f].substr(0,1)==item1)
                    {
                        price1=parr[f];
                   }     
                }
                totalbill=totalbill+quantity1*price1;
                cout<<"\nEnter the corresponding number of item you want to buy otherwise 'Nothing'"<<endl;
                cin>>item1;
                i=0;                                 //i=0 so that items could be entered in any sequence that can be different from the sequence given in our "items.txt" file
            }
        }
        //Discount for members

        double discount=0;
        double discount_rate=0;

        if (totalbill>0)
        {
            string d=" ";
            
            cout<<"\nIs membership discount applicable? [Y/N]?\n";
            string member;
            cin>>member;                                                                    
            if(member=="Y")
            {
                cout<<"\nEnter membership code: ";
                string number;
                cin>>number;
                //use of substr command to determine which discount applies.
                for(int b=0;b<counter3;b++)
                {
                    if(marr[b]==number)
                    {
                        d=marr[b].substr(0,1);
                    }
                }
                //if mebership code starts with R then 20% discount very special customer is given
                if(d=="R")                  
                {
                    discount_rate=0.2;
                    cout<<"\n20% discount given"<<endl;
               
                }
                //if membership code starts with P then 10% discount special customer is given
                else
                {
                   discount_rate=0.1;
                   cout<<"\n10% discount given"<<endl;
                }
            }       
            discount=totalbill*discount_rate;
            cout<<"\nDiscount is "<<discount<<endl;
            cout<<"\nTotal bill is "<<totalbill<<endl;
            
        }
        //incorporating discount and ensuring that cash paid is not less than the total bill.
        double cash=0;     
        if(totalbill>0)
        {
        
            cout<<"\nInput Cash paid: ";
            cin>>cash;
            while(cash<totalbill-discount)
            {
                cout<<"\nCash is less by "<<totalbill-discount-cash<<" Please re-enter: ";
                cin>>cash;
            }
        //receipt function is called
        receiptFun(arr,parr,qarr,count,cash,totalbill,discount);
        }
    }
    //new inventory levels are written on the file "inventory.txt"
    ofstream outfile;   
    writeFun(outfile,"inventory.txt",sarr,counter2);
}
