#pragma once

#include <istream>

namespace hash
{
	class ihash
	{
	public:
		virtual ~ihash() {}
		virtual uint32_t calc(std::istream& input) const = 0;
	};
}