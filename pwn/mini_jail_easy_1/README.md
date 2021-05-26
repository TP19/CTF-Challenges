

1. Vuln 1

This challenge demonstrates how important is to be aware about the SETGID of a program and how it can be used to elevate the priviliges of the user and this way get the eUID of the file.
If a file can be accessed only by root, and another file has the GID of root but the user is not root and can execute it, then there are ways how the user can get temporary access to the root file (in fact of the whole system).
https://unix.stackexchange.com/questions/43744/what-does-gid-mean

2. Vuln 2

By exploiting the SETGID of the program, the users can use this to their advantage including escaping the from a chroot jail. The binary creates a temporary jail file and the user has to exploit a vulnerability against chroot to read the file outside of it. It is very important to mind the relative paths in this challenge.

### How to add this challenge:

compile the source c file like this `gcc mini_jail_easy_1.c -o mini_jail_easy_1` or use the binary that is ready.

After that make sure the user is not root. Then make a flag file with your flag and make it accesible only by root like this chmod 700 flag

Then make this challenge only executable by the user sudo chmod 771 challenge_1.

You also might want to chown both the flag and the challenge `sudo chown root:root flag` `sudo chown root:root mini_jail_easy_1`

Finally, set the GID of the file so the privileges care then passed to user `sudo chmod u+s mini_jail_easy_1`
