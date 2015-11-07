 if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
 endif()

#set(CMAKE_SUPPRESS_REGENERATION 1 CACHE INTERNAL "suppress zero-check")
if (WIN32)
	SET(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_DEPRECATE")
	if (ARCH_TYPE STREQUAL "x64")
		SET(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} /Gd /DWIN64")
	else()
		SET(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} /Gd /DWIN32")
	endif()
	SET(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} /Zi /Od /D_ITERATOR_DEBUG_LEVEL=2 /D_DEBUG /MDd " )
	SET(CMAKE_CXX_FLAGS_RELEASE	"${CMAKE_CXX_FLAGS_RELEASE} /Oi /O2 /Gs /MD ")
	SET(CMAKE_C_FLAGS			${CMAKE_CXX_FLAGS})
	SET(CMAKE_C_FLAGS_DEBUG  	${CMAKE_CXX_FLAGS_DEBUG})
	SET(CMAKE_C_FLAGS_RELEASE	${CMAKE_CXX_FLAGS_RELEASE})
	SET(LINK_FLAGS		"${LINK_FLAGS} /ERRORREPORT:QUEUE /NXCOMPAT")
else (WIN32)
	#message(FATAL_ERROR "compilation only configured for windows platforms")
endif (WIN32)