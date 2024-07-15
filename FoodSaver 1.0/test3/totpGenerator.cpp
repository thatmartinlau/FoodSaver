// 
// Produces a Time Based One-Time Password (TOTP) given a secret seed
// string, as defined by RFC 6238 (https://tools.ietf.org/html/rfc6238)
//

#include <iostream>
#include <iomanip>
#include <string>
#include <oath.h>
#include <openssl/sha.h>

std::string stringToHex(const std::string& s) {
    // Convert the given string to a hexadecimal version of itself
    std::stringstream hexStream;
    for (char c : s) {
        hexStream << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
    }
    return hexStream.str();
}

uint32_t createTOTP(const std::string& seed, const EVP_MD* hashFunction = EVP_sha512) {
    // Create a new TOTP for the given secret seed and hash, using the default 30 second time step period
    std::string hexSeed = stringToHex(seed);

    std::string totpValue = oath_totp_generate(hexSeed.c_str(), hexSeed.length(), nullptr, nullptr, OATH_TOTP_DEFAULT_TIME_STEP, 8, hashFunction);
    return std::stoul(totpValue);
}
