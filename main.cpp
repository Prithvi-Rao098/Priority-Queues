#include "main.h"
#include "data_structures.h"
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string command;
    FILE *inputfile;
    FILE *outputfile;

    ELEMENT **V;                                                    //initialize the element array
    HEAP *pHEAP;                                                    //initialize the heap array

    while (cin >> command) {
        if (command == "Stop") {
            cout << "Instruction: Stop" << endl;
            break;
        }else if (command == "Read") {
            cout << "Instruction: Read" << endl;

            inputfile = fopen(argv[1], "r");                        //open the file to read
            if (!inputfile){
                fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
                exit(0);
            }




        }
        else if (command == "PrintArray") {
            cout << "Instruction: PrintArray" << endl;

        }
        else if (command == "PrintHeap") {
            cout << "Instruction: PrintHeap" << endl;

        }
        else if (command == "BuildHeap") {
            cout << "Instruction: BuildHeap" << endl;

        }
        else if (command == "Insert") {
            cout << "Instruction: Insert" << endl;

        }
        else if (command == "ExtractMin") {
            cout << "Instruction: Insert" << endl;

        }
        else if (command == "DecreaseKey") {
            cout << "Instruction: Insert" << endl;

        }
        else if (command == "Write") {
            cout << "Instruction: Write" << endl;

        }
    }
}