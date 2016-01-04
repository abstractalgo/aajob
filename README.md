# aajob

Based on the large part of the https://github.com/AbstractAlgorithm/mt_jobqueue with minor tweaks, fixes and additions/removals.
Is free of any dependancy.
I plan on adding one additional mode and removing usage of std::list.

System spawns threads with `aajob::Init(numberOfThreads)`. You can add jobs with `aajob::RunJob()`. If you wish to use current thread as worker thread also, call `aajob::Flush()`. Cleanup is done within `aajob::Cleanup()`.

System uses one, global, mt-safe job queue. All jobs are pushed to the queue, and worker threads grab jobs from it. There isn't anything fancy about it, it's the simplest possible job manager that can exist. No sync, it's win-only, no lockless data structures. But in its simplicity, there is power. :P
