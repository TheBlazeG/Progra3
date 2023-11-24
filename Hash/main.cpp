#include <iostream>
#include <string>
int hashing(const std::string &toHash);
std::string CesarIn(const std::string &toHash);
int main() {
    std::string mario="Mario";
   std::cout<<hashing(mario);
   std::string coded=(std::cout<<hashing(mario));
    std::cout<<;

    return 0;
}

int hashing(const std::string &toHash)
{
    int coder=1;
    int poopoo=0;
    for (char pp:toHash) {

poopoo+=pp*coder;
std::cout<<pp*coder<<std::endl;
        coder++;

    }
    return poopoo;
}

std::string CesarIn(const std::string &toHash)
{
    int coder=1;
    std::string poopoo=0;
    for (char pp:toHash) {

        poopoo+=pp*coder;
        std::cout<<pp*coder<<std::endl;
        coder++;

    }
    return poopoo;
}