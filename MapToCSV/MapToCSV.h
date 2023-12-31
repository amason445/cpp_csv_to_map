//Map to CSV Class

#ifndef MAPCSV_H
#define MAPCSV_H

#include <string>
#include <map>
#include <tuple>
#include <fstream>

class MapToCSV {
	//input and logging references
	std::ifstream& inputStream;
	std::ofstream& loggingStream;

	//CSV parsing components
	std::string csv_header;
	std::string csv_line;
	
	//set key value pairs including a column to place hold skipping
	std::string skips;
	std::string date;
	float open, high, low, close, adj_close;
	long volume;

	//output data structure
	std::map<std::string, std::tuple<double, long>> priceVolumeRecords;

	void createPriceVolumeRecords();

public:
	//constructor
	MapToCSV(std::ifstream& input, std::ofstream& logging);

	//member functions
	std::map<std::string, std::tuple<double, long>>& get_map();
};

#endif // !MAPCSV_H