# SPACE*NET Protocol & Service Catalog Usage Notes

This document explains how to use the generated protocol/service catalogs and associated headers.

## File layout

- `include/spacenet/services.h` and `include/spacenet/services.hpp`
- `include/spacenet/protocols.h` and `include/spacenet/protocols.hpp`
- `src/catalog/services.c-cpp`
- `src/catalog/protocols.c-cpp`
- `devel-src/documents/index.dat`

## C usage

```c
#include "spacenet/services.h"
#include "spacenet/protocols.h"

const spacenet_service_info_t *svc = spacenet_find_service_by_name("https");
const spacenet_protocol_info_t *proto = spacenet_find_protocol_by_number(6);
```

## C++ usage

```cpp
#include "spacenet/services.hpp"
#include "spacenet/protocols.hpp"

const auto *svc = spacenet::find_service("https");
const auto *proto = spacenet::find_protocol(static_cast<uint8_t>(17));
```

## About `.c-cpp` source suffix

The `.c-cpp` suffix is used to signal mixed C and C++ compatibility source units:

- Build as **C** to export the C ABI functions.
- Build as **C++** to enable the namespace wrappers (`spacenet::*`) around the same dataset.

If your build system does not recognize `.c-cpp`, map it manually:

- C pass: treat `*.c-cpp` as C source.
- C++ pass: treat `*.c-cpp` as C++ source.

## Dataset scope

The catalog includes widely used services and protocol numbers relevant to networking infrastructure. It is not a complete mirror of the entire IANA registry; use `index.dat` links for authoritative updates.

## Updating policy

1. Add/edit catalog entry in both source files.
2. Keep RFC and URL references synchronized in `index.dat`.
3. Prefer IANA and RFC Editor links as primary references.
