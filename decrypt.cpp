#include <iostream>
#include <string>
#include <array> 
#include <iomanip>
#include "decrypt.h"
#include "vigenere.h"
#include "caesar.h"

const std::array<char, 26> caps = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const std::array<char, 26> lower = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

char uncipher(int in, bool upper) { 
    if(in < 0) { 
        return upper ? caps[in + 26] : lower[in + 26]; 
    }

    return upper ? caps[in] : lower[in];
}

char shift_char_uncipher(char c, int rshift) {  
    int shift = rshift % 26; 
    if(shift < 0) {  
        for(int i = 0; i < 26; i++) { 
            if(c == caps[i] && i - shift > 25) {
                return caps[(i - shift) - 26];
            } else if(c == lower[i] && i - shift > 25) { 
                return lower[(i - shift) - 26];
            } else if(caps[i] == c) { 
                return caps[i - shift]; 
            } else if(lower[i] == c) { 
                return lower[i - shift];
            }
            
        }
    } else {
        for(int i = 0; i < 26; i++) { 
            if(c == caps[i] && i - shift < 0) {
                return caps[26 - (shift - i)];
            } else if(c == lower[i] && i - shift < 0) { 
                return lower[26 - (shift - i)];
            } else if(caps[i] == c) { 
                return caps[i - shift]; 
            } else if(lower[i] == c) { 
                return lower[i - shift];
            } 
        }
    }

    return c;
}

std::string decrypt_caesar(std::string ciphertext, int rshift) { 
    std::string result = "";
    for(int i = 0; i < ciphertext.length(); i++) { 
        result += shift_char_uncipher(ciphertext.at(i), rshift); 
    }

    return result;
}


std::string decrypt_vigenere(std::string ciphertext, std::string keyword) { 
    int keyword_count = 0; 
    std::string result = ""; 
    
    for(int i = 0; i < keyword.length(); i++) { 
        int special_ascii_int = (int)keyword.at(i);
        
        if(33 <= special_ascii_int && special_ascii_int <= 64 || 91 <= special_ascii_int && special_ascii_int <= 96 || 123 <= special_ascii_int && special_ascii_int <= 126) { 
            return "Impossible keyword";
        }
    }

// ASCII Letters range, 65 <= x <= 90 && 97 <= x <= 122
    for(int i = 0; i < ciphertext.length(); i++) { 
        if((int)(ciphertext.at(i)) >= 65 && (int)ciphertext.at(i) <= 90 || (int)ciphertext.at(i) >= 97 && (int)(ciphertext.at(i)) <= 122) { 
            result += uncipher(get_position_in_array(ciphertext.at(i)) - 
            get_position_in_array(keyword.at(keyword_count)), is_upper(ciphertext.at(i)));
            
            keyword_count++;
        } else { 
            result += ciphertext.at(i); 
        }

        if(keyword_count == keyword.length()) { 
            keyword_count = 0; 
        } 
    }

    return result;  
}