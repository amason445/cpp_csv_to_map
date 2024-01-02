#include "Accumulator.h"
#include "boost/date_time/gregorian/gregorian.hpp"

AccumulatorProcessor::AccumulatorProcessor(std::map<std::string, std::tuple<double, long>>& input_map, std::ofstream& logging) :
	inputMap(input_map),
	loggingStream(logging) {

	if (!loggingStream.good()) {
		throw std::runtime_error("One or more file streams are not in a good state.");
	}
}

void AccumulatorProcessor::createAverageVolumeAccumulator() {

	try {
		//fill average annual accumulator volume with volumes
		for (const auto& pair : inputMap) {
			boost::gregorian::date date = boost::gregorian::from_string(pair.first);
			int year = date.year();
			annualAverageVolume[year](std::get<1>(pair.second));
		}

	} catch (const std::exception& e) {
		throw e.what();
	}
}

std::map<int, boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::mean>>>& AccumulatorProcessor::getVolumeAccumulator() {
	createAverageVolumeAccumulator();
	return annualAverageVolume;
}
