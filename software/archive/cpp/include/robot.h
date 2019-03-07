#ifndef ROBOT_H
#define ROBOT_H
#include "navigation.h"
#include "collection.h"
#include "elevation.h"
#include "distribution.h"
#include "celebration.h"

class Robot {
public:
    static Robot& getInstance();
    void run();
private:
    Navigation navigation;
    Collection collection;
    Elevation elevation;
    Distribution distribution;
    Celebration celebration;

    Robot();
};
#endif
