#include <iostream>
#include <string>
#include <array> 
#include "vigenere.h"

const std::array<char, 26> caps = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const std::array<char, 26> lower = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

// gets position of the char that is inputted, from 0 <= x <= 25
int get_position_in_array(char input) { 
    for(int i = 0; i < 26; i++) { 
        if(input == caps[i] || input == lower[i]) { 
            return i; 
        }
    }

    return 0; 
}

// gets char from the position of the inputted number
char cipher(int in, bool upper) { 
    if(in > 25) { 
        return is_upper ? caps[in - 26] : lower[in - 26]; 
    }

    return is_upper ? caps[in] : lower[in];
}

// checks if the input is uppercase or lowercase 
bool is_upper(char in) { 
    for(auto a : upper) { 
        if(a == in) { 
            return true; 
        }
    }

    return false;
} 

std::string encrypt_vigenere(std::string plaintext, std::string keyword) { 
    // 33 <= x <= 64, 91 <= x <= 96, 123 <= x <= 126 all special characters not including special letters
    for(int i = 0; i < keyword.length(); i++) { 
        int special_ascii_int = (int)keyword.at(i);
        
        if(33 <= special_ascii_int && special_ascii_int <= 64 || 91 <= special_ascii_int && special_ascii_int <= 96 || 123 <= special_ascii_int && special_ascii_int <= 126) { 
            return "Impossible keyword";
        }
    }

    int keyword_count = 0; 
    std::string result = ""; 

// ASCII Letters range, 65 <= x <= 90 && 97 <= x <= 122
    for(int i = 0; i < plaintext.length(); i++) { 
        if((int)(plaintext.at(i)) >= 65 && (int)plaintext.at(i) <= 90 || (int)plaintext.at(i) >= 97 && (int)(plaintext.at(i)) <= 122) { 
            result += get_char_cipher(get_position_in_array(plaintext.at(i)) + get_position_in_array(keyword.at(keyword_count)), is_upper(plaintext.at(i)));
            keyword_count++;
        } else { 
            result += plaintext.at(i); 
        }

        if(keyword_count == keyword.length()) { 
            keyword_count = 0; 
        } 
    }

    return result;  
}