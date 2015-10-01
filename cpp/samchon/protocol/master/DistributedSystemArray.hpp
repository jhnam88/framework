#pragma once
#include <samchon/API.hpp>

#include <samchon/protocol/ExternalSystemArray.hpp>

#include <samchon/Dictionary.hpp>
#include <samchon/library/GAParameters.hpp>

namespace samchon
{
	namespace protocol
	{
		namespace master
		{
			class DistributedSystem;
			class DistributedSystemRole;

			/**
			 * @brief An array of distributed system drivers.
			 *
			 * @details
			 * <p> DistributedSystemArray class is an ExternalSystemArray and an abstract class containing
			 * and managing distributed system drivers in framework of master. The DistributedSystemArray 
			 * class allocates DistributedSystemRole objects to DistributedSystem objects for optimization. </p>
			 *
			 * <p> Unlike the ExternalSystemRole class which is dependent on an ExternalSystem, DistributedSystemRole 
			 * is not dependent on a DistributedSystem and even can be allocated to multiple DistributedSystem 
			 * objects. Allocation of DistributedSystemRole(s) to DistributedSystem(s) is determined by estimation of
			 * performance index pursuing best distribution. If number of DistributedSystem and DistributedSystemRole
			 * objects is not a lot, optimize by combined permuation algorithm. Else the objects are a lot,
			 * the allocation will be optimized by genetic algorithm. </p>
			 *
			 * <p> @image html  cpp/protocol_master_distributed_system.png
			 *	   @image latex cpp/protocol_master_distributed_system.png </p>
			 *
			 * \par [Inherited]
			 *		@copydoc protocol::ExternalSystemArray
			 */
			class SAMCHON_FRAMEWORK_API DistributedSystemArray
				: public virtual ExternalSystemArray
			{
			protected:
				typedef ExternalSystemArray super;

				/**
				 * @brief A dictionary of role objects.
				 *
				 * @details 
				 */
				Dictionary<std::shared_ptr<DistributedSystemRole>> roleDictionary;

				/**
				 * @brief A structure of parameters for genetic algorithm
				 *
				 * @details
				 * <p> . </p>
				 */
				struct library::GAParameters gaParameters;

			public:
				/* ------------------------------------------------------------------
					CONSTRUCTORS
				------------------------------------------------------------------ */
				/**
				 * @brief Default Constructor.
				 */
				DistributedSystemArray();
				virtual ~DistributedSystemArray() = default;

				virtual void construct(std::shared_ptr<library::XML>) override;

			protected:
				/**
				 * @brief Factory method of a DistributedSystemRole.
				 *
				 * @details
				 * <p> . </p>
				 *
				 * @param An XML object represents the role.
				 * @return A new DistributedSystemRole.
				 */
				virtual auto createRole(std::shared_ptr<library::XML>) -> DistributedSystemRole* = 0;
				
			public:
				/* ------------------------------------------------------------------
					PROCESS
				------------------------------------------------------------------ */
				virtual void start() override;

				/**
				 * @brief Allocate roles to each distributed processing system.
				 *
				 * @details
				 * <p> Allocates DistributedSystemRole objects to Distributedsystem objects. The allocation
				 * will be done when: </p>
				 *	\li New distributed system (client) has connected.
				 *	\li Ordinary distributed system is disconnected.
				 *	\li Deviation of elapsed time of whole DistributedSystem overs limited value.
				 *
				 * <p>
				 */
				virtual void allocateRoles();

				/* ------------------------------------------------------------------
					GETTERS
				------------------------------------------------------------------ */
				SHARED_ENTITY_ARRAY_ELEMENT_ACCESSOR_HEADER(DistributedSystem)

				/**
				 * @brief Get a role
				 *
				 * @param name An identifier of an DistributedSystemRole
				 * @return A shared pointer of specialized role
				 */
				auto getRole(const std::string &) const -> std::shared_ptr<DistributedSystemRole>;

				/* ------------------------------------------------------------------
					EXPORTERS
				------------------------------------------------------------------ */
				virtual auto toXML() const -> std::shared_ptr<library::XML> override;
			};
		};
	};
};