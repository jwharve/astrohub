#include "distribution.h"
#include "log.h"

Distribution& Distribution::getInstance() {
    static Distribution instance;
    return instance;
}
