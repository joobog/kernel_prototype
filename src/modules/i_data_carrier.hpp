#ifndef SRC_DATA_CARRIER_HPP_
#define SRC_DATA_CARRIER_HPP_

// forward declarations
namespace kernel {
	namespace modules {
		enum class DataType {
			UNDEF,
			GPS_RAW_DATA
		};

		/**
		 * @brief Generic class to exchange data
		 * @details This is the class for inter-module data exchange
		 * objects.
		 * Modules that need to exchange data with other modules or the
		 * kernel must use this type to pass their specific data.
		 */
		class IDataCarrier {
			public:
				virtual ~IDataCarrier() {}
		};
	}
}

#endif // SRC_DATA_CARRIER_HPP_
