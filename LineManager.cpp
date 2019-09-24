#include"LineManager.h"
#include<iostream>
#include"CustomerOrder.h"
#include"Station.h"
#include<queue>
namespace sict {
	LineManager::LineManager(std::vector<Station*>& station, std::vector<size_t>& index, std::vector<CustomerOrder>& custorder, size_t strindex, std::ostream& os)
		: station_(station), index_(index), orderNumber(custorder.size()), startpoint(strindex) {

		for (size_t i = 0; i < custorder.size(); i++)
		{
			customerorder_.push_front(std::move(custorder[i]));
		}
		lastStation = startpoint;
		

		for (size_t i = 0; i < index.size(); i++)
		{
			if (index_[lastStation] < station_.size()) {
				lastStation = index_[lastStation];

			}
		}

	};

	void LineManager::display(std::ostream& os)const {
		os << "COMPLETE ORDERS" << std::endl;
		for (auto& i : complete)
			i.display(os, true);
		os << std::endl;


		os << "INCOMPLETE ORDERS" << std::endl;
		for (auto& i : incomplete)
			i.display(os, true);
		os << std::endl;
	};

	bool LineManager::run(std::ostream& os) {
		bool ret = false;

		if (!customerorder_.empty()) {
			*station_[startpoint] += std::move(customerorder_.back());
			customerorder_.pop_back();
			//std::cout << startpoint <<"testtt"<< std::endl;
		}
		//int m = 0;
		for (size_t i = 0u; i < station_.size(); i++) {
			station_[i]->fill(os);

			//std::cout << m++ << "  "<< station_[i]->getName()<< std::endl;
		}

		for (size_t i = 0u; i < station_.size(); ++i) {
			if (station_[i]->hasAnOrderToRelease()) {
				CustomerOrder custOrder;
				bool itIsComplete = station_[i]->pop(custOrder);
				os << " --> " << custOrder.getNameProduct() << " moved from " << station_[i]->getName() << " to ";


				if (i != lastStation) {

					os << station_[index_[i]]->getName() << std::endl;
					*station_[index_[i]] += std::move(custOrder);
				}
				else if (itIsComplete && custOrder.isFilled()) {
					os << "Completed Set" << std::endl;
					complete.push_back(std::move(custOrder));
				}
				else if (itIsComplete && !custOrder.isFilled()) {
					os << "Incomplete Set" << std::endl;
					incomplete.push_back(std::move(custOrder));
				}
			}
		}

		if ((complete.size() + incomplete.size()) == orderNumber) {
			ret = true;
		}

		return ret;
	}

}