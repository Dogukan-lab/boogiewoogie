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
        #Check if the directory has an include folder, otherwise just gather whatever it can find.
        if (EXISTS "${dir}/include")
            target_include_directories(${target} PUBLIC "${dir}/include")
            message(STATUS "Added Include dir ${dir}/include for target ${target}")
        else ()
            target_include_directories(${target} PUBLIC "${dir}")
            message(STATUS "Added current dir ${dir} for target ${target}, no include dir found")
        endif ()
    else ()
        message(WARNING "No target found for ${target}!")
    endif ()
endfunction()