#include "../utils.h"

int main() {
    BIGNUM* n = BN_new();
    BIGNUM* e = BN_new();
    BIGNUM* M = BN_new();
    BIGNUM* S1 = BN_new();
    BIGNUM* S2 = BN_new();

    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4c61756e63682061206d697373696c652e");
    BN_hex2bn(&S1, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
    BN_hex2bn(&S2, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");

    BN_CTX* ctx = BN_CTX_new();
    BIGNUM* plain1 = BN_new();
    BIGNUM* plain2 = BN_new();
    // verify using public key
    BN_mod_exp(plain1, S1, e, n, ctx);
    bool v1 = (BN_cmp(plain1, M) == 0);
    BN_mod_exp(plain2, S2, e, n, ctx);
    bool v2 = (BN_cmp(plain2, M) == 0);
    
    printBN("Plain1 = ", plain1);
    printf("Plain1 is M: %s\n", v1 ? "True" : "False");
    printBN("Plain2 = ", plain2);
    printf("Plain2 is M: %s\n", v2 ? "True" : "False"); 
    return 0;
}
