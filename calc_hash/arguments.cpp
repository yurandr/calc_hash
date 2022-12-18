#include "arguments.h"
#include <exception>
#include "file_system.h"
#include "i18n.h"

arguments::arguments(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg == "-a" || arg == "--absolute")
            absolute = true;
        else if (arg == "-h" || arg == "--help")
            help = true;
        else if (arg.rfind("-o=", 0) == 0 || arg.rfind("--output=", 0) == 0)
        {	// -o|--output=<file>
            std::size_t separator_index = arg.find("=");
            if (separator_index != std::string::npos)
                output_file = std::string(arg.begin() + separator_index + 1, arg.end());
        }
        else
            path = argv[i];
    }
    if (help)
    {
        /*nothing to check in help mode*/
    }
    else
    {
        if (path.empty())
            throw std::runtime_error(i18n::input_path_not_specified);
        if (!fs::exists(path))
            throw std::runtime_error(i18n::input_path_not_exists + std::string(": ") + path);
        if (fs::is_directory(path))
            directory = true;
    }
};
