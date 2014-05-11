#ifndef SRC_MODULES_GPS_
#define SRC_MODULES_GPS_
#include "modules/i_module.hpp"

#include "i_rttask.hpp"

namespace kernel {
	namespace modules {
		class Gps : public IModule {
			public:
				const ModType type() const {return ModType::GPS;}
				const std::vector<DataType> requires() const {return std::vector<DataType>{};}
				const std::vector<DataType> provides() const {return std::vector<DataType>{};}

		};
	} // modules
} // kernel

#endif // SRC_MODULES_GPS_
