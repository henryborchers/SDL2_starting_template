set(sdlstuff_source sdlstuff.c sdlstuff.h)
add_library(sdlstuff ${sdlstuff_source})

if(SDL2_FOUND)
    target_include_directories(sdlstuff PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries(sdlstuff ${SDL2_LIBRARIES})
    else()
    message(WARNING "CAN'T FIND SDL2")
endif()