#include "SalesPerson.h"

int main()
{
    SalesPerson s1;
    int employeeId;
    char choice;

    do
    {
        cout << "What do you want to do Enter\nA:Enter the Records and store to file\nB:Check the Emoplyee with highest sales:"<<endl;
        cin >> choice;
        switch (choice) {
        case 'a':
            cout << "Enter employee ID: ";
            cin >> employeeId;

            s1.setID(employeeId);
            s1.getSalesFromUser();
            s1.printAnnualSales();
            SalesPerson::writeToFile(s1);
            break;
        case 'b':
            cout << "Employee with the highest sales:\n";
            s1.Calculatehighest();
            break;
        }
       cout << "Do you want to run the program again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    return 0;
}