#include "FileHandler.h"
#include <stdexcept>

FileHandler::FileHandler(const std::string& input_filename) : 
	inputFileName(input_filename),
	outputFileName(createOutputFileName("_output.txt")),
	loggingFileName(createOutputFileName("_logging.txt")),
	input(inputFileName),
	output(outputFileName),
	logging(loggingFileName) {

	if (inputFileName.find('.') == std::string::npos) {
		throw std::runtime_error("CSV is invalid Please investigate: " + inputFileName);
	}

	if (!input.is_open()) {
		throw std::runtime_error("Failed to open input file.");
	}
	if (!output.is_open() || !logging.is_open()) {
		throw std::runtime_error("Failed to open output or logging file.");
	}
}

FileHandler::~FileHandler() {}

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

std::ifstream& FileHandler::getInputStream() {
	return input;
}

std::ofstream& FileHandler::getOutputStream() {
	return output;
}

std::ofstream& FileHandler::getLoggingStream() {
	return logging;
}