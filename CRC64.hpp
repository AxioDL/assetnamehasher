#pragma once
#include <cstdint>

class CRC64 {
    static const uint64_t crc64Table[256];
    static inline uint64_t permute(uint64_t checksum, uint8_t b)
    { return (checksum >> 8) ^ crc64Table[(checksum & 0xFF) ^ b]; }
public:
    static uint64_t Calculate(const void* data, uint32_t length);
};

