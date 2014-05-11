#ifndef SRC_SCHEDULER_HPP_
#define SRC_SCHEDULER_HPP_
#include <vector>
#include "modules/i_rttask.hpp"
#include <memory>
#include <vector>

// Forward declarations
namespace kernel {
	namespace services {
		class IRTTask;
		class SlackTask;
	}
}

namespace kernel {
	namespace services {

		/**
		 * @brief Manages the execution of periodic and non-periodic tasks
		 * @details
		 */
		class Scheduler {
			public:

				/**
				 * @brief Initialize scheduler
				 * @details Initializes the scheduler and allocates all necessary
				 * ressources.
				 */
				static void initialize();

				/**
				 * @brief Start periodic invocation of the registered tasks
				 * @details This method starts the main loop that invokes the
				 * registered real time tasks and possibly dispatches slack time
				 * tasks (the latter is not implemented)
				 */
				static void run();

				/**
				 * @brief Set up a real time task for periodic execution
				 * @details Tasks that are registered here will be invoked
				 * in a 50 Hz cycle in the order they were registered.
				 *
				 * @param  Task to invoke
				 */
				static void registerModule (std::shared_ptr<modules::IModule>);

				/**
				 * @brief Set up a non time-critical job for execution
				 * @details Tasks that are registered here have to check if
				 * there is enough time left in the current cycle to finish
				 * their execution.
				 *
				 * @param[in]  Non time-critical task
				 */
				// static void registerSlackTask (services::SlackTask*);

				static int MAX_RT_TASKS;

			private:
				Scheduler();

				/**
				 * List of all registered tasks
				 */
				static std::vector<std::shared_ptr<modules::IModule>> _rt_modulelist;
		};


	} // namespace services
} // namespace kernel

#endif // SRC_SCHEDULER_HPP_
