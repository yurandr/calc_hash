#pragma once

#include "ipath.h"

namespace path
{
    class relative : public ipath
    {
        std::string base_path;
    public:
        relative(const std::string& base_path) : base_path(base_path) {}
        virtual std::string get(const std::string& path) const override;
    };
}