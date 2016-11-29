/*********************************************************************
** Author:			Erik Heaney
** Date:			11/28/2016
** Description:		This is the class definition file for the Store
					class. Each store has an inventory of products and
					a set of members. The member functions include:
						- addProduct: adds a product to inventory
						- addMember: adds a member to member list
						- getProductFromID: takes product ID string as argument,
											returns Product object
						- getMemberFromID: takes member ID as argument
										   returns Customer object
						- productSearch: searches product title and 
										 description, prints product
										 details if found
						- addProductToMemberCart: adds product to member's
										cart
						- checkOutMember: checks out member, prints receipt
*********************************************************************/
#ifndef STORE_HPP
#define STORE_HPP

#include <string>
#include "Customer.hpp"

class Store
{
private:
    std::vector<Product*> inventory;
    std::vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(std::string);
    Customer* getMemberFromID(std::string);
    void productSearch(std::string str);
    void addProductToMemberCart(std::string pID, std::string mID);
    void checkOutMember(std::string mID);
};

#endif
