#ifndef INIT_H
#define INIT_H

#define CL_TARGET_OPENCL_VERSION 300

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stddef.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

#define ANSI_COLOR_RED   "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ERROR_FPRINTF(ARG) fprintf(stderr, ANSI_COLOR_RED  ARG ANSI_COLOR_RESET)
#define SUCCESS_FPRINTF(ARG) fprintf(stdout, ANSI_COLOR_GREEN ARG ANSI_COLOR_RESET)

#define COMPILE_LOG_BUFFER 20000
#define MEMOBJECTSBUFFER 3
#define ARRAYBUFFER 100000000

cl_context createContext();
cl_command_queue createQueue(cl_context context, cl_device_id *device);
cl_program createProgram(cl_context context, cl_device_id device, const char* fileName);
void createMemoryObjects(cl_context context, cl_mem memObjects[MEMOBJECTSBUFFER],
                         float *vectorA, float *vectorB);

void checkContext(cl_context context);
void checkQueue(cl_command_queue commandQueue);
void checkProgram(cl_program program);
void checkKernel(cl_kernel kernel);
void checkMemObjects(cl_mem element1, cl_mem element2, cl_mem element3);
void checkKernelArg(cl_int errorId);
void checkKernelQueue(cl_int errorId);
void checkReadBuffer(cl_int errorId);

size_t fileSize(FILE *fptr);

#endif