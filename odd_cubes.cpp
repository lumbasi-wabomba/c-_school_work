#include <iostream>
using namespace std;

int main() {
    int number =100;
    while(number<=100 && number >=50){
        if (number % 2 !=0){
          int cube = number*number*number;
          cout<< "the cube of "<<number <<" is " <<cube<< endl;
        }
        number--;
    }
    return 0;
}