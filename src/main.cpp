/** @mainpage Prototype: Scheduler and Data Controller
*   @author Daniel Kirchner <daniel.kirchner1@haw-hamburg.de>
*   @version 0.0.1
*   @par Description:
*   - part of the AES project, SS2014 HAW Hamburg
*   - for feasability testing and documentation purposes
*/

// kernel services
#include "data_controller.hpp"
#include "scheduler.hpp"

// kernel modules
#include "modules/demo_module/demo_module.hpp"
#include "modules/gps/gps_module.hpp"

int
main (int argc, char** argv)
{
	using namespace kernel::services;
	using namespace kernel::modules;
	// initialize data controller
	DataController::initialize();
	// initialize scheduler
	Scheduler::initialize();

	// Initialize modules
	//  kernel::modules::Gps gps;
	//  if (gps.getState() != kernel::modules::MES_OK)
	std::shared_ptr<DemoModule> demo1{new DemoModule{}};
	//  if (demo1.getState() != kernel::modules::MES_OK)
	//    exit(1);
	//
	//  kernel::modules::DemoModule demo2;
	//  if (demo2.getState() != kernel::modules::MES_OK)
	//    exit(1);
	//
	//  //register tasks
  DataController::registerModule(demo1);
	Scheduler::registerModule(demo1);
	//  kernel::services::Scheduler::registerRTTask(demo2.task());
	//
	//  // run scheduler
	  Scheduler::run();
	return 0;
}
