# EUtilities 🖱️⌨️

**EUtilities** (Émile Utilities) is a lightweight C++ library designed for Windows keyboard and mouse utilities. Whether you need to simulate key presses or detect key events, this library is built to make it easy to integrate these functionalities into your C++ projects.

---

## ✨ Features

- **🔑 Key Press Simulation**: Simulate key presses programmatically.
- **🕵️ Key Press Detection**: Detect and respond to key press events.
- **⚙️ Easy Integration**: Built to be simple to import and use in any C++ project.

---

## 🚀 Getting Started

### Prerequisites

- **C++23 or later**: EUtilities leverages modern C++ features for a clean and efficient implementation.
- **Windows OS**: The library is currently tailored for Windows-based systems.

## Installation

For CMake projects, you can do something like this
```CMake
include(FetchContent)
FetchContent_Declare(
    EUtilities
    URL https://github.com/Force-quit/EUtilities/archive/refs/tags/v1.1.zip # check for newer versions if possible
)
FetchContent_MakeAvailable(EUtilities)
target_link_libraries(YourProjectName PRIVATE EUtilities)
```
And that's it! You should be able to `#include "EUtilities.hpp"` and your project should link with the .lib of EUtilities automatically.

## 🛠️ Development Details
EUtilities was originally developed as a Visual Studio MSVC project but has since been migrated to a CMake-based structure to ensure broader compatibility and easier integration with other projects.

## 📝 Usage Examples
See the tests folder for some examples.
