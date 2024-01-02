#include "MapToCSV/MapToCSV.h"
#include "FileHandler/FileHandler.h"
#include "Accumulator/Accumulator.h"
#include <iostream>
#include <fstream>
#include <iomanip>

#include "boost/accumulators/statistics/mean.hpp"

void write_raw_to_output(MapToCSV& csvToMap, std::ofstream& output) {
    //write map to file using output file stream
    for (const auto& pair : csvToMap.get_map()) {
        output << pair.first << ": (" << std::get<0>(pair.second) << ", " << std::get<1>(pair.second) << ")\n";
    }
}

void write_accumulator_to_output(AccumulatorProcessor& volumeAggregator, std::ofstream& output) {
    //write accumulator to file using output file stream
    
    output << std::fixed;
    
    for (const auto& pair : volumeAggregator.getVolumeAccumulator()) {
        output << std::setprecision(0);
        output << "Volume for: " << pair.first << ": " << boost::accumulators::mean(pair.second) << "\n";
    }
}


int main()
{
    try {
        std::string inputFileName = "IOFiles/SPY.csv";

        FileHandler csvFileHandler(inputFileName);

        MapToCSV csvToMap(csvFileHandler.getInputStream(), csvFileHandler.getLoggingStream());

        AccumulatorProcessor volumeAggregator(csvToMap.get_map(), csvFileHandler.getLoggingStream());

        //write_raw_to_output(csvToMap, csvFileHandler.getOutputStream());

        write_accumulator_to_output(volumeAggregator, csvFileHandler.getOutputStream());

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "The program is complete!";

    return 0;
}
