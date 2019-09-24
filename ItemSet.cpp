#include<iomanip>
#include<iostream>
#include<string>
#include"ItemSet.h"
#include"Utilities.h"

namespace sict {
	size_t ItemSet::FW = 0u;

	ItemSet::ItemSet(const std::string& str) {
		size_t next_pos = 0u;
		Utilities aux;
		itemname = aux.extractToken(str, next_pos);
		if (FW < aux.getFieldWidth())FW = aux.getFieldWidth();
		itemcode = stoi(aux.extractToken(str, next_pos));
		qty = stoi(aux.extractToken(str, next_pos));
		itemdesc = aux.extractToken(str, next_pos);
	};

	const std::string& ItemSet::getName()const { return std::ref(itemname); };
	const unsigned int ItemSet::getSerialNumber()const { return std::ref(itemcode); };
	const unsigned int ItemSet::getQuantity()const { return std::ref(qty); };
	ItemSet& ItemSet::operator--() {
		qty--;
		itemcode++;
		return std::ref(*this);
	};

	void ItemSet::display(std::ostream& os, bool full)const {
		if (full) {
			os << std::left << std::setw(FW) << itemname << " [" << std::setfill('0') << std::setw(5) << itemcode << std::setfill(' ') << "] Quantity " << std::setw(3) << qty << " Description: " << itemdesc << std::endl;
		}
		else {
			os << std::left << std::setw(FW) << itemname << " [" << std::setfill('0') << std::setw(5) << itemcode << std::endl;
		}

	};


}