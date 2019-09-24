#ifndef sict_Customer_Order_H
#define sict_Customer_Order_H
#include<iostream>
#include<string>
#include"ItemSet.h"
#include<iomanip>
namespace sict {
	
	class CustomerOrder {
		std::string cname;
		std::string pname;
		struct ItemInfo
		{
			std::string name="";
			unsigned int serial_num = 0;
			bool filled = false;
			ItemInfo(std::string str) : name{ str } {};
			ItemInfo() {};
		};
		int itemc;
		ItemInfo* iteminfo;		
		static size_t field_with;
	public:
		
		CustomerOrder();
		CustomerOrder(const std::string&);
		~CustomerOrder();
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&& other)noexcept;
		CustomerOrder& operator=(CustomerOrder&& other)noexcept;
		void fillItem(ItemSet&, std::ostream&);
		bool isFilled() const;
		bool isItemFilled(const std::string& item)  const;
		std::string getNameProduct()const;
		void display(std::ostream& os, bool showDetail=false) const;



	};


}

#endif // !CustomerOrder_H

