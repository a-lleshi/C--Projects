#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include "vector"
using namespace std;
// TODO: your code goes here

class TimeAndCaseData {

private:
  int time;
  int numberOfCases;

public:
  TimeAndCaseData (int timeIn, int numberOfCasesIn) : time(timeIn), numberOfCases(numberOfCasesIn) {

  }

  int getTime() const {
    return time;
  }

  int getNumberOfCases() const {
    return numberOfCases;
  }

};

class CovidCaseMap {

private:
  int activateHour;
  vector<CovidCase> cc;
  vector<TimeAndCaseData> timeCaseData;


public:
  // add all cc cases to vector.
  void addCase(CovidCase ccIn) {
    cc.push_back(ccIn);
  }


  vector<TimeAndCaseData> getCasesOverTime(int activateHourIn) {
      activateHour = activateHourIn;
      int activeCases = 0;
      int i = 0;
      int x = 0;
      int currentActiveCase = cc[0].getTime() + activateHour;
      int currentCase = cc[0].getTime();

      timeCaseData.push_back(TimeAndCaseData(0, 0));

      do {

        if (currentActiveCase < currentCase) {
          --activeCases;
          timeCaseData.push_back(TimeAndCaseData(currentActiveCase, activeCases));

          ++x;
          currentActiveCase = cc[x].getTime() + activateHour;

        } else {
          if (i < cc.size()) {

            ++activeCases;
            timeCaseData.push_back(TimeAndCaseData(cc[i].getTime(), activeCases));

            ++i;
            currentCase = cc[i].getTime();

          } else if (currentActiveCase > currentCase) {
            --activeCases;
            timeCaseData.push_back(TimeAndCaseData(currentActiveCase, activeCases));

            ++x;
            currentActiveCase = cc[x].getTime() + activateHour;
          }
        }
      } while (activeCases != 0);

    return timeCaseData;
  }

  void supportVisitGreedyTSP(int lat, int lon, int time, int len) {

  }
};





// don't write any code below this line

#endif
