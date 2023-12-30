//Map to CSV Class

#ifndef MAPCSV_H
#define MAPCSV_H

#include <string>
#include <map>
#include <tuple>
#include <fstream>



class MapToCSV {
public:
	//constructor
	MapToCSV(const std::string& input_filename);

	//member functions
	void get_output();

private:
	//input filename
	std::string inputFileName;

	//file streams
	std::ifstream input;
	std::ofstream output;
	std::ofstream logging;

	//CSV parsing components
	std::string csv_header;
	std::string csv_line;
	
	//set key value pairs including a column to place hold skipping
	std::string skips;
	std::string date;
	float open, high, low, close, adj_close;
	long volume;

	//output data structure
	std::map<std::string, std::tuple<double, long>> price_volume_records;

	//function to check errors
	void checkIfOpen();
};

#endif // !MAPCSV_H