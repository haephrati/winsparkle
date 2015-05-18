#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "winsparkle-version.h"
#include "appcast.h"

static void Fail(const char* msg)
{
    std::printf("FAIL %s\n", msg);
    std::exit(1);
}

int main()
{
    if (WIN_SPARKLE_VERSION_MAJOR != 0 || WIN_SPARKLE_VERSION_MINOR != 4 || WIN_SPARKLE_VERSION_MICRO != 0)
    {
        Fail("version numbers");
    }
    if (std::strcmp(WIN_SPARKLE_VERSION_STRING, "0.4.0") != 0)
    {
        Fail("version string");
    }
    if (!WIN_SPARKLE_CHECK_VERSION(0, 4, 0))
    {
        Fail("check current");
    }
    if (!WIN_SPARKLE_CHECK_VERSION(0, 3, 9))
    {
        Fail("check older");
    }
    if (WIN_SPARKLE_CHECK_VERSION(0, 5, 0))
    {
        Fail("check newer");
    }

    winsparkle::Appcast item;
    if (item.IsValid() || item.HasDownload())
    {
        Fail("empty appcast");
    }
    item.Version = "1.2.3";
    if (!item.IsValid())
    {
        Fail("valid version");
    }
    item.DownloadURL = "https://example.invalid/update.exe";
    if (!item.HasDownload())
    {
        Fail("has download");
    }

    std::printf("OK WinSparkleTests\n");
    return 0;
}
