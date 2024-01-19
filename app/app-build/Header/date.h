#ifndef DATE_H
#define DATE_H

// IMPORTS -----

#include <iostream>
//#include <list>
//#include <string>
#include <ctime>

//some kind of json black magic happening here

//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;


// ------

/*
    Date class definition file:
    Stores information on day, month, year
    Use cases: expiry dates, seeing when an item was added to the fridge, history of trades on the marketplace?
*/

class Date {
public:
    //FUNCTIONS

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

    // overloaded operators to compare two date objects together and say which was before/after.
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;

    Date parseDateString(const std::string& dateString);

    int is_exp_date();
    //bool isLeapYear(int y) const;
    int countDays() const;

private:

    //DATA MEMBERS
    int day;
    int month;
    int year;
};

#endif // DATE_H
