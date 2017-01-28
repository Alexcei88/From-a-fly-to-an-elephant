cmake_minimum_required (VERSION 2.8)
 
set (PROJECT unittest_flyandanelephant) 

project (${PROJECT})

find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories (${libflyandanelephant_SOURCE_DIR}
		    ${Boost_INCLUDE_DIRS}
                     )
add_definitions (-DBOOST_TEST_MAIN)
add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (${PROJECT} unittest.cpp)

target_link_libraries (${PROJECT}
		       libflyandanelephant
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                       )
                       
add_test (NAME TestFlytToElephant COMMAND ${PROJECT} –log_level=test_suite)