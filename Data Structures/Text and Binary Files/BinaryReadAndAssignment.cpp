/*
 * Author : Hameed Abdul
 * Date : Aug 22nd, 2017
 * Purpose : To learn more about file formatting and raw data through the creation of a binary file
 * Licence : The MIT License (MIT)
 * University of Southern Mississippi, GulfPark Campus
 */

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

int main()
{
    auto line = std::unique_ptr<char*>(new char*);
    auto temp = 0, salinaty = 0, height = 0, numOfRecs = 0;

    fstream dataFile("data.bin", ios::binary | ios::in );

    // Ensure that the file is open
    if(dataFile.is_open())
    {
        dataFile.seekg(0);
        dataFile.read((char *) &temp ,4);
        dataFile.read((char *) &salinaty ,4);
        dataFile.read((char *) &height ,4);
        dataFile.read((char *) &numOfRecs, 4);

        // Check to see if something broke in the process of reading
        if(dataFile.fail())
        // ERROR: COULD NOT READ THE FILE PROPERLY CHECK
        // CHECK PREVIOUS LINES OF CODE
            return 2;

        // Output data to the screen
        cout << temp << salinaty << height << numOfRecs << " ";

        // Collect all records of relevant data
        for(auto i = 0; i < numOfRecs; i++)
        {
            dataFile.read((char *) &salinaty ,4);
            cout << salinaty << " ";
        }
    }
    else
        // ERROR: FILE COULD NOT BE OPENED
        return 1;
    return 0;
}

