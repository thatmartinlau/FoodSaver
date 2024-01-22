#include "../Header/date.h"

#include <iostream>
#include <sstream>

//#include "front.hpp"
//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

// DATE

// By default, construct with current time

Date::Date() {
    time_t t = time(0);   // Get current time
    tm* now = localtime(&t);

    day = now->tm_mday;
    month = now->tm_mon + 1;  // tm_mon is zero-based
    year = now->tm_year + 1900;  // tm_year is years since 1900
}


Date::Date(int d, int m, int y) : day(d), month(m), year(y){
}

void Date::displayDate() {
    std::cout << "Date: " << year << '-' << month << '-' << day << std::endl;
}

int Date::get_day() {
    return day;
}

void Date::set_day(int d) {
    this->day = d;
}

int Date::get_month() {
    return month;
}

void Date::set_month(int m) {
    this->month = m;
}

int Date::get_year() {
    return year;
}

void Date::set_year(int y) {
    this->year = y;
}

// Overload the < operator
bool Date::operator<(const Date& other) const {
    if (year < other.year)
        return true;
    if (year > other.year)
        return false;
    if (month < other.month)
        return true;
    if (month > other.month)
        return false;
    return day < other.day;
}

// Overload the == operator
bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

// Overload the != operator
bool Date::operator!=(const Date& other) const {
    return !(*this == other); // Utilize the == operator
}

///______________________________________________________________________///

bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static int daysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

static int daysInMonthForYear(int month, int year) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

static int daysFromEpoch(int d, int m, int y) {
    int days = d;
    for (int k = 1; k < y; ++k) {
        days += daysInYear(k);
    }
    for (int l = 1; l < m; ++l) {
        days += daysInMonthForYear(l, y);
    }
    return days;
}

///______________________________________________________________________///

// returns numbre of days between today and the expiration date
int Date::countDays() const {
    time_t t = time(0);   // Get current time
    tm* now = localtime(&t);

    int today_day = now->tm_mday;
    int today_month = now->tm_mon + 1;  // tm_mon is zero-based
    int today_year = now->tm_year + 1900;  // tm_year is years since 1900
    return daysFromEpoch(day, month, year) - daysFromEpoch(today_day, today_month, today_year);
}

Date parseDateString(const std::string& dateString) {
    std::istringstream ss(dateString);
    char delimiter;

    int day, month, year;

    // Read day, month, and year from the string
    ss >> day >> delimiter >> month >> delimiter >> year;

    // Check if the extraction was successful and the format is correct
    if (ss.fail() || delimiter != '/' || ss.rdbuf()->in_avail() != 0) {
        throw std::invalid_argument("Invalid date string format: " + dateString);
    }

    // Check if the components are within valid ranges (you can customize this part)
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        throw std::out_of_range("Invalid date components in: " + dateString);
    }

    return Date(day, month, year);
}
