#ifndef DATE_H
#define DATE_H

#include <iostream>
//#include <list>
//#include <string>
#include <ctime>

//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class Date {
public:
    // Constructor with current date
    Date();
    Date(int d, int m, int y);
    void displayDate();
    int get_day();
    void set_day(int d);
    int get_month();
    void set_month(int m);
    int get_year();
    void set_year(int y);
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    int is_exp_date();
    //bool isLeapYear(int y) const;
    int countDays() const;

private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
