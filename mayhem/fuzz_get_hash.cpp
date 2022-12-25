#include <fuzzer/FuzzedDataProvider.h>
#include <stdint.h>
#include <stdio.h>

#include <climits>

extern "C" int get_hash(char s[]);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    char* s = strdup(provider.ConsumeRandomLengthString(1000).c_str());

    get_hash(s);

    free(s);

    return 0;
}
