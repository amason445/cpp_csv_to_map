//file handler class. written for now to process CSVs only.

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>

class FileHandler {
//file path strings
std::string inputFileName;
std::string outputFileName;
std::string loggingFileName;

//file streams
std::ifstream input;
std::ofstream output;
std::ofstream logging;

//internal function that creates file names for streams
std::string createOutputFileName(const std::string& file_suffix);

public:
	//constructor and destructor for FileHandler class
	FileHandler(const std::string& input_filename);
	~FileHandler();

	// Delete the copy constructor and copy assignment operator
	FileHandler(const FileHandler&) = delete;
	FileHandler& operator=(const FileHandler&) = delete;

	std::ifstream& getInputStream();
	std::ofstream& getOutputStream();
	std::ofstream& getLoggingStream();

};

#endif // !FILEHANDLER_H
