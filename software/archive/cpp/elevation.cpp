#include "elevation.h"
#include "log.h"

Elevation& Elevation::getInstance() {
    static Elevation instance;
    return instance;
}
