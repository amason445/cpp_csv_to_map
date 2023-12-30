//file handler class

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>

class FileHandler {
public:
	//constructor for FileHandler class
	FileHandler(const std::string& input_filename);

	std::ifstream getInputStream();

	std::ofstream getOutputStream();

	std::ofstream getLoggingStream();


private:
	//file path
	std::string inputFileName;
	std::string outputFileName;
	std::string loggingFileName;

	std::string createOutputFileName(const std::string& file_suffix);

};


#endif // !FILEHANDLER_H
