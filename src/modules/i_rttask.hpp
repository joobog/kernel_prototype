#ifndef SRC_I_RT_TASK_HPP_
#define SRC_I_RT_TASK_HPP_
#include "modules/i_module.hpp"
#include "modules/i_data_carrier.hpp"

namespace kernel {
	namespace modules {
		enum class TaskErrorState {OK, UNDEF, ERROR};

		/**
		 * @brief Interface for real time tasks
		 * @details This is the base class to wrap periodic tasks
		 */
		class IRTTask {
			public:
				virtual ~IRTTask() {}

				/**
				 * @brief Contains the time-critical sub routine
				 * @details In one cycle this method gets invoked from the scheduler
				 * after the earlier registered tasks have been invoked and
				 * before the subsequently registered tasks will be invoked
				 */
				virtual TaskErrorState invoke() = 0;
				virtual std::weak_ptr<IDataCarrier> getData() = 0;
		};
	}
}

#endif // SRC_I_RT_TASK_HPP_
