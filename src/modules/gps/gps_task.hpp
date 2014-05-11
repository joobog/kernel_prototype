#ifndef SRC_MODULES_GPS_GPS_TASK_
#define SRC_MODULES_GPS_GPS_TASK_
#include "modules/gps/gps_data.hpp"
#include "i_rttask.hpp"

namespace kernel {
	namespace modules {
		class GpsTask : public IRTTask {
			public:
				TaskErrorState invoke() override;





			private:
				GpsData _gps_data;
		};
	}
}

#endif // SRC_MODULES_GPS_GPS_TASK_
