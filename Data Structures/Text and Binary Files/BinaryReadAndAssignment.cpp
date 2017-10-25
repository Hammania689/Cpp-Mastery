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

// Use to read binary file, store data into a int* (Unique Ptr - handles malloc)
// Takes a file( built for Binary files) and two integers all by reference
// Returns int* with stored Record Data
// Will be used to store Record data in subsequent binary and text files
std::unique_ptr<int[]> ReadRecord(std::fstream &bin, int &recs, int &t);

// Use to write data to data to new binary and text files
// Parameters: original binary file (Data.in), a new binary file, a new text file, and the number of current records
void WriteToFiles(std::unique_ptr<int[]> &data, std::fstream &newBin, fstream &txt, int &recs);

void CheckSmartPointerData(std::unique_ptr<int[]> &ptr, int &recs);

int main(int argc, char *argv[]) {
    // Fstreams to files and binary files
    fstream textFile("DataOutput.txt", ios::out);

    // Variables that correlate to Record data present in Datafile
    auto temp = 0, salinaty = 0, height = 0, numOfRecs = 0;

    // Error Insufficient number of Parameters
    if (argc != 2) {
        cout << "Error; Usage: " << argv[0] << " <filename> \n";
    } else {
        fstream dataFile(argv[1], ios::binary | ios::in);

        // Point to the very beginning of the file
        dataFile.seekg(0);

        // Ensure that the file is open
        if (dataFile.is_open()) {
            // Smart pointer dedicated to hold current Record Variable Values
            auto ptr = std::unique_ptr<int[]>();

            // Read File metadata to determine which variables are relevant
            dataFile.read((char *) &temp, 4);
            dataFile.read((char *) &salinaty, 4);
            dataFile.read((char *) &height, 4);
            dataFile.read((char *) &numOfRecs, 4);

            // Check to see if something broke in the process of reading
            // ERROR: COULD NOT READ THE FILE PROPERLY CHECK
            // CHECK PREVIOUS LINES OF CODE
            if (dataFile.fail()) {
                return 2;
            }

            // Output data to the screen
            cout << temp << salinaty << height << numOfRecs << " ";

            if (textFile) {
                if (temp != 0) {
                    ptr = move(ReadRecord(dataFile, numOfRecs, temp));
                    textFile << "Temp: ";
                    fstream newBin("temp.bin", ios::binary | ios::out);
                    cout << endl << endl << "Temperature : \n";
                    if (newBin.fail()) {
                        return 2;
                    }
                    WriteToFiles(ptr, newBin, textFile, numOfRecs);
                    newBin.close();
                }
                if (salinaty != 0) {
                    ptr = move(ReadRecord(dataFile, numOfRecs, salinaty));
                    textFile << "Salinaty: ";
                    cout << endl << endl << "Salinaty: \n";
                    fstream newBin("salinaty.bin", ios::binary | ios::out);
                    if (newBin.fail()) {
                        return 2;
                    }
                    WriteToFiles(ptr, newBin, textFile, numOfRecs);
                    newBin.close();
                }
                if (height != 0) {
                    ptr = move(ReadRecord(dataFile, numOfRecs, height));
                    textFile << "Height :";
                    cout << endl << endl << "Height: \n";
                    fstream newBin("height.bin", ios::binary | ios::out);
                    if (newBin.fail()) {
                        return 2;
                    }
                    WriteToFiles(ptr, newBin, textFile, numOfRecs);
                    newBin.close();
                }
            } else {
                return 3;
            }

            // Check to see that the unique ptr transfer happen
        } else {
            // ERROR: FILE COULD NOT BE OPENED
            return 1;
        }
        dataFile.close();
    }

    //CheckSmartPointerData(ptr, numOfRecs);
    textFile.close();
    cin.get();
    return 0;
}

void CheckSmartPointerData(std::unique_ptr<int[]> &ptr, int &recs) {
// Check to see that the unique ptr transfer happen
    cout << endl << endl << endl << endl << "Unique pointer data :" << endl;
    for (auto i = 0; i < recs; i++)
        cout << ptr[i] << " ";
}

// Use to Read and store data(OWNERSHIP MUST BE PASSED) into smart pointer for later use
std::unique_ptr<int[]> ReadRecord(std::fstream &bin, int &recs, int &t) {
    // Original Pointer owner of Record data
    auto p = std::make_unique<int[]>(recs);

    for (auto i = 0; i < recs; i++) {
        // Read file in increments of 4 bytes
        // Store Variable at proper index
        bin.read((char *) &t, 4);
        p[i] = t;
    }
    // Returns information stored into p
    return p;
}

// Takes UniquePtr and passes array values to the binary and text file through loop
void WriteToFiles(std::unique_ptr<int[]> &data, std::fstream &newBin, fstream &txt, int &recs) {
    for (auto i = 0; i < recs; i++) {
        newBin.write((char *) &data[i], sizeof(int));
        txt << data[i] << " ";
        cout << data[i] << " ";
    }
    txt << endl;

    if (newBin.fail()) {
        cout << "Error while trying to write data to the new Binary file" << endl;
    }
}
