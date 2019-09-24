#ifndef ItemSet_H

#define ItemSet_H
#include <string>
#include<iostream>
namespace sict {

	class ItemSet {
		static size_t FW;
		std::string itemname;
		int itemcode;
		int qty;
		std::string itemdesc;
	public:
		ItemSet(const std::string&);
		const std::string& getName()const;
		const unsigned int getSerialNumber()const;
		const unsigned int getQuantity()const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full)const;
	};

}

#endif // !1

