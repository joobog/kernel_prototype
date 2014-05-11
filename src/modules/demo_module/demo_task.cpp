#include <iostream> //nur fuer demo
#include "demo_task.hpp"
#include "modules/demo_module/demo_data_carrier.hpp"
#include "data_controller.hpp"
#include <random>
#include <functional>

namespace kernel {

	modules::TaskErrorState
	modules::DemoTask::invoke()
	{
		using namespace std;
		// periodic code goes here
		//cout << __PRETTY_FUNCTION__ << "\nYes, this is demo task." << endl;
		// update data carrier
		//DemoModule* dm = dynamic_cast<DemoModule*> ( _mod );
		//DemoDataCarrier* ddc = dm->getCarrier();
		auto gen = std::bind (
								 std::uniform_int_distribution<char> {65, 90},
								 std::default_random_engine {});
		char s[10];

		for (int i = 0; i < 9; i++) {
			s[i] = gen();
		}

		s[9] = 0;
		_ddc->setData (s);
		// pass data carrier
		//services::DataController::updateData (_mod->getID(), _ddc);
		return modules::TaskErrorState::OK;
	}


} // namespace modules
