#ifndef __SHELL_H__
#define __SHELL_H__

#include "std_type.h"
void setTextColor(int color);
void handleYogurt();
void shell();
void parseCommand(char *buf, char *cmd, char arg[2][64]);
void handleCommand(char *cmd, char arg[2][64], char *buf);


#endif // __SHELL_H__
