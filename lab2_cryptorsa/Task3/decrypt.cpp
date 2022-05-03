#include "../utils.h"

int main() {
    BIGNUM* n = BN_new();
    BIGNUM* d = BN_new();
    BIGNUM* C = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");

    // encrtpy E(M) = M^e % n

    BN_CTX* ctx = BN_CTX_new();
    BIGNUM* cipher = BN_new();

    BN_mod_exp(cipher, C, d, n, ctx);
    printBN("hex = ", cipher);

    return 0;
}
