/***************************************************************************
 *  Description:
 *      Obtain the system serial number via dmidecode and SUID.
 *
 *  Arguments:
 *
 *  Returns:
 *      0 on success, non-zero error codes otherwise
 *
 *  History: 
 *  Date        Name        Modification
 *  2025-10-06  Jason Bacon Begin
 ***************************************************************************/

#include <stdio.h>
#include <sysexits.h>
#include <unistd.h>
#include <xtend/proc.h>

int     usage(char *argv[]);

int     main(int argc,char *argv[])

{
    switch(argc)
    {
        case 1:
            break;
        
        default:
            return usage(argv);
    }
    
    setuid(0);
    return xt_spawnlp(P_WAIT, P_NOECHO, NULL, NULL, NULL,
                "dmidecode", "--string", "system-serial-number", NULL);
}


int     usage(char *argv[])

{
    fprintf(stderr, "Usage: %s\n", argv[0]);
    return EX_USAGE;
}
