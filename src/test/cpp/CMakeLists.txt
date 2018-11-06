
add_library(cfs.algo.test
    cfs/algo/Test
)

#apply_style_targets(cfs.algo.test ${CMAKE_CURRENT_SOURCE_DIR})
apply_style_targets_command(cfs.algo.test ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(cfs.algo.test 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cfs/algo>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cfs/algo>
)

target_link_libraries(cfs.algo.test
    PUBLIC  
        cfs.algo.main
        GMock::GMock
        GTest::GTest
)

add_executable (cfs.algo.test.bin
    cfs/algo/unitTest
    cfs/algo/arithmetic/MatrixTest
    cfs/algo/utils/FlicksTest   

    cfs/algo/filters/kalman/models/QuadraticSystemModel 
    cfs/algo/filters/kalman/models/QuadraticMeasurementModel

    cfs/algo/filters/kalman/base/UnscentedKalmanFilterBaseTest
    cfs/algo/filters/kalman/ukf/UnscentedKalmanFilterTest
    cfs/algo/filters/kalman/ukf/SquareRootUnscentedKalmanFilterTest

    cfs/algo/filters/kalman/ekf/ExtendedKalmanFilterTest
)

target_link_libraries(cfs.algo.test.bin
    PUBLIC cfs.algo.test
)

gtest_discover_tests(cfs.algo.test.bin
    TEST_PREFIX "CFS-ALGO:-: "
    TEST_SUFFIX ----
    PROPERTIES LABELS CFS_ALGO TEST
    DISCOVERY_TIMEOUT 10
    EXTRA_ARGS --iterration 1 --outputpath ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} --module cfs.algo.test
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_dependencies( test-compile cfs.algo.test.bin)

