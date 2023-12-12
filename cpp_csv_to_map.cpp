#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <tuple>

int main()
{
    //create input file stream
    std::ifstream SPYcsv("SPY.csv");

    //check if input file is open
    if (!SPYcsv.is_open()) {
        std::cerr << "The CSV has failed to open" << std::endl;
        return 1;
    }

    // Skip the header row
    std::string header;
    std::getline(SPYcsv, header);

    //declare container map and file string
    std::string csv_line;
    std::map<std::string, std::tuple<double, long>> price_volume_records;
    
    //process file as a stream
    while (std::getline(SPYcsv, csv_line)) {
        
        //create stream from csv line
        std::istringstream iss(csv_line);

        // set key and value variables
        std::string date;
        float open, high, low, close, adj_close;
        long volume;

        //skips unnecessary columns
        std::getline(iss, date, ',');
        std::string skips;
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
        std::cout << "Date: " << date << ". Tuple: (" << adj_close << ", " << volume << ")" << std::endl;


    }

    //close input
    SPYcsv.close();

    //create output file stream
    std::ofstream output("output.txt");

    //check if output file is open
    if (!output.is_open()) {
        std::cerr << "The output file has failed to open" << std::endl;
        return 1;
    }

    //write map to file using output file stream
    for (const auto& pair : price_volume_records) {
        output << pair.first << ": (" << std::get<0>(pair.second) << ", " << std::get<1>(pair.second) << ")\n";
    }

    //close output file
    output.close();

    return 0;
}
