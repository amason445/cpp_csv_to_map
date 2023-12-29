#include "MapToCSV.h"
#include <sstream>
#include <stdexcept>
#include <fstream>


MapToCSV::MapToCSV(const std::string& input_filename, const std::string& output_filename, const std::string& logging_filename) : inputFileName(input_filename), outputFileName(output_filename), loggingFileName(logging_filename){}

void MapToCSV::get_output() {
    //create input file stream
    std::ifstream input(inputFileName);
    std::ofstream output(outputFileName);
    std::ofstream logging(loggingFileName);

    checkIfOpen();

    //strip header from csv
    std::getline(input, csv_header);

    //process file as a stream
    while (std::getline(input, csv_line)) {

        //create stream from csv line
        std::istringstream iss(csv_line);

        //skips unnecessary columns
        std::getline(iss, date, ',');
        for (int i = 0; i < 4; ++i) {
            std::getline(iss, skips, ',');
        }

        //parse tuple values from CSV
        iss >> adj_close;
        iss.ignore();
        iss >> volume;

        //package adj_close and volume into tuple
        price_volume_records[date] = std::make_tuple(adj_close, volume);

        //logging string
        logging << "Date: " << date << ". Tuple: (" << adj_close << ", " << volume << ") was a success!" << std::endl;
    }
        
    logging.close();
    input.close();

    //write map to file using output file stream
    for (const auto& pair : price_volume_records) {
        output << pair.first << ": (" << std::get<0>(pair.second) << ", " << std::get<1>(pair.second) << ")\n";
    }

    output.close();   
}

//check if input file is open
void MapToCSV::checkIfOpen() {
    if (!input.good()) {
        throw std::runtime_error("Failed to open input file: " + inputFileName);
    }
    if (!output.good()) {
        throw std::runtime_error("Failed to open output file: " + outputFileName);
    }
    if (!logging.good()) {
        throw std::runtime_error("Failed to open logging file: " + loggingFileName);
    }
}