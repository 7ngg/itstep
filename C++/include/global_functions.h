#pragma once

#include <iostream>

uint16_t len(char* str);
bool compare(char* str1, char* str2);
bool search(char* text, char* word);

bool fileExists(const char* name);
bool isMember(int* arr, int arrLen, int num);
void getClick(int& x, int& y);
