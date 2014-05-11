#include "modules/demo_module/demo_module.hpp"
#include "modules/demo_module/demo_task.hpp"

kernel::modules::DemoModule::DemoModule()
	:
	_err_state {ModuleErrorState::UNDEF},
_task {new DemoTask{}} {
	// Initialisierungscode optional
	using namespace kernel::modules;

	_err_state = ModuleErrorState::OK;
}

