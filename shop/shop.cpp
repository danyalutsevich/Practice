
#include <iostream>
#include <vector>
#include "Factory.h"
#include "Items.h"

int main()
{


	ProdFactory factory;

	std::vector<Product*> store;

	store=factory.fromDirectory("./");

	//print only TV
	std::cout << "TVs" << "\n";
	for (int i = 0; i < store.size(); i++) {

		if (dynamic_cast<TV*>(store[i])) {

			std::cout << store[i]->print() << "\n";
		}
	}

	//print only Refregirator
	std::cout << "Refregirators" << "\n";
	for (int i = 0; i < store.size(); i++) {

		if (dynamic_cast<Refregirator*>(store[i])) {

			std::cout << store[i]->print() << "\n";
		}
	}

	//print all
	std::cout << "Everything" << "\n";
	for (int i = 0; i < store.size(); i++) {

		std::cout << store[i]->print() << "\n";

	}

	


}
