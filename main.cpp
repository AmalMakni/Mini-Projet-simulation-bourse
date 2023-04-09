#include <iostream>
#include "date.h"
//test
using namespace std;

int main()
{
    TestDate t;
    t.incrementerDate();
    t.incrementerDate_finDuMois30();
    t.incrementerDate_finDuMois31();
    t.incrementerDate_finDuMois_fevrier_28();
    t.incrementerDate_finDuMois_fevrier_29();
    t.incrementerDate_finAnnee();
    t.initialiserDate_chaine1();
    t.initialiserDate_chaine2();
    t.superieur();
    return 0;
}
