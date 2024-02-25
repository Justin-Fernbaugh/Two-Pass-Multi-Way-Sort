/* This is a skeleton code for External Memory Sorting, you can make modifications as long as you meet 
   all question requirements*/  

#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "record_class.h"

using namespace std;

//defines how many blocks are available in the Main Memory 
#define buffer_size 22

Records buffers[buffer_size]; //use this class object of size 22 as your main memory
// vector<string> runs; //This vector will store the fstream objects for the runs


const string csvFName = "Emp.csv"; // Emp.csv is the file that we want to sort


//this file is implementing the merge-sort algorithm on Emp.csv
/***You can change return type and arguments as you want.***/

void swap(Records &a, Records &b) {
    Records temp = a;
    a = b;
    b = temp;
}

//PASS 1
//Sorting the buffers in main_memory and storing the sorted records into a temporary file (Runs) 
void Sort_Buffer(fstream &EmpCSV){
    //Remember: You can use only [AT MOST] 22 blocks for sorting the records / tuples and create the runs
    
    // iterate over buffers returning lowest id on each run and output to tmpFileX.csv where X is the run number
    int numRecords = 0;
    int run = 0;
    while (buffers[0].no_values != -1) {
        Records tmp;
        // for loop to grab 22 pages of tuples from Emp.CSV
        for (int i = 0; i < buffer_size; i++) {
            buffers[i] = Grab_Emp_Record(EmpCSV);
            if(buffers[i].emp_record.eid == 716859) {
                tmp = buffers[i];
            }
            // printf("Grabbed Emp Record: %d\n", buffers[i].emp_record.eid);
            if (buffers[i].no_values == -1) {
                break; // we've reached EOF
            }
            buffers[i].number_of_emp_records++;
            
        }
        run++;
        
        // sort the buffer in memory
        for (int i = 0; i < buffer_size; i++) {
            for (int j = i + 1; j < buffer_size; j++) {
                if (buffers[i].emp_record.eid > buffers[j].emp_record.eid) {
                    swap(buffers[i], buffers[j]);
                    if(buffers[i].emp_record.eid == 716859) {
                        tmp = buffers[i];
                    }
                }
            }
        }
        

        // output the sorted buffer to a tmpFileX.csv
        // printf("Creating tmpFile%d.csv\n", run);
        fstream tmpFile("tmpFile" + to_string(run) + ".csv", ios::in | ios::out | ios::trunc);
        for (int i = 0; i < buffer_size; i++) {
            if (buffers[i].no_values == -1) {
                break;
            }
            if(numRecords == 397) {
                tmpFile << tmp.emp_record.eid << "," << tmp.emp_record.ename << "," << tmp.emp_record.age << "," << tmp.emp_record.salary << "\n";
            }
            numRecords++;
            tmpFile << buffers[i].emp_record.eid << "," << buffers[i].emp_record.ename << "," << buffers[i].emp_record.age << "," << buffers[i].emp_record.salary << "\n";
            // printf("Outputted Emp Record: %d\n", buffers[i].emp_record.eid);
        }
        // printf("NumRecords: %d\n", numRecords);
        tmpFile.close();

        
    }
    printf("Sort_Buffer() PHASE 1 ret\n\n");
    return;
}

    void printVector(vector<Records> &myBuffer) {
        for (int i = 0; i < myBuffer.size(); i++) {
            printf("Buffer[%d]: %d\n", i, myBuffer[i].emp_record.eid);
        }
    }

