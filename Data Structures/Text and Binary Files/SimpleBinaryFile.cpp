
/*
 * Author : Hameed Abdul
 * Date : Aug 22nd, 2017
 * Purpose : To learn more about file formatting and raw data through the creation of a binary file
 * Licence : MIT
 * University of Southern Mississippi, GulfPark Campus
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    char input[100];
    strcpy(input, "learning lad rocks");

    fstream binFile("anil.bin", ios::in | ios::out | ios::binary | ios::trunc);

    if (!binFile) {
        cout << "error while opening the file \n";
        return 1;
    } else {
        int length = strlen(input);
        for (int counter = 0; counter <= length; counter++)
            binFile.put(input[counter]);
    }

    binFile.seekg(0);
    char ch;

    while (binFile.good()) {
        binFile.get(ch);
        cout << ch;
    }


    return 0;
}