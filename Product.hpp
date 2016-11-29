/*********************************************************************
** Author:			Erik Heaney
** Date:			10/28/2016
** Description:		This is the class definition file for the Product
					class. This class creates an product object that 
					can be held as inventory by the store and bought
					by customers. It includes the following fields:
					ID, Title, description, price, and quantity.
*********************************************************************/

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>



class Product
{
private:
    std::string idCode;
    std::string title;
    std::string description;
    double price;
    int quantityAvailable;
public:
    Product(std::string id, std::string t, std::string d, double p, int qa);
    std::string getIdCode();
    std::string getTitle();
    std::string getDescription();
    double getPrice();
    int getQuantityAvailable();
    void decreaseQuantity();
};

#endif
