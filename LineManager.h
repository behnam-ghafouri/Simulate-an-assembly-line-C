#ifndef sict_LineManager_H
#define sict_LineManager_H
#include<iostream>
#include<vector>
#include"Station.h"
#include"CustomerOrder.h"
#include<deque>

namespace sict {

	class LineManager {
		std::deque<CustomerOrder>complete;
		std::deque<CustomerOrder>incomplete;

		std::vector<Station*>station_;
		std::deque<CustomerOrder>customerorder_;

		std::vector<size_t>index_;
		const size_t orderNumber;
		const size_t startpoint;
		size_t lastStation;


	public:

		LineManager(std::vector<Station*>& station, std::vector<size_t>& index, std::vector<CustomerOrder>& custorder, size_t strindex, std::ostream& os);

		void display(std::ostream& os)const;

		bool run(std::ostream& os);
	};
}
#endif // !sict_LineManager_H

