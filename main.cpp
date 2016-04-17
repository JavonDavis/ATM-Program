#include <iostream>

using namespace std;

void intro();
void write_account();
void display (int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main() {
    int choice;

    while (true)
    {
        intro();
        cin >> choice;
        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
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
    cout << "Press 1 to write a record of the account." << endl;
    cout << "Press 2 to display account details." << endl;
    cout << "Press 3 to delete record of the account." << endl;
    cout << "Press 4 to display all details of the account." << endl;
    cout << "Press 5 to deposit or withdraw from an account." << endl;
    cout << "Press 0 to end the program" << endl;
}