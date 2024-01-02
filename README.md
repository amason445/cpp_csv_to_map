# CSV to Map using C++
A set of C++ modules that read CSVs, convert them to a map and then write this map to a text file. This script uses pricing data for SPY from Yahoo Finance's public download page. The final map will use dates as the key and contain tuples of the adjusted close and volume as values.

As of 1/1/2024, I also added an accumulator from the Boost Library and calculated the daily average volume for each year. I've printed this to the final output.

- [Data Source](https://finance.yahoo.com/quote/SPY?p=SPY)
