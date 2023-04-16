#pragma once

#include <cinttypes>

namespace ura::messaging::priority
{
    inline const uint8_t URGENT = 0;
    inline const uint8_t HIGHEST = 1;
    inline const uint8_t MEDIUM = 128;
    inline const uint8_t LOWEST = 255;
}   /* namespace ura::messaging::priority */
