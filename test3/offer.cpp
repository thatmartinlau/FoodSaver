#include "offer.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//OFFERme

/*
Offer::Offer(Ingredient ingredient_on_offer) {
    this->ingredient_on_offer = ingredient_on_offer;
    price = 0.0;
    quantity = 0;
    User u;
    username = u;
}
*/

Offer::~Offer() {
}

bool Offer::operator==(Offer& other) {
    return (this->get_ingredient() == other.get_ingredient());
}

void Offer::set_price(double price) {
    this->price = price;
}

double Offer::get_price() {
    return price;
}

void Offer::set_quantity(int q) {
    this->quantity = q;
}

int Offer::get_quantity() {
    return quantity;
}

void Offer::set_ingredient(Ingredient i) {
    this-> ingredient_on_offer = i;
}

Ingredient Offer::get_ingredient() {
    return ingredient_on_offer;
}

/*
std::vector<Ingredient> Offer::sort_offers_by_category() {
    std::vector<Ingredient> sorted_list = ingredient_list;
    std::sort(sorted_list.begin(), sorted_list.end(),
              [](Ingredient& a, Ingredient& b) {
                  return a.get_food_class_name() < b.get_food_class_name();
              }
              );
    return sorted_list;
}

std::vector<Ingredient> Offer::sort_offers_by_expiration_date() {
    std::vector<Ingredient> sorted_list = ingredient_list;
    std::sort(sorted_list.begin(), sorted_list.end(),
              [](Ingredient& a, Ingredient& b) {
                  return a.get_expiry_date() < b.get_expiry_date();
              }
              );
    return sorted_list;
}

std::vector<Ingredient> Offer::sort_offers_by_price() {
    std::vector<Ingredient> sorted_list = ingredient_list;
    std::sort(sorted_list.begin(), sorted_list.end(),
              [](Ingredient& a, Ingredient& b) {
                  return a.get_price() < b.get_price();
              }
              );
    return sorted_list;
}
*/
