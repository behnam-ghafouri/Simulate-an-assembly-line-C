#include"CustomerOrder.h"
#include"Utilities.h"
#include"ItemSet.h"
#include<vector>
#include<iomanip>
namespace sict {

	size_t CustomerOrder::field_with = 0;

	CustomerOrder::CustomerOrder() {
		cname = { "" };
		pname = { "" };
		itemc = 0;
		iteminfo = nullptr;
	};
	
	CustomerOrder::~CustomerOrder() {
		delete[] iteminfo;
		iteminfo = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {
		
		size_t next_pos = 0u;
		Utilities aux;
		std::string input;
		std::vector<std::string>inputs;
		bool flag = true;


		while (flag) {
			
			input = aux.extractToken(str, next_pos);
			inputs.push_back(input);
			if ((inputs.size() == 1) && (field_with < aux.getFieldWidth())) { field_with = aux.getFieldWidth(); };
			if (next_pos >= str.size() || next_pos == -1) {
				flag = false;
				
			}
			
		}
		
		cname = inputs[0];
		pname = inputs[1];
		
		itemc = (inputs.size() - 2);
		iteminfo = new ItemInfo[itemc];

		if (itemc < 1) {
			throw std::string("NO ITEM");
		}
		else {
			for (int i = 0; i < itemc; i++)
			{
				iteminfo[i].name = inputs[i + 2];
			}
		};

	}
	
	CustomerOrder::CustomerOrder(CustomerOrder&& other)noexcept {
		iteminfo = nullptr;
		*this = std::move(other);

	};
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		if (this != &other) {
			cname = other.cname;
			pname = other.pname;
			itemc = other.itemc;
			iteminfo = other.iteminfo;
			other.iteminfo = nullptr;
		}
		return *this;
	}

		void CustomerOrder::fillItem(ItemSet & item, std::ostream & os) {
			for (int i = 0; i < itemc; i++)
			{
				if (item.getName()==iteminfo[i].name) {
					
					if (item.getQuantity() == 0u) {
						os << " unable to fill" << cname
							<< "[" << pname << "]["
							<< iteminfo[i].name << "]["
							<< iteminfo[i].serial_num << "]" << " out of stock"<<std::endl;
					}
					else /*if(item.getQuantity() != 0u)*/{

						if (iteminfo[i].filled) {
							os << " unable to fill" << cname
								<< "[" << pname << "]["
								<< iteminfo[i].name << "]["
								<< iteminfo[i].serial_num << "]" << " already filled" << std::endl;
						}
						else {
							iteminfo[i].serial_num = item.getSerialNumber();
							iteminfo[i].filled = true;
							--item;
							os << " filled " << cname
								<< "[" << pname << "]["
								<< iteminfo[i].name << "]["
								<< iteminfo[i].serial_num << "]"  << std::endl;

						}





					}

				}

			}
		
		
		};

		bool CustomerOrder::isFilled() const {
			bool flag=true;
			for (int i = 0; i < itemc && flag; i++)
			{
				if (iteminfo[i].filled == false) { flag = false; };
			}
			return flag;
		
		};

		bool CustomerOrder::isItemFilled(const std::string& item) const {
			bool flag = true;
			for (int i = 0; i < itemc && flag; i++)
			{
				if (item == iteminfo[i].name) {
					if (!iteminfo[i].filled) { flag = false; }
				}
			}
			return flag;
		}

		std::string CustomerOrder::getNameProduct()const {
			return cname + std::string("[") + pname + std::string("]");
		};

		void CustomerOrder::display(std::ostream& os, bool showDetail)const {
			os << std::left << std::setw(field_with) << cname
				<< "[" << pname << "]" << std::endl;
		if(showDetail){
			for (int i = 0; i < itemc; i++)
			{
				os << std::setfill(' ') << std::setw( field_with) << " " << std::right << "[" << iteminfo[i].serial_num << "]" 
					<<iteminfo[i].name << " - " << (iteminfo[i].filled ? "FILLED" : "MISSING") << std::endl;
			}
		}
		else {
			for (int i = 0; i < itemc; i++)
			{
				os << std::setfill(' ') << std::setw(field_with) << " " << std::right << iteminfo[i].name<< std::endl;
			}
		}
		};





	





}