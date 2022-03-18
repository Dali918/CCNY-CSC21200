// Dalitso Banda CSC21200 | Homework 3 Problem 1
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/*A date class is described by month(m), day(d), year(y). A finance bond is described
by a unique name (e.g. “GW Bridge”), principal(P=1000), annual interest
rate(r=0.05), issue date(06,01, 2021), maturity date (06, 01, 2031). Calculate the
Principal at maturity date. Recognize that composition is present in the instantiation
of a bond. Make sure to include all proper constructors, destructors, assignment
operators for the date and bond classes.*/

// Date Class
class Date
{
private:
    int month, day, year;

public:
    // constructors and destructor
    Date() {}
    Date(const Date &date);
    Date(int m, int d, int y) : month{m}, day{d}, year{y} {}
    ~Date() { cout << "Destructing Date" << endl; }
    // getter functions
    int getMonth() const { return this->month; }
    int getDay() const { return this->day; }
    int getYear() const { return this->year; }
    // operator overloaded functions for arithmetic and I/O manipulation
    Date &operator=(const Date &date);
    friend Date operator+(Date &left, Date &right);
    friend Date operator-(Date left, Date &right);
    friend istream &operator>>(istream &is, Date &date);
    friend ostream &operator<<(ostream &os, const Date &date);
};

// Bond Class
class Bond
{
private:
    string name;
    double principal, rate;
    Date issueDate, maturDate;

public:
    // Constructors and Destructors
    Bond() {}
    Bond(const Bond &bond);
    Bond(string name, double princip, double r, const Date &issue, const Date &matur) : name{name}, principal{princip}, rate{r / 100}, issueDate{issue}, maturDate{matur} {};
    ~Bond() { cout << "Destructing Bond" << endl; }
    // getter functions
    string getName() const { return name; }
    double getPrincipal() const { return principal; }
    double getRate() const { return rate; }
    const Date& getIssueDate() const { return issueDate; }
    const Date& getMaturityDate() const { return maturDate; }
    // operator overloading
    Bond &operator=(const Bond &bond);
};

// const int monthDays[12] = {31, 28, 31, 30, 31, 30,

//                            31, 31, 30, 31, 30, 31};

// function to count the number of leap years/days
int countLeap(int yearOne, int yearTwo)
{
    /*A year is leap if it is divisble by (4 and not divisible by 100) or divisible by 400 */
    int count = 0;
    for (int i = yearOne; i < yearTwo; ++i)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            count++;
        }
    }

    return count;
}

double calcYears(const Date &issueDate, const Date &maturDate)
{
    // Get the number of days in the range then convert to years and return the calculated value
    int leapDays = countLeap(issueDate.getYear(), maturDate.getYear()); // Number of Leap Years == Number of Leap Days
    int years = maturDate.getYear() - issueDate.getYear();              // Number of years
    int monthDays = maturDate.getMonth() - issueDate.getMonth();        // Number of months * 31 to turn to days
    int days = maturDate.getDay() - issueDate.getDay();                 // Number of days

    return ((years * 365) + (monthDays * 31) + leapDays) / 365; // return the number of days expressed as years
}

double calculatePrincipalMaturity(Bond &bond)
{
    int time = calcYears(bond.getIssueDate(), bond.getMaturityDate());
    return bond.getPrincipal() * pow(1 + bond.getRate(), time);
}

int main()
{
    string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /************ *****************************/

    string bondName;
    double bondPrincip, bondRate;
    Date issueDate, maturityDate;
    cout << fixed << setprecision(2);
    cout << "Enter the bond name, principal and rate in the format: \"Bond Name\" \"principal\" \"rate (%)\"" << endl;
    cin >> bondName >> bondPrincip >> bondRate;
    cout << "Enter the issue date in the format: dd mm yyyy" << endl;
    cin >> issueDate;
    cout << "Enter the maturity data in the format: dd mm yyyy" << endl;
    cin >> maturityDate;
    cout << "------------------You entered:-----------------" << endl;
    cout << "Bond Name:" << bondName << endl;
    cout << "Bond principal: $" << bondPrincip << endl;
    cout << "Bond rate: " << bondRate << endl;
    // priniting the issue date and the maturity date
    cout << "Issue Date:" << endl;
    cout << issueDate;
    cout << "Maturity Date:" << endl;
    cout << maturityDate;
    cout << endl;

    // make bond and calculate the principal maturity
    Bond newBond(bondName, bondPrincip, bondRate, issueDate, maturityDate);
    double maturityPrincipal = calculatePrincipalMaturity(newBond);
    cout << "Calculated Maturity Principal: $" << maturityPrincipal << endl;
    cout << endl;
}

/*-----------------------------------------CLASS FUNCTION DEFINITIONS---------------------------------------------------------------*/
/*CONSTRUCTORS*/
// Date Class copy constructor defintion
Date::Date(const Date &date)
{

    this->day = date.day;
    this->year = date.day;
    this->month = date.month;
}

Bond::Bond(const Bond &bond)
{
    this->name = bond.name;
    this->principal = bond.principal;
    this->rate = bond.rate;
    this->issueDate = bond.issueDate;
    this->maturDate = bond.maturDate;
}

/*CLASS OPERATOR OVERLOADING*/
//Date Class Assignment overloading
Date &Date::operator=(const Date &date)
{
    if (this != &date)
    {
        this->day = date.day;
        this->year = date.day;
        this->month = date.month;
    }

    return *this;
}
//Bond assignment operator overloading
Bond &Bond::operator=(const Bond &bond)
{
    if (this != &bond)
    {
        this->name = bond.name;
        this->principal = bond.principal;
        this->rate = bond.rate;
        this->issueDate = bond.issueDate;
        this->maturDate = bond.maturDate;
    }
    return *this;
}
// arithmetic operator overloading
Date operator+(Date &left, Date &right)
{
    return Date(left.getDay() + right.getDay(), left.getMonth() + right.getMonth(), left.getYear() + right.getYear());
}
Date operator-(Date &left, Date &right)
{
    return Date(left.getDay() - right.getDay(), left.getMonth() - right.getMonth(), left.getYear() - right.getYear());
}

// input - output stream operator overloading
ostream &operator<<(ostream &os, const Date &date)
{
    cout << "{Day: " << date.day
         << " Month: " << date.month
         << " Year: " << date.year << "}" << endl;
    return os;
}

istream &operator>>(istream &is, Date &date)
{
    is >> date.day >> date.month >> date.year;
    return is;
}

