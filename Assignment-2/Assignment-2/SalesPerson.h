#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class SalesPerson
{
public:
    static const int monthsPerYear = 12; // months in one year
    SalesPerson(); // constructor
    void getSalesFromUser(); // input sales from keyboard
    void setSales(int, double); // set sales for a specific month
    void printAnnualSales(); // summarize and print sales
    static void writeToFile(SalesPerson);
    int getID();
    void setID(int);
    void Calculatehighest();
private:
    double sales[monthsPerYear]; // 12 monthly sales figures
    double totalAnnualSales();
    int employeeID;
};

