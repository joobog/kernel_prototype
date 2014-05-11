#ifndef SRC_DATA_CARRIER_HPP_
#define SRC_DATA_CARRIER_HPP_

namespace kernel {
	namespace modules {
		/**
		 * @brief Generic class to exchange data
		 * @details This is the class for inter-module data exchange
		 * objects.
		 * Modules that need to exchange data with other modules or the
		 * kernel must use this type to pass their specific data.
		 */
		class IDataCarrier {
			public:
				virtual ~IDataCarrier() {};

				virtual const kernel::modules::ModID getModID() const
				{
					return _mod_id;
				};

			protected:
				IDataCarrier (const kernel::modules::ModID) {};

			private:
				kernel::modules::ModID _mod_id;
		};
	}
}

#endif // SRC_DATA_CARRIER_HPP_
