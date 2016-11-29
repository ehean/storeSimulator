#include "Store.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {

	Store myStore;
	Customer test("erik", "123", 0);
	Customer t2("erik", "500", true);
	Customer *ptrTest = &test;
	Customer *ptrt2 = &t2;
	Product widget("111", "widget", "this is a test widget", 100.75, 2);
	Product *ptrWidget = &widget;
	std::string pID = "111", mID = "123";
	
	myStore.addProduct(ptrWidget);
	myStore.addMember(ptrTest);
	myStore.addMember(ptrt2);

	myStore.productSearch("WIDGET");
	//myStore.addProductToMemberCart(pID, mID);
	//myStore.addProductToMemberCart(pID, "500");
	//myStore.addProductToMemberCart(pID, "500");

	//myStore.checkOutMember("500");
	//myStore.checkOutMember("123");

	//myStore.checkOutMember("500");

	return 0;
}