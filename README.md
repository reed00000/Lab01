Write a command sequence to make a directory called “backup” underneath the current directory, then copy all the files in the current directory to “backup”

    mkdir backup
    cp * backup

How could you move all the files that end with an extension *.h in your home directory to the current directory without knowing the full path to the current directory [Hint: use a shortcut for the home directory and current directory.]

    cp ~/*.h . //tilde refers to home, dot refers to pwd.  the wildcard indicates only the .h filetypes

How could you remove a directory named “temp” (need to delete all the underneath files and sub-directories)

    rm -r temp

If a program becomes unresponsive, what two Linux commands could you use to identify the faulty program number and terminate it? 

    top //find the unresponsive process
    kill PID //kill with process ID

By using command line, how could you check the version of
the OS
    cat /etc/os-release
gcc, g++
    gcc --version OR g++ --version
python
    python3 --version