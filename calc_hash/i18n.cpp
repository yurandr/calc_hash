#include "i18n.h"

namespace i18n
{
    const char* input_path_not_specified = "path to the file/folder should be specified";
    const char* input_path_not_exists = "specified path doesn't exists";
    const char* output_file_not_specified = "\"output\" mode specified but no output file provided";

    const char* help = "-h | --help - information about tool and how it can be used\
\n-a | --absolute - used in 'folder mode' - show absolute file paths instead of relative\
\n-o | --output=<file> - save data into the file instead of writing to the standard output stream";
}