#include <gtest/gtest.h>
#include "../../../src/ara/exec/worker_runnable.h"

namespace ara
{
    namespace exec
    {
        class WorkerRunnableTest : public testing::Test, public WorkerRunnable<uint64_t>
        {
        public:
            virtual void  Run(uint64_t &element, WorkerThread &t) override
            {
                element = t.GetRandom() + 1;
            }
        };

        TEST_F(WorkerRunnableTest, RandomNumberAssignment)
        {
            uint64_t _element = 0;
            WorkerThread _workerThread;

            Run(_element, _workerThread);

            EXPECT_GT(_element, 0);
        }
    }
}