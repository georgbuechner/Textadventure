//Game Events

#include "CGameEvents.h"
using namespace std;

void CGameEvents::echo_item(CGame *game)
{
    cout << "Du nimmst "; // << item->getName() << " und verstaust es in deinen Rucksack" << endl;
}

void CGameEvents::echo_person(CGame*game)
{
    cout << "Du beginnst eine Unterhaltung mit ";// << person->getName() << ". " << endl;
}
