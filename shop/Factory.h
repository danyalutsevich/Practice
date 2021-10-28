#pragma once

#include <iostream>
#include "Items.h"
#include <fstream>
#include <filesystem>
#include <vector>

class ProdFactory {

private:

	size_t parts;

	std::string* splitString(std::string str, char sym) {

		size_t pos = 0;
		parts = 1;

		while ((pos = str.find(sym, pos + 1)) != std::string::npos) {
			parts++;
		}

		std::string* res = new std::string[parts];
		pos = 0;
		size_t pos2;

		for (int i = 0; i < parts - 1; i++) {

			pos2 = str.find(sym, pos + 1);
			res[i] = str.substr(pos, pos2 - pos);
			pos = pos2;


		}

		res[parts - 1] = str.substr(pos + 1);



		return res;
	}

public:

	Product* fromString(std::string str) {

		auto arr = splitString(str, '\n');

		size_t lines = parts;

		if (lines != 4) {

			return NULL;
		}


		auto title = splitString(arr[0], ':');
		auto manufacturer = splitString(arr[1], ':');
		auto price = splitString(arr[2], ':');
		auto part4 = splitString(arr[3], ':');


		if (part4[0]=="volume") {

			Refregirator* ref = new Refregirator;
			ref->setVolume(stoi(part4[1]))->setTitle(title[1])->setPrice(price[1])->setManufacturer(manufacturer[1]);
			return ref;

		}
		if (part4[0]=="resolution") {

			TV* tv = new TV;
			tv->setResolution(part4[1])->setTitle(title[1])->setPrice(price[1])->setManufacturer(manufacturer[1]);
			return tv;

		}

		return NULL;

	}

	Product* fromFile(std::string filename) {

		std::ifstream input;
		input.open(filename);
		char chunk[100];
		std::string str;

		while (!input.eof())
		{
			input.read(chunk, 5);
			std::streamsize n = input.gcount();
			chunk[n] = 0;


			str += chunk;
		}

		input.close();

		return fromString(str);


	}


	std::vector<Product*> fromDirectory(std::string directory) {

		namespace fs = std::filesystem;

		std::vector<Product*>products;

		for (fs::directory_entry const& dir : fs::directory_iterator(directory)) {

			if (dir.is_regular_file()) {

				if (dir.path().extension() == ".prod") {

					Product* prod = fromFile(dir.path().string());
					if (prod) {

						products.push_back(prod);

					}

				}
			}

		}

		return products;
	}


};


