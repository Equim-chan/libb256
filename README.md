# libb256
[![Travis](https://img.shields.io/travis/Equim-chan/libb256.svg)](https://travis-ci.org/Equim-chan/libb256)

C implementation of [base256](https://github.com/Equim-chan/base256).

## Install
```shell
$ git clone https://github.com/Equim-chan/libb256.git
$ cd libb256/build
$ cmake ..
$ make
$ [sudo] make install
```

This will by defaults build a static linked library, if you want a shared one,
specify `-DWITH_SHARED=1` in cmake.

## Example
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <base256.h>

int main(void)
{
    // Encode a string
    char* plain = "Hello, 世界";
    int plain_size = strlen(plain);
    int encoded_size = BASE256_ENCODED_SIZE(plain_size);
    char* encoded = (char*)malloc(encoded_size);

    int n = base256_encode(encoded, encoded_size, (unsigned char*)plain, plain_size);
    if (n < 0) {
        return n;
    }

    puts(encoded); //=> 👾🍧🙆🍬🙇🌱😌🚟💦🏥🐴🏤👈

    // And decode it back
    int decoded_size = BASE256_DECODED_SIZE(encoded_size);
    char* decoded = (char*)malloc(decoded_size);

    base256_init_dec();
    n = base256_decode((unsigned char*)decoded, encoded_size, encoded);
    if (n < 0) {
        return n;
    }

    puts(decoded); //=> Hello, 世界
}
```

## Documents
Please refer to [libb256(3)](https://github.com/Equim-chan/libb256/blob/master/doc/libb256.3.adoc).

## License
[BSD-3-clause](https://github.com/Equim-chan/libb256/blob/master/LICENSE)
