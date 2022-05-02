#include <stdio.h>
#include <openssl/bn.h>

void printBN(const char *msg, BIGNUM *a) {
	char *number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}