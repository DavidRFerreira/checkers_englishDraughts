#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

void gotoxy(int x, int y);
void clear(void);
void print_slow(const std::string& str, int delay_time);