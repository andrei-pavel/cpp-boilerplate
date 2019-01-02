# Simple C++ boilerplate

Reads all the entries in the provided config.yaml and outputs them.

yaml-cpp is a dependency and needs to be installed prior to building.

## Usage

```
meson ./build
ninja -C ./build
./build/cpp-boilerplate -c|--config ${CONFIG_FILE}
```

```
Usage:
  cpp-boilerplate [OPTION...]

  -h, --help        show usage
  -c, --config arg  specify YAML configuration file
```

Sample config.yaml provided in root directory

To format source files, run:
```
./clang-format [${FILE}...]
```

## Support the maintainer

<noscript><a href="https://liberapay.com/andrei/donate"><img alt="Donate using Liberapay" src="https://liberapay.com/assets/widgets/donate.svg"></a></noscript>
