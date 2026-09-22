cmake_minimum_required(VERSION 3.16)

project(libLRC)

# libLRC

set(CMAKE_CXX_STANDARD 20)

add_library(LRC SHARED 
    src/Lyrics.cpp 
    src/Parser.cpp
    src/Song.cpp
)
target_include_directories(LRC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(APPLE)
    add_library(LRCObjC SHARED
        src/Lyrics.cpp
        src/Parser.cpp
        src/Song.cpp
        src/objc/LRCSong.mm
        src/objc/LRCParser.mm
        src/objc/LRCDiagnostics.mm
    )

    target_link_libraries(LRCObjC PRIVATE "-framework Foundation")
    set_source_files_properties(
        src/objc/LRCSong.mm src/objc/LRCParser.mm src/objc/LRCDiagnostics.mm
        PROPERTIES COMPILE_FLAGS "-fobjc-arc"
    )

    set_target_properties(LRCObjC PROPERTIES
        FRAMEWORK TRUE
        FRAMEWORK_VERSION A
        MACOSX_FRAMEWORK_IDENTIFIER com.yourorg.LRCObjC
        PUBLIC_HEADER "src/objc/LRCSong.h;src/objc/LRCParser.h;src/objc/LRCDiagnostics.h;src/objc/LRCObjC.h"
        XCODE_ATTRIBUTE_DEFINES_MODULE YES
        INSTALL_NAME_DIR "@rpath"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
    target_include_directories(LRCObjC PUBLIC include)
endif()

#end

# LRC_test

add_executable(lrc-test examples/Main.cpp)
target_include_directories(lrc-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(lrc-test LRC)

#end
