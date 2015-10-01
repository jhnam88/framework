#pragma once
#include <samchon/API.hpp>

#include <samchon/protocol/master/DistributedSystemArray.hpp>
#include <samchon/protocol/ExternalServerArray.hpp>

namespace samchon
{
	namespace protocol
	{
		namespace master
		{
			/**
			 * @brief An array of DistributedServer(s).
			 *
			 * @details
			 * <p> DistributedServerArray is an DistributedSystemArray specialized in servers' driver. </p>
			 *
			 * \par Inherited
			 *		@copydoc master::DistributedSystemArray
			 */
			class SAMCHON_FRAMEWORK_API DistributedServerArray
				: public virtual DistributedSystemArray,
				public virtual ExternalServerArray
			{
			protected:
				typedef ExternalSystemArray super;

			public:
				/**
				 * @brief Default Constructor.
				 */
				DistributedServerArray();
				virtual ~DistributedServerArray() = default;

				virtual void start() override;
			};
		};
	};
};