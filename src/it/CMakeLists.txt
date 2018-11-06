

set(FEATURE_TEST_FORMAT --format progress)  #--format pretty OR --format pretty --tags @wip OR ...
set(FEATURE_TEST_OPTION --backtrace --format html --color)

add_executable(cfs.algo.it-test.steps
    cfs/algo/features/step_definitions/ApplicationSteps
    cfs/algo/features/step_definitions/kalman/SystemModel
    cfs/algo/features/step_definitions/kalman/Control
    cfs/algo/features/step_definitions/kalman/KalmanSteps
    cfs/algo/features/step_definitions/kalman/OrientationMeasurement
    cfs/algo/features/step_definitions/kalman/OrientationMeasurementModel
    cfs/algo/features/step_definitions/kalman/PositionMeasurement
    cfs/algo/features/step_definitions/kalman/PositionMeasurementModel
    cfs/algo/features/step_definitions/kalman/State
    cfs/algo/features/step_definitions/kalman/KalmanSteps

)

apply_style_targets_command(cfs.algo.it-test.steps ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cfs.algo.it-test.steps
    PUBLIC  
        cfs.algo.main
        cfs.algo.test
        CUCUMBER-CPP::CUCUMBER-CPP
#        PUBLIC BENCHMARK::BENCHMARK
)

add_custom_target(cfs.algo.integration-test

    COMMAND
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/qa/test-result        
    COMMAND
        cfs.algo.it-test.steps --port 3902  >/dev/null &

    COMMAND 
        cucumber ${FEATURE_TEST_FORMAT} ${FEATURE_TEST_OPTION} 
            --out ${CMAKE_INSTALL_PREFIX}/qa/test-result/cfs.algo.test-report.html 
            --strict ${CMAKE_CURRENT_SOURCE_DIR}/cfs/algo/features

    WORKING_DIRECTORY 
        ${CMAKE_CURRENT_SOURCE_DIR}

    COMMENT 
        "Run cfs algo integration test."
)

#add_custom_command(TARGET cfs.algo.integration-test
#    PRE_BUILD
#    COMMAND
#        cfs.algo.it-test.steps --port 3902  >/dev/null &
#    WORKING_DIRECTORY
#        ${CMAKE_CURRENT_SOURCE_DIR}
#    WORKING_DIRECTORY
#        ${CMAKE_CURRENT_SOURCE_DIR}
#    COMMENT
#        "Start cucumber's wire server on port 3902."
#)

add_custom_command(TARGET cfs.algo.integration-test 
    POST_BUILD
    COMMAND 
        fuser -k -n  tcp 3902 || true # kill -9 *.Seps which is using port 3902
#        # iptables -I INPUT -p tcp --dport 3902 -j DROP ;# need to be root for this command
    COMMENT
        // check pro opened lsof -i -P -n | grep LISTEN 
        "Killing process to close cucumber wire port. (bind: Address already in use)"
)

add_dependencies( feature-test cfs.algo.integration-test)

