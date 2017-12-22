# libb256
[![Travis](https://img.shields.io/travis/Equim-chan/libb256.svg)](https://travis-ci.org/Equim-chan/libb256)

C implementation of base256.

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

## Documents
Please refer to [libb256(3)](https://github.com/Equim-chan/libb256/blob/master/doc/libb256.3.adoc).

## License
[BSD-3-clause](https://github.com/Equim-chan/libb256/blob/master/LICENSE)
