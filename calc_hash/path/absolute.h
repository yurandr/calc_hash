#pragma once

#include "ipath.h"

namespace path
{
    class absolute : public ipath
    {
    public:
        virtual std::string get(const std::string& path) const override;
    };
}