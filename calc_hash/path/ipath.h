#pragma once

#include <string>

namespace path
{
    class ipath
    {
    public:
        virtual ~ipath() {}
        virtual std::string get(const std::string& path) const = 0;
    };
}