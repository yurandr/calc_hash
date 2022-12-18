#pragma once

#include <string>

class arguments
{
public:
    arguments(int argc, char** argv);

    bool is_help() const { return help; }
    bool is_absolute() const { return absolute; }
    bool is_directory() const { return directory; }
    bool is_output_file() const { return !output_file.empty(); }
    std::string get_output_file() const { return output_file; }
    std::string get_path() const { return path; }

private:
    bool help = false;
    bool absolute = false;
    bool directory = false;
    std::string path;
    std::string output_file;
};