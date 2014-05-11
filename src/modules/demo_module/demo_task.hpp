#ifndef SRC_MODULES_DEMO_MODULE_DEMO_TASK_
#define SRC_MODULES_DEMO_MODULE_DEMO_TASK_
#include "modules/i_rttask.hpp"
#include "demo_module/demo_data_carrier.hpp"

// forward declaration
namespace kernel {
	namespace modules {
		class DemoModule;
	}
}

namespace kernel {
	namespace modules {
		class DemoTask : public IRTTask {
			public:
        DemoTask() : _ddc(new DemoDataCarrier()){}
				/**
				 * @brief Invokes demo code
				 * @details This method contains the demo code we want to be
				 * executed periodically to obtain and pass data or make any
				 * kind of computations on a regular basis
				 */
				TaskErrorState invoke();
				std::weak_ptr<IDataCarrier> getData() {return _ddc;}
		  private:
        std::shared_ptr<DemoDataCarrier> _ddc;
		};
	}
}

#endif // SRC_MODULES_DEMO_MODULE_DEMO_TASK_
