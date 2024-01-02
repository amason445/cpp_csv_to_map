#ifndef ACCUM_H
#define ACCUM_H

#include "boost/accumulators/accumulators.hpp"
#include "boost/accumulators/statistics/stats.hpp"
#include "boost/accumulators/statistics/mean.hpp"
#include <map>
#include <string>
#include <fstream>

class AccumulatorProcessor {

	std::ofstream& loggingStream;
	std::map<std::string, std::tuple<double, long>>& inputMap;

	//container to hold an an annual average volume calculated from an average. It expects year as an integer.
	std::map<int, boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::mean>>> annualAverageVolume;

	void createAverageVolumeAccumulator();

public:

	AccumulatorProcessor(std::map<std::string, std::tuple<double, long>>& input_map, std::ofstream& logging);

	std::map<int, boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::mean>>>& getVolumeAccumulator();
};


#endif // !MAPCSV_H
