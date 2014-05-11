#include <iostream>
#include "gps_task.hpp"
#include "i_rttask.hpp"
#include "data_carrier.hpp"
#include "data_controller.hpp"

namespace kernel {
	modules::TaskErrorState
	modules::GpsTask::invoke()
	{
		using namespace std;
		//using namespace kernel::services;
		//cout << "Yes, this is GPS task." << endl;
	//	services::DataController::updateData (21321, _mod->getCarrier());
		return TaskErrorState::OK;
	}


} // namespace kernel
