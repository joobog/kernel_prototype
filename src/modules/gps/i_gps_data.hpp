#ifndef SRC_I_GPS_DATA_
#define SRC_I_GPS_DATA_
#include "modules/i_data_carrier.hpp"

namespace kernel {
	namespace modules {
		class IGpsData : public IDataCarrier {
			public:

				// Returns the azimuth of the satellite in degrees.
				virtual const double 	azimuth() const = 0;
				// Returns the elevation of the satellite in degrees.
				virtual const double 	elevation() const = 0;
				// Returns the PRN (pseudo - random number) for the satellite.
				virtual const int 	prn() const = 0;
				// Returns the signal to noise ratio for the satellite.
				virtual const double 	snr() const = 0;
				// Returns true if the GPS engine has almanac data for the satellite.
				virtual const bool 	hasAlmanac() const = 0;
				// Returns true if the GPS engine has ephemeris data for the satellite.
				virtual const bool 	hasEphemeris() const = 0;
				// Returns true if the satellite was used by the GPS engine when calculating the most recent GPS fix.
				virtual const bool 	usedInFix() const = 0;
		};
	} // namespace modules
} // namespace kernel

#endif // SRC_I_GPS_DATA_
