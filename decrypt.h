#pragma once
#include <string>

char shift_char_uncipher(char c, int rshift);
std::string decrypt_caesar(std::string ciphertext, int rshift);
char uncipher(int in, bool upper);
std::string decrypt_vigenere(std::string ciphertext, std::string keyword);