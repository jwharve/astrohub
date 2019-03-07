#include "collection.h"
#include "log.h"

Collection& Collection::getInstance() {
    static Collection instance;
    return instance;
}
