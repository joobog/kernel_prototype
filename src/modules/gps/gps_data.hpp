#ifndef SRC_GPS_DATA_
#define SRC_GPS_DATA_
#include "modules/gps/i_gps_data.hpp"

namespace kernel {
	namespace modules {
		class GpsData : public IGpsData {
			public:

				// Returns the azimuth of the satellite in degrees.
				const double 	azimuth() const override {return 0;}
				// Returns the elevation of the satellite in degrees.
				const double 	elevation() const override {return 0;}
				// Returns the PRN (pseudo - random number) for the satellite.
				const int 	prn() const override {return 0;}
				// Returns the signal to noise ratio for the satellite.
				const double 	snr() const override {return true;}
				// Returns true if the GPS engine has almanac data for the satellite.
				const bool 	hasAlmanac() const override {return true;}
				// Returns true if the GPS engine has ephemeris data for the satellite.
				const bool 	hasEphemeris() const override {return true;}
				// Returns true if the satellite was used by the GPS engine when calculating the most recent GPS fix.
				const bool 	usedInFix() const override {return true;}
		};
	} // namespace modules
} // namespace kernel

#endif // SRC_GPS_DATA_