//PASS 2
//Use main memory to Merge the Runs 
//which are already sorted in 'runs' of the relation Emp.csv 
// load the first record of each tmpFileX into memory
// iterate through in memory records and output lowest eid to EmpSorted.csv
// if a record is outputted from a run, load the next record from that run
// if a run is empty, remove it from the runs vector
// once only one run is left, output the rest of the records to EmpSorted.csv
void Merge_Runs(fstream &SortOut){
    // iterate through the runs and grab the first record from each
    fstream tmpFile1("tmpFile1.csv", ios::in | ios::out);
    fstream tmpFile2("tmpFile2.csv", ios::in | ios::out);
    fstream tmpFile3("tmpFile3.csv", ios::in | ios::out);
    fstream tmpFile4("tmpFile4.csv", ios::in | ios::out);
    fstream tmpFile5("tmpFile5.csv", ios::in | ios::out);
    fstream tmpFile6("tmpFile6.csv", ios::in | ios::out);
    fstream tmpFile7("tmpFile7.csv", ios::in | ios::out);
    fstream tmpFile8("tmpFile8.csv", ios::in | ios::out);
    fstream tmpFile9("tmpFile9.csv", ios::in | ios::out);
    fstream tmpFile10("tmpFile10.csv", ios::in | ios::out);
    fstream tmpFile11("tmpFile11.csv", ios::in | ios::out);
    fstream tmpFile12("tmpFile12.csv", ios::in | ios::out);
    fstream tmpFile13("tmpFile13.csv", ios::in | ios::out);
    fstream tmpFile14("tmpFile14.csv", ios::in | ios::out);
    fstream tmpFile15("tmpFile15.csv", ios::in | ios::out);
    fstream tmpFile16("tmpFile16.csv", ios::in | ios::out);
    fstream tmpFile17("tmpFile17.csv", ios::in | ios::out);
    fstream tmpFile18("tmpFile18.csv", ios::in | ios::out);
    fstream tmpFile19("tmpFile19.csv", ios::in | ios::out);
    vector<fstream*> runs = {&tmpFile1, &tmpFile2, &tmpFile3, &tmpFile4, &tmpFile5, &tmpFile6, &tmpFile7, &tmpFile8, &tmpFile9, &tmpFile10, &tmpFile11, &tmpFile12, &tmpFile13, &tmpFile14, &tmpFile15, &tmpFile16, &tmpFile17, &tmpFile18, &tmpFile19};
    vector<Records> myBuffer(19);

    for (int i = 0; i < myBuffer.size(); i++) {
        myBuffer[i] = Grab_Emp_Record(*runs[i]);
        // printf("Grabbed Emp Record: %d\n", buffers[i].emp_record.eid);
    }

    // iterate through in memory records and output lowest eid to EmpSorted.csv
    
    int ret = 0;
    while (runs.size() > 1){
        int lowest = 0;
        if(runs[lowest]->eof() != 0) {
            runs.erase(runs.begin() + lowest);
            // printf("EOF reached at %d\n", lowest);
            myBuffer[lowest].no_values = -1;
            // printf("before size: %d\n", myBuffer.size());

            myBuffer.erase(myBuffer.begin() + lowest);
            // printf("after size: %d\n", myBuffer.size());
            lowest++;
        }

        for (int i = 0; i < myBuffer.size(); i++) {
            if (myBuffer[i].no_values == -1) {
                // printf("hit continue\n");
                continue;
            }
            if (myBuffer[i].emp_record.eid < myBuffer[lowest].emp_record.eid) {
                lowest = i;
            }
        }
        ret = lowest;

        if(myBuffer[lowest].no_values != -1) {
            // printf("Outputted Emp Record: %d\n", myBuffer[lowest].emp_record.eid);
            string record = to_string(myBuffer[lowest].emp_record.eid) + "," + myBuffer[lowest].emp_record.ename + "," + to_string(myBuffer[lowest].emp_record.age) + "," + to_string(myBuffer[lowest].emp_record.salary) + "\n";
            SortOut.write(record.c_str(), record.size());
        }
        // SortOut << myBuffer[lowest].emp_record.eid << "," << myBuffer[lowest].emp_record.ename << "," << myBuffer[lowest].emp_record.age << "," << myBuffer[lowest].emp_record.salary << "\n";
        

        string line;
        getline(*runs[lowest], line, '\n');
        // printf("Got tuple: %s\n", line.c_str());
        
        // printf("after getline\n");

        if(line == "\n" || line == "") {
            // printf("Erase run: %d\n", runs.size());
            myBuffer[lowest].no_values = -1;
            // myBuffer.erase(myBuffer.begin() + lowest);
            // printf("Erasing done\n");
            continue;
        }

        myBuffer[lowest] = stringToRecord(line);
        // printf("after stringToRecord\n");
        
    }
    printf("broke while loop\n");
    // string line;
    // getline(*runs[ret], line, '\n');
    // printf("Got tuple: %s\n", line.c_str());
    // SortOut << line;
    

    // output the rest of the records to EmpSorted.csv
    //and store the Sorted results of your Buffer using PrintSorted() 
    return;
}

//This function will be used to print the sorted records in EmpSorted.csv
void PrintSorted(fstream &EmpSorted){
    string line;
    while(getline(EmpSorted, line)) {
        printf("%s\n", line.c_str());
    }
    //Store in EmpSorted.csv
    return;
}

int main() {

    //Open file streams to read and write
    //Opening out the Emp.csv relation that we want to Sort
    fstream empin;
    empin.open("Emp.csv", ios::in);
    printf("Emp.csv opened\n");
   

    // truncate or delete all contents of EmpSorted.csv
    fstream empSorted("EmpSorted.csv", ios::out | ios::trunc);
    empSorted.close();
    //Creating the EmpSorted.csv file where we will store our sorted results
    fstream SortOut("EmpSorted.csv", ios::out | ios::app); // Open SortOut in append mode

    //1. Create runs for Emp which are sorted using Sort_Buffer()
    printf("Creating runs for Emp.csv\n");
    Sort_Buffer(empin);
    empin.close();


    //2. Use Merge_Runs() to Sort the runs of Emp relations 
    printf("Merging runs for Emp.csv\n");
    Merge_Runs(SortOut);
    SortOut.close();

    //3. Print the sorted records in EmpSorted.csv
    printf("Printing sorted records in EmpSorted.csv\n");
    fstream empSorted2("EmpSorted.csv", ios::in);
    PrintSorted(empSorted2);
    empSorted2.close();


    //Please delete the temporary files (runs) after you've sorted the Emp.csv
    for (int i = 1; i <= 20; i++) {
        remove(("tmpFile" + to_string(i) + ".csv").c_str());
    }

    return 0;
}
