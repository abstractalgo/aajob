#include <cstdio>
#include "aajob.hpp"

AAJOB_ENTRY_POINT(complexJob)
{
    int* pN = static_cast<int*>(jobDataPtr);
    DWORD tid = GetCurrentThreadId();
    printf("%d [%d]\n", *pN, tid);
}

int main()
{
    // init
    aajob::Init(4);

    // add jobs (opt.)
    int bla[100];
    for (int i = 0; i<100; i++)
    {
        bla[i] = i;
        aajob::JobDecl job(complexJob, bla + i);
        aajob::RunJob(job);
    }

    // run and help with jobs (opt.)
    //aajob::Flush();

    // cleanup
    aajob::Cleanup();

    // check
    system("pause");
    return 0;
}