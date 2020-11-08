# Compress data structures for cpp

[![CircleCI](https://circleci.com/gh/o-mdr/compress-data-struct-cpp.svg?style=svg&circle-token=15153e079b8e597f4d30dfcd35766b16ce07f0b3)](https://app.circleci.com/pipelines/github/o-mdr/compress-data-struct-cpp)
[![License](https://img.shields.io/badge/license-GPL-green.svg)](https://github.com/o-mdr/compress-data-struct-cpp/blob/main/COPYING) 
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/o-mdr/compress-data-struct-cpp/blob/main/LICENSE) 

Use compression with data structures, minimal example:
```
#include "cdsc.h"
#include <cstdint>  // uint8_t

int main(int argc, char **argv) {

    int key = 123;
    std::string value = "this is a long really long string";
    compressable::compressable_map<int> cm;    

    compressable::insert(cm, key, value.c_str(), value.size());

    auto raw = compressable::at<int, std::string>(cm, key);
    std::string actual(raw.begin(), raw.end());

    return 0;
}
```

## Prerequisites
```
cd compress-data-struct-cpp
sudo sh script/bootstap
```

## Building
```
meson compile -C builddir
 ```

## Contributing
Any contributions are welcome, please submit a PR. All contributions are made and accepted under this project's license. 

## License
This project is dual licenced under [MIT](LICENSE) or [GNU GPLv2](COPYING).
You may choose either license at your own will.
