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
    while (cin >> command) {
        if (command == "Stop") {
            cout << "Instruction: Stop" << endl;
            break;
        }else if (command == "Read") {
            cout << "Instruction: Read" << endl;

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