#include "FileHandler.h"
#include <stdexcept>

FileHandler::FileHandler(const std::string& input_filename) : inputFileName(input_filename){
	outputFileName = "OutputFiles/" + createOutputFileName("_output.txt");
	loggingFileName = createOutputFileName("_logging.txt");
}

std::string FileHandler::createOutputFileName(const std::string& file_suffix) {
	// set stop character to windows file extension
	char stop_char = '.';

	//calculate stop position and scrape string until stop position is hit
	size_t stop_position = inputFileName.find(stop_char);
	if (stop_position != std::string::npos) {
		std::string substr = inputFileName.substr(0, stop_position);
		return substr + file_suffix;
	}
	else {
		throw std::runtime_error("Issue with parsing file in FileHandler.setStreamFileNames: " + inputFileName);
	}
}

std::ifstream FileHandler::getInputStream() {
	return std::ifstream(inputFileName);
}

std::ofstream FileHandler::getOutputStream() {
	return std::ofstream(outputFileName);
}

std::ofstream FileHandler::getLoggingStream() {
	return std::ofstream(loggingFileName);
}