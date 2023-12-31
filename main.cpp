#include "MapToCSV/MapToCSV.h"
#include "FileHandler/FileHandler.h"
#include <iostream>
#include <fstream>


void write_to_output(MapToCSV& csvToMap, std::ofstream& output) {
    //write map to file using output file stream
    for (const auto& pair : csvToMap.get_map()) {
        output << pair.first << ": (" << std::get<0>(pair.second) << ", " << std::get<1>(pair.second) << ")\n";
    }
}

int main()
{
    try {
        std::string inputFileName = "IOFiles/SPY.csv";

        FileHandler csvFileHandler(inputFileName);

        MapToCSV csvToMap(csvFileHandler.getInputStream(), csvFileHandler.getLoggingStream());

        write_to_output(csvToMap, csvFileHandler.getOutputStream());
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "The program is complete!";

    return 0;
}
