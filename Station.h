#ifndef sict_station_h
#define sict_station_h
#include<iostream>
#include"ItemSet.h"
#include<queue>
#include"CustomerOrder.h"
namespace sict {

	class Station {
		ItemSet* iset;
		std::queue<CustomerOrder> ord;
		
	public:
		Station(const std::string&);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;
		~Station();
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName()const;
		bool hasAnOrderToRelease()const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os)const;
	};








}

#endif // !sict_station_h

