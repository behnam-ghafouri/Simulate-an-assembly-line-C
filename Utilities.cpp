
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Utilities.h"

namespace sict {

	char Utilities::delimiter{ '\0' };

	Utilities::Utilities() {
		this->FW = 0u;
	};


	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string token;
		token.clear();

		size_t pos = str.find_first_of(this->delimiter,next_pos); //finding position of next delimiter

		if (next_pos <= str.length()) {
			if (next_pos == pos) {
				throw std::string("Error: No token!");
			}
			else {
				if (pos != std::string::npos) {
					token = str.substr(next_pos, pos - next_pos);
					next_pos = pos + 1;
				}
				else {
					token = str.substr(next_pos, str.length() - next_pos);
					next_pos = str.length() + 1;
				};

				if (this->FW < token.size()) {
					setFieldWidth(token.size());
				};
			};
		};
		
		return token;
	};

	const char Utilities::getDelimiter() const { return this->delimiter; };
	
	size_t Utilities::getFieldWidth() const { return this->FW; };
	
	void Utilities::setDelimiter(const char d) { delimiter = d; };

	void Utilities::setFieldWidth(size_t fw) { this->FW = fw; };

}
