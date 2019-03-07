#include "robot.h"
#include "log.h"

Robot::Robot() :
    navigation(Navigation::getInstance()),
    collection(Collection::getInstance()),
    elevation(Elevation::getInstance()),
    distribution(Distribution::getInstance()),
    celebration(Celebration::getInstance())
{
    Log("Robot startup\n");
}

Robot& Robot::getInstance() {
    static Robot instance;
    return instance;
}

void Robot::run() {
    navigation.toInnerZone();
}
