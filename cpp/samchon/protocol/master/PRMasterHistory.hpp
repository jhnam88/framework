#pragma once
#include <samchon/API.hpp>

#include <samchon/protocol/master/PRInvokeHistory.hpp>

#include <atomic>
#include <vector>

namespace samchon
{
	namespace protocol
	{
		namespace master
		{
			class ParallelSystemArray;
			class PRMasterHistoryArray;

			/**
			 * @brief A history log of an Invoke message on a master.
			 * 
			 * @author Jeongho Nam
			 */
			class SAMCHON_FRAMEWORK_API PRMasterHistory
				: public PRInvokeHistory
			{
			protected:
				typedef PRInvokeHistory super;
				
				/**
				 * @brief A master the history is belonged to.
				 */
				ParallelSystemArray *master;

				/**
				 * @brief An array of histories which are generated in each system. 
				 */
				std::vector<PRInvokeHistory*> historyArray;

				std::atomic<size_t> completed;

			public:
				/**
				 * @brief Construct from master and invoke message.
				 * 		  
				 * @param master master
				 * @param invoke An invoke message to send
				 */
				PRMasterHistory(PRMasterHistoryArray*, std::shared_ptr<Invoke>, size_t, size_t);
				virtual ~PRMasterHistory() = default;

				virtual void notifyEnd() override;
			};
		};
	};
};