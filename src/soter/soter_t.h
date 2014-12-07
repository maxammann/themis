/**
 * @file
 *
 * (c) CossackLabs
 */

#ifndef SOTER_T_H
#define SOTER_T_H

/* TODO: #ifdef type definition includes when we support different crypto engines */
#include <soter/openssl/soter_openssl.h>

soter_status_t soter_hash_init(soter_hash_ctx_t *hash_ctx, soter_hash_algo_t algo);

soter_status_t soter_asym_cipher_init(soter_asym_cipher_t* asym_cipher, soter_asym_cipher_padding_t pad);
soter_status_t soter_asym_cipher_cleanup(soter_asym_cipher_t* asym_cipher);

soter_status_t soter_asym_ka_init(soter_asym_ka_t* asym_ka_ctx, soter_asym_ka_alg_t alg);
soter_status_t soter_asym_ka_cleanup(soter_asym_ka_t* asym_ka_ctx);

soter_status_t soter_sign_init(soter_sign_ctx_t* ctx, soter_sign_alg_t algId, const void* private_key, const size_t private_key_length, const void* public_key, const size_t public_key_length);
soter_status_t soter_verify_init(soter_sign_ctx_t* ctx, soter_sign_alg_t algId, const void* private_key, const size_t private_key_length, const void* public_key, const size_t public_key_length);

/* Largest possible block size for supported hash functions (SHA-512) */
#define HASH_MAX_BLOCK_SIZE 128

struct soter_hmac_ctx_type
{
	uint8_t o_key_pad[HASH_MAX_BLOCK_SIZE];
	size_t block_size;
	soter_hash_algo_t algo;
	soter_hash_ctx_t hash_ctx;
};

soter_status_t soter_hmac_init(soter_hmac_ctx_t *hmac_ctx, soter_hash_algo_t algo, const uint8_t* key, size_t key_length);
soter_status_t soter_hmac_cleanup(soter_hmac_ctx_t *hmac_ctx);

#endif /* SOTER_T_H */
