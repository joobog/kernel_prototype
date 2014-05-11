#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <cassert>
#include <typeinfo>
#include "scheduler.hpp"
#include "modules/i_rttask.hpp"
#include <random>
#include <memory>


namespace kernel {
	namespace services {
		std::vector<std::shared_ptr<modules::IModule>> Scheduler::_rt_modulelist (0);

		int Scheduler::MAX_RT_TASKS (20);

		void
		Scheduler::initialize()
		{
		}

		void
		Scheduler::run()
		{
			using namespace std;
			using namespace std::chrono;
			auto gen = bind (normal_distribution<double> {1000, 4.0}, default_random_engine {});
			// Main loop
			cout << "Size of task list: " << _rt_modulelist.size() << endl;
			cout << "entering main loop" << endl;

			while (1) {
				assert (_rt_modulelist.size() != 0);

				for (auto& module : Scheduler::_rt_modulelist) {
					this_thread::sleep_for (milliseconds (static_cast<int> (gen())));
					assert (module != 0);
					cout << __PRETTY_FUNCTION__ << endl;
					module->invoke();
				}
			}
		}

		void
		Scheduler::registerModule (std::shared_ptr<modules::IModule> module)
		{
			_rt_modulelist.push_back (std::move (module));
		}

		//	void
		//	services::Scheduler::registerSlackTask (services::SlackTask* st)
		//	{
		//	}
	} // namespace services
} // namespace kernel
