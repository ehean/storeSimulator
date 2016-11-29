/*********************************************************************
** Author:			Erik Heaney
** Date:			10/28/2016
** Description:		This is the class implementation file for the Product
					class. Member functions include a constructor, five
					getter functions, and a function that decreases the
					quantity available by one every time it's called.
*********************************************************************/
#include "Product.hpp"
#include <string>

/*********************************************************************
** Product()
** This is the constructor. 
*********************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa) {
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/*********************************************************************
** getIdCode()
** This is the getter for the product's ID.
*********************************************************************/
std::string Product::getIdCode() {
	return idCode;
}

/*********************************************************************
** getTitle()
** This is the getter for the product's title.
*********************************************************************/
std::string Product::getTitle() {
	return title;
}

/*********************************************************************
** getDescription()
** This is the getter function for the description.
*********************************************************************/
std::string Product::getDescription() {
	return description;
}

/*********************************************************************
** getPrice()
** This is the getter function for price.
*********************************************************************/
double Product::getPrice() {
	return price;
}

/*********************************************************************
** getQuantityAvailable()
** This is the getter function for quantity available.
*********************************************************************/
int Product::getQuantityAvailable() {
	return quantityAvailable;
}

/*********************************************************************
** decreaseQuantity()
** This function decreases quanitty avaible by one.
*********************************************************************/
void Product::decreaseQuantity() {
	quantityAvailable--;
}
