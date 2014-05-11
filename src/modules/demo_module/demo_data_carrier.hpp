#ifndef SRC_MODULES_DEMO_MODULE_DEMO_DATA_CARRIER_
#define SRC_MODULES_DEMO_MODULE_DEMO_DATA_CARRIER_
#include "modules/i_data_carrier.hpp"
#include <string> // nur fuer demo

namespace kernel {
	namespace modules {
		class DemoDataCarrier final : public IDataCarrier {
			public:
				std::string getMyData() const {return _my_data;}

				void setData (std::string data) {_my_data = data;}

			private:
				std::string _my_data;
		};
	}
}

#endif // SRC_MODULES_DEMO_MODULE_DEMO_DATA_CARRIER_
