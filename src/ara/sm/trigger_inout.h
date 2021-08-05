#ifndef TRIGGER_INOUT_H
#define TRIGGER_INOUT_H

#include "./trigger.h"
#include "./notifier.h"

namespace ara
{
    namespace sm
    {
        /// @brief State input and output trigger
        /// @tparam T State type
        template <typename T>
        class TriggerInOut
        {
        private:
            Trigger<T> mTrigger;
            Notifier<T> mNotifier;

        public:
            /// @brief Constructor
            /// @param T State
            /// @param hanlder Handler to be invoked after state change
            TriggerInOut(T &state, TriggerHandler handler) : mTrigger(state, handler),
                                                                mNotifier(state)
            {
            }

            TriggerInOut() = delete;
            ~TriggerInOut() noexcept = default;
            TriggerInOut(const TriggerInOut &) = delete;
            TriggerInOut(TriggerInOut &&) = delete;
            TriggerInOut &operator=(const TriggerInOut &) = delete;
            TriggerInOut &operator=(TriggerInOut &&) = delete;

            /// @brief Trigger property getter
            /// @returns The trigger
            Trigger<T> &Trigger() noexcept
            {
                return mTrigger;
            }

            /// @brief Notifier property getter
            /// @returns The notifier
            Notifier<T> &Notifier() noexcept
            {
                return mNotifier;
            }
        };
    }
}

#endif