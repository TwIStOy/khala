Khala project
=============
[![pipeline status](https://gitlab.com/khala-team/khala/badges/master/pipeline.svg)](https://gitlab.com/khala-team/khala/commits/master)

All in one library based on `libuv`. Inspired by `media_server_library`.

Usage
-------
```cpp
#include <thread>
#include <khala/base/event_loop.hh>

using namespace khala::base;

int main() {
  EventLoop loop;
  loop.Run();
}
```

------
Use third-party library:

- [JSON for Modern C++](https://github.com/nlohmann/json)