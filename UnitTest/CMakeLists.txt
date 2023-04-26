add_executable(
	unitTest
	source/test.cpp
	source/uniquePtrTest.cpp
    source/uniquePtrTestArray.cpp)

target_link_libraries(
	unitTest PUBLIC
	gtestLib
	uniquePtr
)