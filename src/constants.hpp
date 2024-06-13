#pragma once

namespace MAP {
    constexpr int HEIGHT = 50;
    constexpr int WIDTH  = 80;
}

namespace SYMBOL {
    constexpr char WATER    = '.';
    constexpr char LAND     = '+';
    constexpr char TREE     = '*';
    constexpr char BUILDING = '@';
    constexpr char MOUNTAIN = '^';
}

namespace ID {
    constexpr int FIRST_CLUSTER =  0;
    constexpr int WATER         = -1;
    constexpr int UNASSIGNED    = -2;
    constexpr int QUEUED        = -3;
}
