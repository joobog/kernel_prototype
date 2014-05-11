#ifndef SRC_MODULES_I_MODULE_HPP_
#define SRC_MODULES_I_MODULE_HPP_
#include "modules/i_data_carrier.hpp"
#include <memory>
#include <iostream>
#include <cassert>
#include <vector>

// Forward declarations
namespace kernel {
	namespace modules {
		class IRTTask;
	}
}

namespace kernel {
	namespace modules {
		enum class ModuleErrorState {
		  OK,
		  UNDEF,
		  ERROR
    };

    enum class ModType {
      UNDEF,
      POSITIONING,
      LOGGER,
      GPS,
      DEMO
    };

		class IModule {
			public:
				virtual const ModType type() const = 0;
				virtual const std::string name() const = 0;
				virtual const unsigned short version() const = 0;
				virtual const unsigned short uid() const {return _uid;}
        virtual const std::vector<DataType> requires() const = 0;
				virtual const std::vector<DataType> provides() const = 0;

				IModule() : _uid{_id} {++_id;}
				virtual ~IModule() {}

				/**
				 * @brief Initialize the module
				 * @details Registers tasks if necessary and does all the
				 * work to set up the module for production.
				 * @return The return state of the initialization
				 */
				virtual const ModuleErrorState getState() const = 0;

				/**
				 * @brief Periodic task
				 * @details This holds a module specific implementation of IRTTask
				 * @return [description]
				 */
				virtual std::unique_ptr<modules::IRTTask> task() = 0;

				virtual void invoke() = 0;




			private:
				static unsigned short _id;
        unsigned short _uid;
		};
	} // namespace services
} // namespace kernel

#endif // SRC_MODULES_I_MODULE_HPP_
