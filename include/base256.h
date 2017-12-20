#ifndef _BASE256_H
#define _BASE256_H

#define BASE256_ENCODED_SIZE(x) (x * 4 + 1)
#define BASE256_DECODED_SIZE(x) (x / 4)

#define ERR_NO_DEC_INIT -1 /* dec_init hasn't been called */
#define ERR_BAD_INPUT -2   /* the input for decode was bad encoded*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize decode.
 * It must be called before calling `base256_decode', however one call to the
 * `base256_init_dec' is enough for multiple `base256_decode' uses.
 */
extern void base256_init_dec(void);

/**
 * Decode base256 string.
 *
 * @param out       buffer for decoded data
 * @param out_size  size in bytes of the output buffer, must be at least
 *                  BASE256_DECODED_SIZE(strlen(in))
 * @param in        null-terminated input string, must be utf-8 encoded
 * @return          number of bytes written, or a negative value in case of
 *                  error
 */
extern int base256_decode(unsigned char* out, int out_size,
                          const char* in);

/**
 * Encode data to base256.
 *
 * @param out       buffer for encoded data in utf-8
 * @param out_size  size in bytes of the output buffer, must be at least
 *                  BASE256_ENCODED_SIZE(in_size)
 * @param in        input data
 * @param in_size   size in bytes of the `in' buffer
 * @return          number of bytes written, or a negative value in case of
 *                  error
 */
extern int base256_encode(char* out, int out_size,
                          const unsigned char* in, int in_size);

#ifdef __cplusplus
}
#endif

#endif /* BASE256_H */
