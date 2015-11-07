# Found here : https://www.cmake.org/Wiki/CMakeMacroGenerateProject on 28/11/2014
# Generate source groups that mimic the directory structure of ProjectDir.
# ProjectDir The directory that we want to mimic. Usually, it will be ${CMAKE_CURRENT_SOURCE_DIR}/../src
# ProjectSources The list of sources files. Usually, you will get it with file(GLOB_RECURSE source_files ../src/*.cpp ../src/*.hpp).
# Example :
# CreateSourceGroups(${CMAKE_CURRENT_SOURCE_DIR}/../src "${source_files}")
#
# Lowik CHANUSSOT (lowik.chanussot at priceminister dot com)

MACRO ( CreateSourceGroups ProjectDir ProjectSources )
    # Copy the input list of files, modification will be done on the copied version.
    # For each file path (project/dir/a/b/file) :
    # . remove the ProjectDir -> /a/b/file
    # . remove the file name -> /a/b
    # . remove the first "/" or "\" -> a/b
    # . replace "/" y "\\" -> a\\b : this is the source group
    SET ( DirSources "${ProjectSources}" )
    FOREACH ( Source ${DirSources} )
        STRING ( REGEX REPLACE "${ProjectDir}" "" RelativePath "${Source}" )
        STRING ( REGEX REPLACE "[\\\\/][^\\\\/]*$" "" RelativePath "${RelativePath}" )
        STRING ( REGEX REPLACE "^[\\\\/]" "" RelativePath "${RelativePath}" )
        STRING ( REGEX REPLACE "/" "\\\\\\\\" RelativePath "${RelativePath}" )
        SOURCE_GROUP ( "${RelativePath}" FILES ${Source} )
    ENDFOREACH ( Source )
ENDMACRO ( CreateSourceGroups)
 