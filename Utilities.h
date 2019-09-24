

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <iostream>
#include <string>
#include <vector>


namespace sict {

	class Utilities {
		size_t FW;
		static char delimiter;

	public:
		Utilities();
		const std::string extractToken(const std::string&, size_t&);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char);
		void setFieldWidth(size_t);
		Utilities(const Utilities&) = delete;
		Utilities& operator=(const Utilities&) = delete;
		Utilities& operator=(Utilities&&) = delete;
	};
}

#endif
