#include <iostream> 
#include <string> 

void ascii_test(std::string word){
    for(int i=0;i < word.length(); i++){
        std::cout << word.at(i) << " " << (int)word.at(i) << std::endl;
    }
}

int main(){
    ascii_test("Cat :3 Dog");

    return 0; 
}