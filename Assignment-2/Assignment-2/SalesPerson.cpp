
#include "SalesPerson.h"
#include<fstream>
SalesPerson::SalesPerson() {
    for (int i = 0; i < monthsPerYear; ++i)
        sales[i] = 0.0;
}

void SalesPerson::getSalesFromUser() {
    double salesFigure;

    for (int i = 1; i <= monthsPerYear; ++i) {
        std::cout << "Enter sales amount for month " << i << ": ";
        std::cin >> salesFigure;
        setSales(i, salesFigure);
    }
}

void SalesPerson::setSales(int month, double amount) {
    if (month >= 1 && month <= monthsPerYear && amount > 0)
        sales[month - 1] = amount;
    else
        std::cout << "Invalid month or sales figure" << std::endl;
}

void SalesPerson::printAnnualSales() {
    std::cout << std::setprecision(2) << std::fixed
        << "\nThe total annual sales are: $" << totalAnnualSales() << std::endl;
}

double SalesPerson::totalAnnualSales() {
    double total = 0.0;
    for (int i = 0; i < monthsPerYear; ++i)
        total += sales[i];
    return total;
}

void SalesPerson::setID(int employeeID) {
    this->employeeID = employeeID;
}

int SalesPerson::getID() {
    return employeeID;
}

void SalesPerson::writeToFile(SalesPerson s) {
    ofstream fout;
    fout.open("Sales.txt", std::ios::app);
    if (fout.is_open()) {
        fout << s.getID() <<endl;
        for (int i = 0; i < monthsPerYear; ++i)
        fout<< s.sales[i] <<endl;
       
        fout.close();
        cout << "Sales record saved to file." <<endl;
    }
    else {
        cout << "File is not available" << endl;
    }
   
}
void SalesPerson::Calculatehighest() {
    ifstream fin;
    fin.open("Sales.txt");
    double highestsales=0;
    double sale;
    int sumofsales=0;
    int empid;
    int empWmaxSales=0;
    while (fin >> empid) {
        for (int i = 0; i < monthsPerYear; i++) {
            fin >> sale;
            sumofsales += sale;
        }
        if (sumofsales > highestsales) {
            highestsales = sumofsales;
            empWmaxSales = empid;
        }
    }
    if (highestsales > 0) {
        cout << "EmployeeID with highest sale is: " << empWmaxSales << endl;
        cout << "The Sales done are: " << highestsales << endl;
    }
    else {
        cout << "No record found" << endl;
    }
    fin.close();
}
