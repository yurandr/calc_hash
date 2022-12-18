#include "absolute.h"

#include "../file_system.h"

namespace path
{
    std::string absolute::get(const std::string& path) const
    {
        return fs::absolute(path).string();
    }
}