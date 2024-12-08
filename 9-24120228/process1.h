#pragma once
#include <iostream>
#include <stdint.h>
#include <string.h>
using namespace std;
#define GB 1 * 1024 * 1024 * 1024

void copy_file(const char* src, const char* dest, bool type);
void help();
void add_file(const char* src1, const char* src2, const char* dest_path);
void copy_path(const char* src, const char* dest_path);
void call(int32_t argc, char **dest);
void error_syntax();
void error_file();