#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("Task B: encrypting Caesar Cipher:") { 
    CHECK(encrypt_caesar("Hello, World!" , 10) == "Rovvy, Gybvn!");
}

TEST_CASE("Task C: ecrypting Vigenere Cipher:"){
    CHECK(encrypt_vigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encrypt_vigenere("Hello, World!", "EGG") == "Lkrpu, Csxrh!");
}

TEST_CASE("Task D: decrypting: "){
    CHECK(decrypt_caesar(encrypt_caesar("Hello, World!", 10), 10) == "Hello, World!");

    CHECK(decrypt_caesar(encrypt_caesar("!@#$%^&*()!(&)!<>?><???", 26), 26) == "!@#$%^&*()!(&)!<>?><???");

    CHECK(decrypt_vigenere(encrypt_vigenere("Hello, World!", "cake"), "cake") == "Hello, World!");

        CHECK(decrypt_vigenere(encrypt_vigenere("Hello, World!", "1234567890"), "1234567890") == "Impossible keyword");
        CHECK(decrypt_vigenere(encrypt_vigenere("Vigenere", "EGG"), "EGG") == "Vigenere");

}


// add your tests here
