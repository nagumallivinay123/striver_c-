#include <bitset>
#include <iostream>
#include <string>

int main()
{
    std::bitset<1000> s; // All bits are initialized to 0

    // Setting bits
    s.set(10); // Set the bit at position 10 to 1
    s.set();   // Set all bits to 1

    // Resetting bits
    s.reset(10); // Set the bit at position 10 to 0
    s.reset();   // Set all bits to 0

    // Flipping bits
    s.flip(10); // Flip the bit at position 10
    s.flip();   // Flip all bits

    // Accessing bits
    bool bit10 = s.test(10); // Get the bit at position 10
    bool bit20 = s[20];      // Get the bit at position 20
    s[30] = 1;               // Set the bit at position 30 to 1

    // Counting bits
    size_t numBitsSet = s.count(); // Get the number of bits set to 1
    size_t totalBits = s.size();   // Get the total number of bits (1000)

    // Bitwise operations
    std::bitset<1000> t;
    s &= t;  // Bitwise AND with another bitset
    s |= t;  // Bitwise OR with another bitset
    s ^= t;  // Bitwise XOR with another bitset
    s <<= 5; // Left shift by 5 positions
    s >>= 5; // Right shift by 5 positions

    // String conversion
    std::string str = s.to_string(); // Convert bitset to string
    unsigned long ul = s.to_ulong(); // Convert bitset to unsigned long

    // Output
    std::cout << s << std::endl; // Print bitset to output stream

    return 0;
}
