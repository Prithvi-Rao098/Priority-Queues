#include "main.h"
#include "data_structures.h"
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

ELEMENT **V = nullptr;  // Definition of the global variable V
HEAP *pHEAP = nullptr;  // Definition of the global variable pHEAP

using namespace std;

int main(int argc, char *argv[]) {
    string command;
    FILE *inputfile;
    FILE *outputFile;

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

            // first integer is number of elements
            int n;
            fscanf(inputfile, "%d", &n); 
            
            V = new ELEMENT*[n + 1]; 

            for (int i = 1; i <= n; i++) {
                V[i] = new ELEMENT; 
                fscanf(inputfile, "%lf", &V[i]->key); 
                V[i]->index = i;
                V[i]->pos = 0;
            }

            fclose(inputfile); 

            // allocated mem for heap
            pHEAP = new HEAP;
            pHEAP->capacity = n;
            pHEAP->size = 0;
            pHEAP->H = new int[n + 1];
        }

        else if (command == "PrintArray") {
            cout << "Instruction: PrintArray" << endl;

            if (V == NULL) {
                fprintf(stderr, "Error: array is NULL\n");
            } else {
                for (int i = 1; i <= pHEAP->capacity; i++) {
                    cout << V[i]->index << " ";
                    cout << fixed << setprecision(6) << V[i]->key << " "; 
                    cout << V[i]->pos << endl;
                }
            }
        }

        else if (command == "PrintHeap") {
            cout << "Instruction: PrintHeap" << endl;
            if (pHEAP == NULL) {
                fprintf(stderr, "Error: heap is NULL\n");
                exit(0);
            }
            cout << "Capacity = " << pHEAP->capacity << ", " << "size = " << pHEAP->size << endl;
            for (int i = 1; i <= pHEAP->size; i++){
                cout << "H[" << i << "] = " << pHEAP->H[i] << endl;
            }
        }

        else if (command == "BuildHeap") {
            cout << "Instruction: BuildHeap" << endl;
            BuildHeap();
        }

        else if (command == "Insert") {
            int index;
            cin >> index; 
            cout << "Instruction: Insert " << index << endl;
            Insert(index);
        }

        else if (command == "ExtractMin") {
            cout << "Instruction: ExtractMin" << endl;
            ExtractMin();
        }

        else if (command == "DecreaseKey") {
            cout << "Instruction: DecreaseKey" << endl;

        }

        else if (command == "Write") {
            cout << "Instruction: Write" << endl;

            outputFile = fopen(argv[2], "w");
            if (!outputFile) {
                fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                exit(0);
            }

            for (int i = 1; i <= pHEAP->capacity; i++) {
                fprintf(outputFile, "%d %lf %d\n", i, V[i]->key, V[i]->pos);
            }

            fclose(outputFile);
        }
    }
}