#include <iostream>
#include "findTheName.hpp"

using namespace std;

int main()
{
    FindTheName file("hideMe.txt");
    file.search();
}