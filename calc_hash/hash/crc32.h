#pragma once

#include "ihash.h"

namespace hash
{
    class crc32 : public ihash
    {
    public:
        uint32_t calc(std::istream& input) const override;
    };
}
