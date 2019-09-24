#include"Station.h"
#include<queue>

namespace sict {

	Station::Station(const std::string& str) {
		iset = new ItemSet(str);
	}

	void Station::display(std::ostream& os) const {
		iset->display(os,true);
	};
	Station::~Station() {
		delete iset;
	
	};
	void Station::fill(std::ostream& os) {
		if (!(ord.empty())) {
				ord.front().fillItem((*iset), os);			
		}
	};

	const std::string& Station::getName()const {
		return(iset->getName());
	};

	bool Station::hasAnOrderToRelease()const {
		bool flag=false;
		if (!(ord.empty())) {
			if (ord.front().isItemFilled(getName()) || (iset->getQuantity() == 0)) { flag = true; }
		}
		return flag;
	};
	Station& Station::operator--() {
		--(*iset);
		return *this;
	};

	Station& Station::operator+=(CustomerOrder&& inp) {
		ord.push(std::move(inp));
		return std::ref(*this);
	};
	
	bool Station::pop(CustomerOrder& ready) {
		bool flag = false;
		if (!(ord.empty())) {
			ready = std::move(ord.front());
			ord.pop();
			if (ready.isItemFilled(getName())) {
				flag = true;
			}
		}
		return flag;
	};

	void Station::validate(std::ostream& os)const {
		os << "getName(): " << iset->getName()<<std::endl;
		os << "getSerialNumber(): " << iset->getSerialNumber()<<std::endl;
		os<< "getQuantity(): " << iset->getQuantity()<<std::endl;
	};










}