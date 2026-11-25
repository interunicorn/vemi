add_executable(vemi_tests
    test_vector.c
)

target_link_libraries(vemi_tests PRIVATE vemi)
