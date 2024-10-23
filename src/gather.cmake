#Function used to search through directories
#Goes through its *.cpp files and include folder
#Adds these to the target
function(gather_sources_headers dir target)
    if (NOT EXISTS "${dir}")
        message(FATAL_ERROR "Source directory does not exist: ${dir}")
    endif ()
    file(GLOB_RECURSE sources "${dir}/*.cpp")
    if (TARGET ${target})
        target_sources(${target} PRIVATE ${sources})
        target_include_directories(${target} PUBLIC "${dir}/include")

#        message(STATUS "Added sources for target ${target}: ${sources}")
    endif ()
endfunction()