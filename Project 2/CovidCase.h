#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <cmath>
#include <iostream>
using std::ostream;
using namespace std;

// TODO: your code  goes here

class CovidCase {

private:
  double personLat;
  double personLon;
  string personName;
  int personAge;
  int personTestDate;

public:
  CovidCase(double personLatIn, double personLonIn, string personNameIn, int personaAgeIn, int personTestDateIn)
    : personLat(personLatIn), personLon(personLonIn), personName(personNameIn), personAge(personaAgeIn), personTestDate(personTestDateIn) {

    }

  CovidCase(string patientStrIn) {
    string latPersonStr;
    string lonPersonStr;
    string agePersonStr;
    int index = 0;

    index = patientStrIn.find(",");
    latPersonStr = patientStrIn.substr(0, index);
    patientStrIn = patientStrIn.substr(index+1);
    personLat = stod(latPersonStr);

    index = patientStrIn.find(",");
    lonPersonStr = patientStrIn.substr(0, index);
    patientStrIn = patientStrIn.substr(index+1);
    personLon = stod(lonPersonStr);

    index = patientStrIn.find("\"");
    patientStrIn = patientStrIn.substr(index+1);
    index = patientStrIn.find("\"");
    personName = patientStrIn.substr(0, index);

    index = patientStrIn.find(",");
    patientStrIn = patientStrIn.substr(index+1);
    index = patientStrIn.find(",");
    agePersonStr = patientStrIn.substr(0, index);
    patientStrIn = patientStrIn.substr(index+1);
    personAge = stoi(agePersonStr);

    personTestDate = stoi(patientStrIn);
  }

    void write(ostream & o) const {
      o << "{" << personLat << ", " << personLon << ", \"" << personName << "\", " << personAge << ", " << personTestDate << "}";
    }

    double getLatitude() const {
      return personLat;
    }

    double getLongitude() const {
      return personLon;
    }

    string getName() const {
      return personName;
    }

    int getAge() const {
      return personAge;
    }

    int getTime() const {
      return personTestDate;
    }

    double distanceTo(CovidCase personBIn) {
      double pi = 3.14159265359;
      double personBLat = personBIn.getLatitude();
      double personBLon = personBIn.getLongitude();

      double dLatA = personLat * (pi / 180);
      double dLonA = personLon * (pi / 180);
      double dLatB = personBLat * (pi / 180);
      double dLonB = personBLon * (pi / 180);

      double dLat = dLatB - dLatA;
      double dLon = dLonB - dLonA;

      double a = pow((sin(dLat/2)), 2) + cos(dLatA) * cos(dLatB) * pow((sin(dLon/2)), 2);
      double r = 3960;
      double c = 2 * atan2(sqrt(a), sqrt(1-a));

      double distance = r*c;
      return distance;
    }

    bool operator==(CovidCase personB) {
      return ((personLat == personB.getLatitude()) && (personLon == personB.getLongitude()) && (personName == personB.getName()) && (personAge == personB.getAge()) && (personTestDate == personB.getTime()));
    }

};

ostream & operator<<(ostream & o, const CovidCase & p) {
  p.write(o);
  return o;
}


// don't write any code below this line

#endif
