#pragma once

#include <iostream>
#include <string>

class Product {

private:

	std::string title;
	std::string manufacturer;
	std::string price;

public:

	Product* setTitle(std::string title) {
		
		this->title = title;
		return this;

	}
	
	Product* setManufacturer(std::string manufacturer) {

		this->manufacturer = manufacturer;
		return this;
	}

	Product* setPrice(std::string price) {

		this->price = price;
		return this;

	}

	std::string getTitle() {

		return title;
	}

	std::string getManufacturer() {

		return manufacturer;
	}

	std::string getPrice() {

		return price;
	}

	virtual std::string print() = 0;

};




class Refregirator : public Product {

private:
	int volume;

public:

	Refregirator* setVolume(int volume) {

		this->volume = volume;
		return this;
	}

	int getVolume() {

		return volume;
	}

	std::string print() {

		return getTitle() + " " + getManufacturer() + " " + std::to_string(getVolume()) + " price: " + getPrice();
	}

};

class TV : public Product {

private:
	std::string resolution;

public:

	TV* setResolution(std::string resolution) {

		this->resolution = resolution;
		return this;
	}

	std::string getResolution() {

		return resolution;
	}

	std::string print() {

		return getTitle() + " " + getManufacturer() + " " + getResolution() + " price: " + getPrice();
	}

};

