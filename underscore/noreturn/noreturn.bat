gcc .\no_noreturn.c -o no_noreturn -Wmissing-noreturn
.\no_noreturn

gcc .\noreturn.c -o noreturn -Wmissing-noreturn
.\noreturn

gcc .\return.c -o return -Wmissing-noreturn
.\return
