/* This is a skeleton code for External Memory Sorting, you can make modifications as long as you meet 
   all question requirements*/  
/* This record_class.h contains the class Records, which can be used to store tuples form Emp.csv (stored
in the EmpRecord).
*/
#include <bits/stdc++.h>

using namespace std;

class Records{
    public:
    
    struct EmpRecord {
        int eid;
        string ename;
        int age;
        int salary;
    }emp_record;

    /*** You can add more variables if you want below ***/

    int no_values = 0; //You can use this to check if you've don't have any more tuples
    int number_of_emp_records = 0; // Tracks number of emp_records you have on the buffer
};

Records stringToRecord(string line) {
    string word;
    Records emp;
    // turn line into a stream
    // printf("stringToRecord\n");

    stringstream s(line);
    // gets everything in stream up to comma
    getline(s, word,',');
    emp.emp_record.eid = stoi(word);
    getline(s, word, ',');
    emp.emp_record.ename = word;
    // printf("Emp Record Name: %s, word: %s\n", emp.emp_record.ename.c_str(), word.c_str());
    getline(s, word, ',');
    emp.emp_record.age = stoi(word);
    getline(s, word, ',');
    emp.emp_record.salary = stoi(word);
    // printf("return record\n");

    return emp;
}

// Grab a single block from the Emp.csv file and put it inside the EmpRecord structure of the Records Class
Records Grab_Emp_Record(fstream &empin) {
    string line, word;
    Records emp;
    // grab entire line
    if (getline(empin, line, '\n')) {
        // turn line into a stream
        stringstream s(line);
        // gets everything in stream up to comma
        getline(s, word,',');
        emp.emp_record.eid = stoi(word);
        getline(s, word, ',');
        emp.emp_record.ename = word;
        // printf("Emp Record Name: %s, word: %s\n", emp.emp_record.ename.c_str(), word.c_str());
        getline(s, word, ',');
        emp.emp_record.age = stoi(word);
        getline(s, word, ',');
        emp.emp_record.salary = stoi(word);

        return emp;
    } else {
        emp.no_values = -1;
        return emp;
    }
}
