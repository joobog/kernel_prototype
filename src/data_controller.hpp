#ifndef SRC_DATA_CONTROLLER_HPP_
#define SRC_DATA_CONTROLLER_HPP_
#include <string>
#include <map>
#include <iostream>

#include "i_module.hpp"

// forward declarations
namespace kernel {
	namespace services {
		class IDataCarrier;
	}
}

namespace kernel {
	namespace services {
		class DataController {
			public:
				/**
				 * @brief Initialize the static data controller
				 * @details [long description]
				 */
				static void initialize() {}

				/**
				 * @brief Updates the data reference
				 * @details Data that is of interest for other modules or logging
				 * purposes can be published by passing it here
				 *
				 * @param[in] _inArg1 Generic container for the passed data
				 */
				static void registerModule (std::shared_ptr<modules::IModule> module)
				{
					_data_container.insert (
						std::make_pair < modules::ModType, std::shared_ptr<modules::IModule> >
						(module->type(), std::move(module)));
				}

				/**
				 * @brief Retrieves data from specified foreign module
				 * @details Data produced by other sub systems can be retrieved
				 * here publicly
				 *
				 * @param[in]   _inArg1 Unique identifier of the module to retrieve data from
				 * @return [description] Generic data object that needs to be downcasted to the
				 * actual type
				 */
				static modules::IDataCarrier* retrieveLast (std::string) {return nullptr;}

//				template class <T> const std::weak_ptr<T> retrieve<T>() {
//				  return std::shared_ptr<T>{new T};
//				}

			private:
				DataController();

				static std::map<modules::ModType, std::weak_ptr<modules::IModule>> _data_container;
		};
	} // namespace services
} // namespace kernel

#endif // SRC_DATA_CONTROLLER_HPP_
