#include "navigation.h"
#include "log.h"

Navigation& Navigation::getInstance() {
    static Navigation instance;
    return instance;
}

void Navigation::toInnerZone() {
    Log("Navigating to Inner Zone\n");
    // Drive forward until Spacetel is reached
    // Rotate to face quadrant
    // L

}
