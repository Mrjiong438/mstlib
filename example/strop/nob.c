#define NOB_IMPLEMENTATION
#define PATH_MAX 4096
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER   "./"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

    Nob_Cmd cmd = {0};

#if !defined(_MSC_VER)
    // On POSIX
    nob_cmd_append(&cmd, "cc", "-std=c99", "-Wall", "-Wextra", "-o", BUILD_FOLDER"strsplit.out", SRC_FOLDER"filepath.c");
#else
    // On MSVC
    nob_cmd_append(&cmd, "cl", "-I.", "-o", BUILD_FOLDER"hello", SRC_FOLDER"hello.c");
#endif // _MSC_VER

    if (!nob_cmd_run_sync_and_reset(&cmd)) return 1;

#if !defined(_MSC_VER)
    // On POSIX
    nob_cmd_append(&cmd, BUILD_FOLDER"strsplit.out", "114,514,1919,810,asdasd \n");
#else
    // On MSVC
    nob_cmd_append(&cmd, "cl", "-I.", "-o", BUILD_FOLDER"hello", SRC_FOLDER"hello.c");
#endif // _MSC_VER
    if (!nob_cmd_run_sync_and_reset(&cmd)) return 1;

    return 0;
}
