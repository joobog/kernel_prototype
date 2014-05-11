#include <map>
#include <string>
#include "data_controller.hpp"

namespace kernel {
  std::map<modules::ModType, std::weak_ptr<modules::IModule>> kernel::services::DataController::_data_container;
}
