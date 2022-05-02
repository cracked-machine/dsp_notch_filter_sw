target_sources(${BUILD_NAME} PRIVATE
    src/mainapp.cpp
    src/I2SManager.cpp
    src/I2SCallbacks.cpp
)

target_include_directories(${BUILD_NAME} PRIVATE 
    inc
)