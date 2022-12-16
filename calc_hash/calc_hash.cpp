#include <iostream>
#include <string>
#include <fstream>
#include "file_system.h"

#include "i18n.h"
#include "arguments.h"
#include "hash/crc32.h"

#include "path/ipath.h"
#include "path/absolute.h"
#include "path/relative.h"

void report_file(std::ostream& destination, const std::string& file_path, const hash::ihash& hash)
{
	std::ifstream is(file_path);
	destination << std::hex << hash.calc(is) << std::endl;
}

void report_folder(std::ostream& destination, const std::string& folder_path, const path::ipath& path_reporter, const hash::ihash& hash)
{
	for (const auto& entry: fs::directory_iterator(folder_path))
	{
		if (fs::is_directory(entry.path()))
			report_folder(destination, entry.path().string(), path_reporter, hash);
		else
		{
			std::ifstream is(entry.path());
			destination << std::hex << hash.calc(is) << " " << path_reporter.get(entry.path().string()) << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	try
	{
		arguments args(argc, argv);
		if (args.is_help())
			std::cout << i18n::help << std::endl; // думаю нет смысла делать возможность вывода справки в файл, в задании про это прямо не сказано конечно
		else
		{
			path::absolute path_reporter_absolute;
			path::relative path_reporter_relative(args.get_path());
			path::ipath& path_reporter = args.is_absolute() ? static_cast<path::ipath&>(path_reporter_absolute) : static_cast<path::ipath&>(path_reporter_relative);

			std::ofstream output_file;
			if (args.is_output_file())
				output_file.open(args.get_output_file(), std::ios::out | std::ios::trunc);

			std::ostream& destination = output_file.is_open() ? output_file : std::cout;

			if (args.is_directory())
				report_folder(destination, args.get_path(), path_reporter, hash::crc32());
			else
				report_file(destination, args.get_path(), hash::crc32());
		}
	}
	catch (std::exception& exc)
	{
		std::cerr << exc.what() << std::endl;
	}
}