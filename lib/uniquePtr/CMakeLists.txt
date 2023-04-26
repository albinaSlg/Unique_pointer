add_library(
	uniquePtr
	include/uniquePtr.h
	include/uniquePtr.inl
    source/uniquePtr.cpp)

set_target_properties(uniquePtr PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(
	uniquePtr PROPERTIES 
    VERSION 1
    SOVERSION 0
)

target_include_directories(
	uniquePtr PUBLIC
	"include/"
)