#include <iostream>
#include <fstream>

using namespace std;

void intro();
void write_account();
void display ();
void delete_account();
void display_all();
void deposit_withdraw(int, int);


string password;
string name;
int balance = 0;

int main() {
    int choice;

    cout << "Enter name:" << endl;
    cin >> name;
    cout << "Enter password:" << endl;
    cin >> password;


    while (true)
    {
        intro();
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid option" << endl;
            break;
        }


        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
            case 1:
                write_account();
                break;
            case 2:
                display();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                display_all();
                break;
            case 5:
                cout << "Enter 1 to deposit to accout." << endl;
                cout << "Enter 2 to withdraw from account." <<endl;
                cout << "Enter any thing else to cancel and go back." <<endl;
                int deposit_withdraw_op;
                cin >> deposit_withdraw_op;

                if (cin.fail())
                {
                    cout << "Invalid option" << endl;
                    break;
                }
                
                if(deposit_withdraw_op == 1 || deposit_withdraw_op == 2)
                {
                    int amount;
                    cout << "Enter amount for transaction:" <<endl;
                    cin >> amount;
                    deposit_withdraw(deposit_withdraw_op, amount);
                }
                break;
            default:
                cout << "Invalid option" << endl;
                continue;
        }
        cout << "\n" << endl;
    }
    return 0;
}

void intro()
{
    cout << "Enter 1 to write a record of the account." << endl;
    cout << "Enter 2 to display account details." << endl;
    cout << "Enter 3 to delete record of the account." << endl;
    cout << "Enter 4 to display all details of the account." << endl;
    cout << "Enter 5 to deposit or withdraw from an account." << endl;
    cout << "Enter 0 to end the program" << endl;
}

void write_account()
{
    ofstream bank_file;
    bank_file.open(name+".abm");
    bank_file << name << endl;
    bank_file << password << endl;
    bank_file << balance << endl;
    bank_file.close();
}

void display()
{
    cout << "Name:" << name <<  endl;
    cout << "Password:" << password <<  endl;
}

void delete_account()
{
    string file_name = name+".abm";
    if( remove( file_name.c_str() ) != 0 )
        perror( "Error deleting file" );
    else
        cout << "File successfully deleted" << endl;
}

void display_all()
{
    cout << "Name:" << name <<  endl;
    cout << "Password:" << password <<  endl;
    cout << "Balance:" << balance << endl;
}

void deposit_withdraw(int op, int amount)
{
    if(op == 1)
    {
        balance += amount;
    }
    else
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Not enough money in account to withdraw " << amount <<endl;
        }
    }
}
