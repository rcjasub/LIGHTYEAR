add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SRC/framework/application.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SRC/EntryPoint.cpp
)

# Include directories
target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link SFML libraries in a single call
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC 
    sfml-graphics sfml-window sfml-system sfml-audio
)

# Function to copy SFML libraries (for example, DLLs in Windows)
function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

# Copy the SFML libraries to the engine target
CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})



