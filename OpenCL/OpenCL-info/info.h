#ifndef INFO_H
#define INFO_H

#define CL_TARGET_OPENCL_VERSION 300

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

#if defined (__unix__) || defined (__unix) || defined (__APPLE__)
#define ANSI_COLOR_RED   "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ERROR_FPRINTF(ARG) fprintf(stderr, ANSI_COLOR_RED  ARG ANSI_COLOR_RESET)
#define SUCCESS_FPRINTF(ARG) fprintf(stdout, ANSI_COLOR_GREEN ARG ANSI_COLOR_RESET)

#else
#define ERROR_FPRINTF(ARG) fprintf(stderr, ARG)
#define SUCCESS_FPRINTF(ARG) fprintf(stdout, ARG)
#endif

#define NLINE printf("\n");

void displayIntroLogo();
void displayPlatformsInfo();
void displaySpecificPlatformInfo(cl_platform_id id,
                                 cl_platform_info param_name,
                                 char *string);
void displayDevicesInfo(cl_platform_id *platformId);
void displaySpecificDeviceInfo(cl_device_id deviceId,
                               cl_device_info param_name,
                               char *string);

#endif