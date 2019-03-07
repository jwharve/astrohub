#include "celebration.h"
#include "log.h"

Celebration& Celebration::getInstance() {
    static Celebration instance;
    return instance;
}
