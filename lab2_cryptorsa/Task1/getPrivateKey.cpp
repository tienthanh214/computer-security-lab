#include "../utils.h"

using namespace std;

BIGNUM* getPrivateKey(BIGNUM* p, BIGNUM* q, BIGNUM* e) {
    /*
        ed % phi = 1 
        phi =  (p-1)(q-1)
        -> d = e^-1 (mod phi)
    */
    BN_CTX *ctx = BN_CTX_new();

    BIGNUM* pMinus1 = BN_new();
    BIGNUM* qMinus1 = BN_new();
    BIGNUM* phi = BN_new();
    BIGNUM* one = BN_new();

    BN_dec2bn(&one, "1");
    BN_sub(qMinus1, q, one);
    BN_sub(pMinus1, p, one);
    BN_mul(phi, qMinus1, pMinus1, ctx);

    BIGNUM* result = BN_new();
    BN_mod_inverse(result, e, phi, ctx);
    
    return result;
}

int main() {
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();

    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    printBN("Private key = ", getPrivateKey(p, q, e));
    // Private key =  3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB
    return 0;
}