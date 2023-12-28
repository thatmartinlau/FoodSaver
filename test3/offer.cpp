#include "offer.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//OFFER
Offer::Offer(std::vector<Ingredient> ingredient_list) {
    this->ingredient_list = ingredient_list;
    price = (double) 0;
}

Offer::~Offer() {
}

void Offer::set_price(double price) {
    this->price = price;
}

double Offer::get_price() {
    return price;
}

std::vector<Ingredient> Offer::get_ingredient_list() {
    return ingredient_list;
}
