#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {

private:
    std::string solution;
    int value;

public:

    CountdownSolution() : solution(), value(0) {}

    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }

    const std::string & getSolution() const {
        return solution;
    }

    int getValue() const {
        return value;
    }

};

// Do not edit above this line

// TODO: write code here:

double evaluateCountdown(string mathExpression) {
  // Initalise tokens and stack
  vector<string> tokens;
  stack<double> numStack;

  // Convert strings into a tokenised values in vector
  stringstream str(mathExpression);

  while (str.good()) {
    string substr;
    getline(str, substr, ' ');
    tokens.push_back(substr);
  }

  // For each value in the vector check if its an operator and calculate the output and push onto numStack
  // else push integer onto numStack
  for(string token : tokens) {

    if ((token == "+") || (token == "-") || (token == "*") || (token == "/")) {
      double a = numStack.top();
      numStack.pop();
      double b = numStack.top();
      numStack.pop();

      switch (token[0]) {
        case '+': numStack.push(b + a); break;
        case '-': numStack.push(b - a); break;
        case '*': numStack.push(b * a); break;
        case '/': numStack.push(b / a); break;
      }
    } else {
      numStack.push(stod(token));
    }

  }

  // Return the top of the stack.
  return numStack.top();

}

CountdownSolution solveCountdownProblem(vector<int> numIn, int targetIntIn) {
  // Vectors of all possible operations
  vector<string> operations{"+","-","*","/"};
  vector<vector<string>> op;


  // Vectors of all possible numbers
  vector<int> numberTemp;
  vector<vector<int>> numbers;

  string solutionStr;
  int targetInt = 0;
  double solutionInt = 0;

  // All possible ways to use the operators
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          for (int m = 0; m < 4; m++) {

             vector<string> temp = {operations[i], operations[j], operations[k], operations[l], operations[m]};
             op.push_back(temp);

           }
        }
      }
    }
  }


 // All possiblities of the order of the numbers
  do {
    for (int numb : numIn) {
      numberTemp.push_back(numb);
    }
    numbers.push_back(numberTemp);
    numberTemp.clear();
  } while(next_permutation(numIn.begin(), numIn.end()));


  bool checkFlag = false;
  solutionStr = intToString(numbers[0][0]);

  // start
  for(int i = 0; i < op.size(); ++i) {
    for (int j = 0; j < numbers.size(); ++j) {
      for (int x = 2; x < 7; ++x) {
          solutionStr += " " + intToString(numbers[j][x-1]) + " " +  op[i][x-2];
          solutionInt = evaluateCountdown(solutionStr);

          if (solutionInt == targetIntIn) {
            checkFlag = true;
            targetInt = solutionInt;
            break;
          }

          if (x == 6){
            solutionStr = intToString(numbers[0][0]);
          }
      }
      if (checkFlag == true){break;}
    }
    if (checkFlag == true){break;}
  }

  // return a CountdownSolution object
  return CountdownSolution(solutionStr, targetInt);
}


// Do not edit below this line


#endif
