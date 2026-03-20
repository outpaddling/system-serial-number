# System-hardware-identification

Allow non-root users to obtain limited system hardware identification
information from dmidecode.  As dmidecode accesses kernel memory for
some information, it can only be run by root.  This unfortunately
means that none of the information it provides can be obtained
without root privileges.

System-hardware-identification uses SUID to run

    dmidecode -s system-serial-number

and similar dmidecode commands to report hardware identification
information that need not be limited to the superuser in most
environments.

It does not allow the user to obtain any arbitrary information via
dmidecode, as some such information may be sensitive.

System-hardware-identification must be installed by the root user
in order to function, so it does not facilitate privilege escalation.
