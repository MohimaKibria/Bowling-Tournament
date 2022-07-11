#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
#define rounds 4
const string scores = "BowlingScores.txt";//avoid hardcoding file name
char z = '*', s = ' ';

struct Tournament 
{
    string contestant;
    int points[rounds]{};
    int average{};
};//organized different data types such as names and points in the bowling tournament. 


bool getBowlingData(const string& scores, Tournament players[], int & sum);
void GetAverageScore(Tournament players[], int sum);
void PrettyPrintResults(Tournament players[], int sum);
//this is the order each function should be read in order to work.

int main()
{
  cout << setw(68) << setfill('*') << z << endl;
  cout << setw(20) << setfill('*') << z << " What's The Average Score? " << setw(21) << setfill('*') << z << endl;
  cout << setw(68) << setfill(z) << z << endl; //intro to program using manipulators in order to prevent hard-coding.
    int sum = 0;
    ifstream fs; fs.open(scores); 

    Tournament players[10];
    if (getBowlingData(scores, players, sum))
    {
        GetAverageScore(players, sum);
        PrettyPrintResults(players, sum);
    } 
    else {
        cout <<"\n**File Required**" << endl;//shows user that the file is required for the output
    }
    return 0;
}
void PrettyPrintResults(Tournament players[], int sum) {

cout<<"Players"<<setw(5) << setfill(' ') << s << "Round#1"<< setw(5) << setfill(' ') << s << "Round#2" << setw(5) << setfill(' ') << s <<"Round#3"<< setw(5) << setfill(' ') << s <<"Round#4" << setw(5) << setfill(' ') << s  << "Average" << endl;//outputs each round of scores with spaces inbetween

    for (int i = 0; i < sum; i++) {
        cout << left << setw(15) << players[i].contestant;//the dot operator is used throughout this code. Here it is used to access each players name in the loop.
        for (int score: players[i].points) {
            cout << score << setw(8) << setfill(' ') << s<< "\t";
          }//outputs scores for each player
        cout << setw(5) << players[i].average << endl;//outputs average for each player
    }
}
bool getBowlingData(const string& scores, Tournament players[], int & sum) {
    ifstream fs; fs.open(scores);
  
    if (fs.fail()) 
        return false;
     else {
        while (fs >> players[sum].contestant) {
            for (int & score : players[sum].points) {
                fs >> score;
            }
            sum++;
        }
    }//opens txt file to read the data
    return true;
  }
void GetAverageScore(Tournament players[], int sum) {
    double overall;

    for (int i = 0; i < sum; i++) {
        overall = 0;
        for (int score : players[i].points) {//dot used to access points
            overall += score;
          }
        players[i].average = (overall);}
}//this function uses loops to find the mean score of each player.
