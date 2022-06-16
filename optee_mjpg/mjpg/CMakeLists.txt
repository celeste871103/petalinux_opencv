project (optee_mjpg C)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set( THREADS_PTHREAD_ARG 
     "0"
     CACHE STRING "Result from TRY_RUN" FORCE)

find_package(Threads REQUIRED)
set (SRC host/main.c)
FILE(GLOB AA host/utils.c)
FILE(GLOB UVC host/input_uvc/*.c)
#FILE(GLOB HTTP host/output_http/*.c)
FILE(GLOB OFILE host/output_file/*.c)
add_executable (${PROJECT_NAME} ${SRC} ${AA} ${UVC} ${OFILE})

target_include_directories(${PROJECT_NAME}
			   PRIVATE ta/include
			   #PRIVATE host/input_file
			   PRIVATE host/input_uvc
			   #PRIVATE host/output_http
 			   PRIVATE host/output_file
			   PRIVATE include)

target_link_libraries (${PROJECT_NAME} PRIVATE teec -lm Threads::Threads)
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
