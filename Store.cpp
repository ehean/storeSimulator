/*********************************************************************
** Author:			Erik Heaney
** Date:			11/28/2016
** Description:		This is the class implementation file for the 
					Store class.
*********************************************************************/

#include "Store.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

/*********************************************************************
** addProduct()
** This function adds a Product object to the inventory.
*********************************************************************/
void Store::addProduct(Product* p) {
	inventory.push_back(p);
}


/*********************************************************************
** addMember()
** This function adds a Member object to members.
*********************************************************************/
void Store::addMember(Customer* c) {
	members.push_back(c);
}


/*********************************************************************
** getProductFromID()
** This function takes a product ID as an argument, and if it exists
** in the inventory, returns the product object.
*********************************************************************/
Product* Store::getProductFromID(std::string p) {
	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getIdCode() == p)
			return inventory[i];
	}

	return NULL;
}


/*********************************************************************
** getMemberFromID()
** This function takes a member ID as an argument, and if it exists in
** the inventory, returns the member object.
*********************************************************************/
Customer* Store::getMemberFromID(std::string m) {
	for (size_t i = 0; i < members.size(); i++) {
		if (members[i]->getAccountID() == m) {
			return members[i];
		}
	}

	return NULL;
}


/*********************************************************************
** productSearch()
** This function takes a string as an argument and performs a text search
** in the inventory. If it finds a match, it prints the product details.
*********************************************************************/
void Store::productSearch(std::string str) {
	bool found = false;
	// set all characters of search string to lower case
	std::string str_lower;
	std::transform(str_lower.begin(), str_lower.end(), str_lower.begin(), ::tolower);
	for (size_t i = 0; i < inventory.size(); i++) {	
		// create temp title and description and make all characters lower case
		std::string title = inventory[i]->getTitle();
		std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		std::string description = inventory[i]->getDescription();
		std::transform(description.begin(), description.end(), description.begin(), ::tolower);
		// if str found in title or description, print details
		if (title.find(str_lower) != std::string::npos || description.find(str_lower) != std::string::npos) {
			found = true;
			std::cout << "\n" << inventory[i]->getTitle() << "\n";
			std::cout << "ID Code: " << inventory[i]->getIdCode() << "\n";
			std::cout << "Price: " << inventory[i]->getPrice() << "\n";
			std::cout << inventory[i]->getDescription() << "\n";
		}
	}
	if (!found)
		std::cout << "\n0 Search results.\n";
}


/*********************************************************************
** addProductToMemberCart()
** This function takes a product ID and member ID as arguments and
** verifies that:
**		- product ID is in inventory
**		- member ID is in members and
**		- product is not sold out.
** If that's the case, product is added to the member's cart. If not,
** a error validation message prints.
*********************************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID) {
	bool productFound = false,
		memberFound = false,
		prodAvail = false;
	int memberIndex = 0, inventoryIndex = 0;

	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getIdCode() == pID) {
			productFound = true;
			inventoryIndex = i;
		}
		if (inventory[i]->getQuantityAvailable() > 0)
			prodAvail = true;
	}

	for (size_t i = 0; i < members.size(); i++) {
		if (members[i]->getAccountID() == mID) {
			memberFound = true;
			memberIndex = i;
		}
	}

	if (!productFound)
		std::cout << "\nProduct #" << pID << " not found.\n";
	else if (!memberFound)
		std::cout << "\nMember #" << mID << " not found.\n";
	else if (!prodAvail)
		std::cout << "\nSorry, product #" << pID << " is currently out of stock.\n";
	else {
		members[memberIndex]->addProductToCart(pID);
		std::cout << '\n' << inventory[inventoryIndex]->getTitle() << " added to cart.";
	}
}


/*********************************************************************
** checkOutMember()
** The purpose of this function is to checkout a Member. It verifies
** the member ID, then checks to see if any products in the member's cart
** has been sold out. It then calculates and prints the subtotal, shipping
** cost, and total cost and clears the cart.
*********************************************************************/
void Store::checkOutMember(std::string mID) {

	int memberIndex = 0;
	double subtotal = 0.0, shipCost, total;
	bool memberFound = false;

	std::cout << "\n";
	
	// validate member ID
	for (size_t i = 0; i < members.size(); i++) {
		if (members[i]->getAccountID() == mID) {
			memberFound = true;
			memberIndex = i;
		}	
	}

	if (!memberFound)
		std::cout << "\nMember #" << mID << " not found.\n";
	else {
		std::vector<std::string> cart = members[memberIndex]->getCart();

		// iterate through the member's cart and check to see if any of the products are sold out.
		// If it's not sold out, print title and price, decrease quantity, and update subtotal cost.
		for (size_t i = 0; i < cart.size(); i++) {
			Product* item = getProductFromID(cart[i]);
			if (item->getQuantityAvailable() > 0) {
				std::cout << '\n' << item->getTitle() << " - $" << item->getPrice() << '\n';
				item->decreaseQuantity();
				subtotal += item->getPrice();
			}
			else
				std::cout << "\nSorry, product #" << item->getIdCode() << ", \"" << item->getTitle() << "\", is currently out of stock.\n";
		}

		// calculate shipping cost
		if (members[memberIndex]->isPremiumMember())
			shipCost = 0.0;
		else
			shipCost = subtotal * .07;

		total = subtotal + shipCost;

		// print subtotal, shipping cost, and total cost
		std::cout << "\nSubtotal: " << std::setprecision(2) << std::fixed << subtotal
			<< "\nShipping Cost: " << shipCost
			<< "\nTotal: " << total << "\n\n";

		// empty cart
		members[memberIndex]->emptyCart();
	}
}