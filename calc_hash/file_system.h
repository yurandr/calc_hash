#pragma once

// include proper 'filesystem'
#ifdef UNDEFINED

#include <filesystem>
namespace fs = std::filesystem;

#else // otherwise

#define MYFS
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#endif

namespace myfs 
{
    fs::path relative( const fs::path &path, const fs::path &relative_to );
}
