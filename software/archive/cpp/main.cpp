#include "robot.h"
#include "log.h"

int main() {
    Robot& robot = Robot::getInstance();
    robot.run();
}
