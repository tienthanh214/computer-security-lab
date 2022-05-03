#include "../utils.h"

int main() {
    BIGNUM* n = BN_new();
    BIGNUM* e = BN_new();
    BIGNUM* M = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4120746f702073656372657421");

    // encrtpy E(M) = M^e % n

    BN_CTX* ctx = BN_CTX_new();
    BIGNUM* cipher = BN_new();

    BN_mod_exp(cipher, M, e, n, ctx);
    printBN("Cipher = ", cipher);

    return 0;
}
