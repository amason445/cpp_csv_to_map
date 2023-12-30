#include "MapToCSV/MapToCSV.h"
#include <iostream>

int main()
{
    try {
        //Writes SPY.csv to map of tuples and then a txt file
        MapToCSV SPYcsv = MapToCSV("SPY.csv");
        SPYcsv.get_output();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "The program is complete!";

    return 0;
}
