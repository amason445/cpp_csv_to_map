#include "MapToCSV.h"
#include <sstream>
#include <stdexcept>


MapToCSV::MapToCSV(std::ifstream& input, std::ofstream& logging) :
    inputStream(input),
    loggingStream(logging)
{
    if (!inputStream.good() || !loggingStream.good()) {
       throw std::runtime_error("One or more file streams are not in a good state.");
    }
}
        
void MapToCSV::createPriceVolumeRecords() {

    //strip header from csv
    std::getline(inputStream, csv_header);

    //process file as a stream
    while (std::getline(inputStream, csv_line)) {

        //create stream from csv line
        std::istringstream iss(csv_line);

        //skips unnecessary columns
        std::getline(iss, date, ',');
        for (int i = 0; i < 4; ++i) {
            std::getline(iss, skips, ',');
        }

        //processes stream and checks for breaks
        if (iss >> adj_close && iss.ignore() && iss >> volume) {
            //package adj_close and volume into tuple
            priceVolumeRecords[date] = std::make_tuple(adj_close, volume);

            //logging string
            loggingStream << "Date: " << date << ". Tuple: (" << adj_close << ", " << volume << ") was a success!" << std::endl;
        }
        else {
            loggingStream << "Error parsing line: " << csv_line << std::endl;
        }

        //reset stream for new line
        iss.clear();
    }
}

std::map<std::string, std::tuple<double, long>>& MapToCSV::get_map() {
    createPriceVolumeRecords();
    return priceVolumeRecords;
}