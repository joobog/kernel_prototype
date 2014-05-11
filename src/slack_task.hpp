#ifndef SRC_SLACK_TASK_HPP_
#define SRC_SLACK_TASK_HPP_

namespace kernel {
	namespace services {

		enum RTT_ERROR_STATE {RES_OK, RES_ERROR}

		/**
		 * @brief Interface for slack time tasks
		 * @details This is the base class to wrap periodic tasks
		 */
		class SlackTask {
			public:
			virtual ~SlackTask();

			/**
			 * @brief Contains the non time-critical sub routine
			 * @details This method gets invoke in case there is enough
			 * slack time after executing the periodic tasks.... TODO
			 */
			virtual RTT_ERROR_STATE invoke() = 0;

			private:
			SlackTask();
		};
	}
}

#endif // SRC_SLACK_TASK_HPP_
