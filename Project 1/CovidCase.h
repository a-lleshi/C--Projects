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

    void write(ostream & o) const {
      o << "{" << personLat << ", " << personLon << ", \"" << personName << "\", " << personAge << ", " << personTestDate << "}";
    }

    double getPersonLat() {
      return personLat;
    }

    double getPersonLon() {
      return personLon;
    }

    double distanceTo(CovidCase personBIn) {
      double pi = 3.14159265359;
      double personBLat = personBIn.getPersonLat();
      double personBLon = personBIn.getPersonLon();

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

};

ostream & operator<<(ostream & o, const CovidCase & p) {
  p.write(o);
  return o;
}

// don't write any code below this line

#endif
