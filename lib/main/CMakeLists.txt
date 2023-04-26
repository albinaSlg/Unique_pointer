add_executable(
	${PROJECT_NAME} 
	source/main.cpp
	source/program.cpp
	include/program.h
)

target_link_libraries(
	${PROJECT_NAME} PUBLIC
	uniquePtr
)

target_include_directories(
	${PROJECT_NAME} PUBLIC
	"include/"
)

add_custom_command(
	TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND doxygen D:/visualStudio/UniquePtr/doxygen.conf.in
)