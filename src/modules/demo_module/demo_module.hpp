#ifndef SRC_MODULES_DEMO_MODULE_DEMO_MODULE_
#define SRC_MODULES_DEMO_MODULE_DEMO_MODULE_
#include "modules/i_module.hpp"
#include "modules/i_rttask.hpp"
#include "modules/demo_module/demo_data_carrier.hpp"
#include "modules/demo_module/demo_task.hpp"
#include <memory>

namespace kernel {
	namespace modules {
		/**
		 * @brief [brief description]
		 * @details [long description]
		 */
		class DemoModule : public IModule {
			public:
				DemoModule();

				const ModType type() const override {return ModType::DEMO;}
				const std::string name() const override {return "Demo Module";}
				const unsigned short version() const override {return 1;}
				const std::vector<DataType> requires() const override {return std::vector<DataType>{};}
				const std::vector<DataType> provides() const override {return std::vector<DataType>{};}

				const ModuleErrorState getState() const {return _err_state;}

				std::unique_ptr<IRTTask> task() {
				  if(!_task) {
            return std::move(_task);
				  }
				  else {
            std::cerr << __PRETTY_FUNCTION__ << " : no task found" << std::endl;
            exit(1);
				  }
				}



        void invoke() {
          assert(_task);
          _task->invoke();
        }


			private:
				ModuleErrorState _err_state;
				std::unique_ptr<DemoTask> _task;
		};
	}
}

#endif // SRC_MODULES_DEMO_MODULE_DEMO_MODULE_
