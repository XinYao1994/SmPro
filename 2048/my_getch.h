#ifndef __MYGETCH_H__
#define __MYGETCH_H__
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
char my_getch()
{
        int c=0;
        struct termios org_opts, new_opts;
        int res=0;
        res=tcgetattr(STDIN_FILENO, &org_opts);
        assert(res==0);
        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();
        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);assert(res==0);
        return c;
}
#endif
