#pragma once

#include "Breach.h"
#include "Help.h"
#include "Spark.h"

// this entire file would be slit into multiple files and gathered with #includes
// in a larger project. These also could be static functions on each class.

namespace Breach {
    void upgrade_ability(Ability* ability);
}

namespace Spark {
    void upgrade_ability(Ability* ability);
}

namespace Help {
    void upgrade_ability(Ability* ability);
}