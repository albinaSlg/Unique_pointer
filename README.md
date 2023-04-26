# Unique pointer
---
What is unique pointer?
Unique pointer is subspecies of smart pointer.
In it's turn, smart pointer is a class that manages dynamically dedicated memory / resource / object. It help avoid memory leaks and correctly delete managed object after exiting the scope.

---

## Example 

```
#include "uniquePtr.h"

int main()
{
    UniquePtr pointer(new int(2));
    return 0;
}
```
It also supports arrays:

```
#include "uniquePtr.h"

int main()
{
    UniquePtr pointer(new int[5](1,2,3,4,5));
    return 0;
}
```

## How to use

If you want to work with cmake just add subdirectories to your main CMakeLists.txt file:

```
add_subdirectory(dependencies/googletest)
add_subdirectory(lib/uniquePtr)
add_subdirectory(lib/main)
add_subdirectory(UnitTest)
```

Also you need to link uniquePtr library to CMakeLists.txt for your executables:

```
target_link_libraries(
	${PROJECT_NAME} PUBLIC
	uniquePtr
)
```

Now you can add Unique pointer to your project using #include

```
#include "uniquePtr.h"
```

## Documentation

To generate documentation install and run doxygen from main directory using config file:

```
doxygen doxygen.conf.in
```

If you want to generate documentation automatically after building project add this command to CMakeLists.txt for your executables:
```
add_custom_command(
	TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND doxygen D:/visualStudio/UniquePtr/doxygen.conf.in
)
```