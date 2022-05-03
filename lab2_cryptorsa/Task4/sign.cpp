#include "../utils.h"

int main() {
    BIGNUM* n = BN_new();
    BIGNUM* e = BN_new();
    BIGNUM* d = BN_new();
    BIGNUM* M1 = BN_new();
    BIGNUM* M2 = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    
    BN_hex2bn(&M1, "49206f776520796f75202432303030");
    BN_hex2bn(&M2, "49206f776520796f75202433303030");

    BN_CTX* ctx = BN_CTX_new();
    BIGNUM* cipher1 = BN_new();
    BIGNUM* cipher2 = BN_new();
    // sign using private key
    BN_mod_exp(cipher1, M1, d, n, ctx);
    BN_mod_exp(cipher2, M2, d, n, ctx);

    
    printBN("Cipher1 = ", cipher1);
    printBN("Cipher2 = ", cipher2);


    return 0;
}
