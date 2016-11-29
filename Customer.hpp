/*********************************************************************
** Author:			Erik Heaney
** Date:			11/28/2016
** Description:		This is the class definition file for the Customer
					class. Every customer has a name, ID, is either premium
					or not, and a cart. The member functions include a 
					constructor, three getter functions, a member that
					adds a product to the customer's cart, and a member
					that empties the cart.
*********************************************************************/
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>
#include "Product.hpp"

class Customer
{
private:
   std::vector<std::string> cart;
   std::string name;
   std::string accountID;
   bool premiumMember;
public:
   Customer(std::string n, std::string a, bool pm);
   std::string getAccountID();
   std::vector<std::string> getCart();
   void addProductToCart(std::string p);
   bool isPremiumMember();
   void emptyCart();
};

#endif
