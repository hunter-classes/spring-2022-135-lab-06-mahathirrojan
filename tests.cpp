#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("Task B: encrypting Caesar Cipher:") { 
    CHECK(encrypt_caesar("Hello, World!" , 10) == "Rovvy, Gybvn!");
}

TEST_CASE("Task C: encrypting Vigenere ciphers "){
    CHECK(encrypt_vignere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

TEST_CASE("Task D: decrypting: "){
    CHECK(decrypt_caesar(encrypt_caesar("Hello, World!", 10), 10) == "Hello, World!");

    CHECK(decrypt_caesar(encrypt_caesar("!@#$%^&*()!(&)!<>?><???", 26), 26) == "!@#$%^&*()!(&)!<>?><???");

    CHECK(decrypt_vigenere(encrypt_vigenere("Hello, World!", "cake"), "cake") == "Hello, World!");

    CHECK(decrypt_vigenere(encrypt_vigenere("Hello World!", "1234567890"), "1234567890") == "Impossible keyword"); 

    CHECK(decrypt_vigenere(encrypt_vigenere("Egg", "Vigenere"),"Vigenere") == "Egg");

}


// add your tests here
