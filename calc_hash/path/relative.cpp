#include "relative.h"

#include "../file_system.h"

namespace path
{
    std::string relative::get(const std::string& path) const
    {
        return myfs::relative(fs::path(path), fs::path(base_path)).string();
    }
}


