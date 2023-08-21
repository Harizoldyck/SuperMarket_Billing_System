#include<iostream>
#include<fstream>///////////////////////////////

using namespace std;/////////////////////////////////////


//class for shopping
class shopping
{
    private:
        int pcode;           //product code
        float price;         //product price
        float dis;           //discount of product
        string pname;        //product name

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};


//Main menu function
void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_______________________________________________________\n";
    cout << "\t\t\t\t                                                       \n";
    cout << "\t\t\t\t                  Supermarket Main Menu                \n";
    cout << "\t\t\t\t                                                       \n";
    cout << "\t\t\t\t_______________________________________________________\n";        
    cout << "\t\t\t\t                                                       \n";
    cout << "\t\t\t\t      1) Administrator         |\n";
    cout << "\t\t\t\t                               |\n";
    cout << "\t\t\t\t      2) Buyer                 |\n";
    cout << "\t\t\t\t                               |\n";
    cout << "\t\t\t\t      3) Exit                  |\n";
    cout << "\n\n\t\t\t Please select!";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "\t\t\t Please Login   \n";
            cout << "\t\t\t Enter Email    :";
            cin >> email;
            cout << "\t\t\t Password       :";
            cin >> password;

            if(email == "admin@gmail.com" && password == "admin@123")
            {
                administrator();
            }
            else
            {
                cout << "Invalid Email/Password !!!\n\n";
                break;
            }
        }

        case 2:
        {
            buyer();
        }

        case 3:
        {   
            exit(0);
        }

        default :
        {
            cout << "Please select from given options!\n\n";
        }
    }

    goto m;

}

////////////////////////////////////////////--administrator--////////////////////////////////////////////////////////////////////////////////////////////////////

void shopping:: administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t\t\t        Administrator Menu             \n";
    cout << "\t\t\t\t|___________1) Add the product__________|\n";
    cout << "\t\t\t\t|                                       |\n";
    cout << "\t\t\t\t|___________2) Modify the product_______|\n";
    cout << "\t\t\t\t|                                       |\n";
    cout << "\t\t\t\t|___________3) Delete the product_______|\n";
    cout << "\t\t\t\t|                                       |\n";
    cout << "\t\t\t\t|___________4) Back to Main Menu________|\n";
    
    cout << "\n\n\t\t\t Please select! :";
    cin >> choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default :
            cout << "Invalid Choice \n\n";
    }

    goto m;
}

//////////////////////////////////////////--buyer--/////////////////////////////////////////////////////////////////////////////////////////

void shopping::buyer()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t           Buyer    \n";
    cout << "\t\t\t___________________________\n";
    cout << "                                 \n";
    cout << "\t\t\t  1) Buy product           \n";
    cout << "\t\t\t                           \n";
    cout << "\t\t\t  2) Go Back               \n";
    cout << "\t\t\t  Enter your choice  :  ";

    cin >> choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;

        default:
            cout << "Invalid choice!!! \n\n";
    }

    goto m;
}

///////////////////////////////////////--add--/////////////////////////////////////////////////////////////////////////////////////////////

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t    Add the Product   \n";
    cout << "\n\n\t Enter product code of the product :";
    cin >> pcode;
    cout << "\n\n\t Enter product name :";
    cin >> pname;
    cout << "\n\n\t Enter price of the product :";
    cin >> price;
    cout << "\n\n\t Enter discount of the product :";
    cin >> dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if(token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app|ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }

    }
    cout << "\n\n\t\t\t  Record Inserted! \n\n";

}

/////////////////////////////////////--edit--//////////////////////////////////////////////////////////////////////////////////////////////////

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t    Modify the Product   \n";
    cout << "\n\n\t Enter product code of the product :";
    cin >> pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout << "\n\nFile doesn't exist !!!\n\n";
    }
    else
    {
        data1.open("database.txt",ios::app|ios::out);

        data >> pcode >> pname >>price >> dis;
        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout << "\n\n\t Enter new product code of the product :";
                cin >> c;
                cout << "\n\n\t Enter product name :";
                cin >> n;
                cout << "\n\n\t Enter price of the product :";
                cin >> p;
                cout << "\n\n\t Enter discount of the product :";
                cin >> d;    

                data << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t Record edited!\n\n";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

            }
            data >> pcode >> pname >>price >> dis;

        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << "\n\n Record not found sorry!\n\n";
        }
    }
}

///////////////////////////////--rem(remove)--///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\n\t\t    Delete Product   \n";
    cout << "\n\n\t Enter product code of the product :";
    cin >> pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout << "\n\nFile doesn't exist !!!";
    }
    else
    {
        data1.open("database.txt",ios::app|ios::out);

        data >> pcode >> pname >>price >> dis;
        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout << "\n\n\t   Product deleted successfully! \n\n";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

            }
            data >> pcode >> pname >>price >> dis;

        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << "\n\n Record not found sorry!\n\n";
        }

    }
}

////////////////////////////////--list--/////////////////////////////////////////////////////////////////////////////////////////////////////////

void shopping:: list()
{
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n|_____________________________________________________________________________|\n";
    cout << "Pro.No\t\tName\t\t\tPrice\n";
    cout << "\n\n|_____________________________________________________________________________|\n";
    data >> pcode >> pname >> price >> dis;

    while(!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }

    data.close();
}

///////////////////////////////--receipt--//////////////////////////////////////////////////////////////////////////////////////

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT    ";
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout << "\n\n \t\t Empty database! \n";

    }
    else
    {
        data.close();

        list();
        cout << "\n|________________________________________________________________________|\n";
        cout << "\n|                                                                        |\n";
        cout << "\n|                      Please place the order                            |\n";
        cout << "\n|                                                                        |\n";
        cout << "\n|________________________________________________________________________|\n";

        do
        {
            m:
            cout << "\n\n Enter Product Code :";
            cin >> arrc[c];

            cout << "\n\n Enter the product quantity :";
            cin >> arrq[c];

            for(int i = 0;i < c;i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again!\n\n";
                    goto m;
                }
    
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press 'y' else press 'n' : ";
            cin >> choice;
        } 
        while (choice == 'y');

        cout << "\n\n\t\t\t|____________________________RECEIPT__________________________________|\n";
        cout << "\nProduct No \t Product Name \t Product quantity \t price \t\t Amount \t Amount with discount \n";

        for(int i = 0;i < c;i++)
        {
            data.open("database.txt",ios::in);
            data >> pcode >> pname >> price >> dis;

            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }

        data.close();
    }

    cout << "\n\n|_________________________________________________________________________________________|\n";
    cout << "\n\t\t Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
}