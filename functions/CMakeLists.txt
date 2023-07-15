add_library(functions functions.cpp)
# create an option
option(OPTION1 "Customized option 1." ON)
if (OPTION1)
	# When OPTION1 is ON, the compile definition OPTION1_ENABLED will be set.
	target_compile_definitions(functions PRIVATE "OPTION1_ENABLED")
endif()

target_include_directories(functions INTERFACE ".")

# after configuring is done we need to provide custom install operations for CMake
install(TARGETS functions DESTINATION "lib")
install(FILES "functions.h" DESTINATION "include")
