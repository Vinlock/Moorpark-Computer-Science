// Dak Washbrook - M10A

/*
 // Input
 The first three integers are in the range 0..100000.  They represent seconds taken to solve the first, second, and third problems, respectively.
 Zero seconds indicates that a problem has not been solved.  The last three integers are in the range 0..100, representing the attempts taken to
 solve the first, second, and third problems, respectively.
 
 // Output
 Each output line should begin with the line number (right justified in a 3 character field), followed by a colon and a space, the teams name
 (left justified in a 40 character field), followed by a single space, the number of solved problems (right justified in a 2 character field),
 a single space, and the total number of seconds including penalties it took for the solved problems (right justified in a 7 character field).
 */


// Includes
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Namespace used.
using namespace std;

const int ZERO = 0, SOLVED = 1, NOT_SOLVED = 0, COLUMN1 = 3, COLUMN2 = 40, COLUMN3 = 2, COLUMN4 = 7; // Declaring Constants for zero, if solved, and the column lengths.
const string READ_FILE = "RawScore.dat", WRITE_FILE = "ComputedScore.dat"; // Declaring Constants for the filenames.

// Prototypes
int Solved(int score);
bool ReadInputRecord(ifstream &, int &, int &, int &, int &, int &, int &, string &);
bool WriteInputRecord(ofstream &, int, string, int, int);
int CountLines(string);

int main() {
    
    // Declaring all integer values.
    int numLines = ZERO, iteration = ZERO, score1, score2, score3, attempt1, attempt2, attempt3, numSolved, totalTime;
    
    // Declaring the fstreams for the read and writted files.
    ifstream filename;
    ofstream newFilename;
    
    string teamName; // Declaring the string for the team name column.
    
    numLines = CountLines(READ_FILE); // Counts the number of lines in a file.
    
    if (numLines > 0) {
        
        cout << "Opening " << READ_FILE << endl;
        
        filename.open(READ_FILE); // Open the READ_FILE and stream contents.
        
        if (filename) {
            
            cout << READ_FILE << " successfuly opened." << endl << endl;
            
            cout << "Opening " << WRITE_FILE << endl;
            
            // Open the WRITE_FILE and stream contents.
            newFilename.open(WRITE_FILE);
            
            if (newFilename) {
                
                cout << WRITE_FILE << " successfully opened." << endl << endl;
                
                // For each line, read contents, then convert to desired output and write.
                for (int i = ZERO; i < numLines; i++) {
                    cout << "Reading line." << endl;
                    // Read the contents of 'filename' and store it into the reference variables.
                    if (ReadInputRecord(filename, score1, score2, score3, attempt1, attempt2, attempt3, teamName)) {
                        cout << "Line successfully read" << endl; // Say the line is read if it didn't fail.
                        cout << "Team: " << teamName << " found." << endl; // Say the name of the team it found on the current line.
                        cout << "Calculating number of successfully solved problems by " << teamName << "." << endl;
                        numSolved = Solved(score1) + Solved(score2) + Solved(score3); // Find out how many were solved by the team.
                        cout << teamName << " solved " << numSolved << " problems." << endl; // Output number of solved problems by the team on the current line.
                        cout << "Calculating total time it took " << teamName << " to solve " << numSolved << " problems." << endl;
                        totalTime = score1 + score2 + score3; // Fine the total time that it took for them to solve all problems.
                        cout << teamName << " took " << totalTime << " seconds to solve " << numSolved << " problems." << endl; // Output the total time it took the team on the current line.
                        iteration++; // Iterate for the first column's number.
                        cout << "Writing data to " << WRITE_FILE << endl;
                        if (WriteInputRecord(newFilename, iteration, teamName, numSolved, totalTime)) { // Write the new output to 'newFilename'.
                            cout << "Data written to " << WRITE_FILE << endl << endl; // Output that the data was successfully written.
                        }
                        else {
                            cout << "Error writing data to file." << endl << endl; // If failed to write, output an error.
                            break; // Break the loop due to error.
                        }
                    }
                    else {
                        cout << "Error reading line." << endl << endl; // If failed to write, output an error.
                        break; // Break the loop due to error.
                    }
                }
                
                cout << "Closing " << WRITE_FILE << endl;
                newFilename.close(); // Close the WRITE_FILE;
                if (newFilename.is_open()) {
                    cout << "Error closing file." << endl << endl; // If failed to close, output an error.
                    return 0; // If failed to close, end program.
                }
                else {
                    cout << WRITE_FILE << " closed." << endl << endl;
                }
            }
            else {
                // If 'newFilename' failed to open, display an error message.
                cout << "Error Opening " << WRITE_FILE << endl << endl;
            }
            
            cout << "Closing " << READ_FILE << endl;
            filename.close(); // Close the READ_FILE.
            if (filename.is_open()) {
                cout << "Error closing file." << endl << endl; // If failed to close, output an error.
                return 0; // If failed to close, end program.
            }
            else {
                cout << READ_FILE << " closed." << endl << endl;
            }
        }
        else {
            // If 'filename' failed to open, display an error message.
            cout << "Error Opening " << READ_FILE << endl << endl;
        }
    }
    else {
        // If the file is empty then alert user.
        cout << READ_FILE << " is empty." << endl << endl;
    }
    
    return 0;
    
}

bool ReadInputRecord(ifstream &filename, int &score1, int &score2, int &score3, int &attempt1, int &attempt2, int &attempt3, string &teamName) {
    // Change the values of the reference variables to be the contents of the current line.
    if (filename >> score1 >> score2 >> score3 >> attempt1 >> attempt2 >> attempt3 >> teamName) {
        return true;
    }
    else {
        return false;
    }
}

bool WriteInputRecord(ofstream &newFilename, int iteration, string teamName, int numSolved, int totalTime) {
    // Write a new line to the 'newFilename' with the desired values and formatting. Also, sets the correct column widths for each column.
    if (newFilename << setw(COLUMN1) << iteration << ": " << setw(COLUMN2) << left << teamName << right << " " << setw(COLUMN3) << numSolved << " " << setw(COLUMN4) << totalTime << endl) {
        return true;
    }
    else {
        return false;
    }
}

int Solved(int score) {
    
    /* This function calculates if the problem was solved or not.
     Outputs SOLVED if it was, ZERO if it was not. Allowing
     the outputs to be added together to produce the total
     number of solved problems.
     */
    
    if (score > ZERO) { // Find if the problem was solved by seeing if their seconds were greater than 0.
        return SOLVED; // Return SOLVED if solved.
    }
    else {
        return NOT_SOLVED; // Return NOT_SOLVED if not solved.
    }
}

int CountLines(string file) {
    
    /* This function finds the number of lines that exist in a file and outputs that number. */
    
    int numLines = ZERO; // Initiate numLines.
    ifstream filename;
    string line;
    
    filename.open(file); // Open the filename that was passed into the function via a string.
    
    if (filename) {
        
        cout << "Counting number of lines in " << file << endl;
        
        while (getline(filename, line)) {
            // For each line, iterate numLines.
            numLines++;
        }
        
        cout << numLines << " line(s) counted." << endl << endl;
        
        filename.close(); // Close the file after done.
        
    }
    else {
        cout << file << " could not be opened." << endl << endl;
    }
    
    return numLines; // Return the number of lines that exist.
}
