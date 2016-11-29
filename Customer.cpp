/*********************************************************************
** Author:			Erik Heaney
** Date:			11/28/2016
** Description:		This is the class implementation file for the Customer
					class. 
*********************************************************************/
#include "Customer.hpp"
#include <vector>


/*********************************************************************
** Customer()
** This is the constructor.
*********************************************************************/
Customer::Customer(std::string n, std::string a, bool pm) {
	name = n;
	accountID = a;
	premiumMember = pm;
}


/*********************************************************************
** getAccountID()
** This is the getter for the member ID.
*********************************************************************/
std::string Customer::getAccountID() {
	return accountID;
}


/*********************************************************************
** getCart()
** This is the getter for the member's cart.
*********************************************************************/
std::vector<std::string> Customer::getCart() {
	return cart;
}


/*********************************************************************
** addProductToCart()
** This adds a product's title to the customer's cart.
*********************************************************************/
void Customer::addProductToCart(std::string p) {
	cart.push_back(p);
}


/*********************************************************************
** isPremiumMember()
** This is the getter for premium (returns true if premium member).
*********************************************************************/
bool Customer::isPremiumMember() {
	return premiumMember;
}


/*********************************************************************
** emptyCart()
** This function emptys the member's cart.
*********************************************************************/
void Customer::emptyCart() {
	cart.clear();
}