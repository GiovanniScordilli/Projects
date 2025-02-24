#ifndef SETUP_H
#define SETUP_H

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

#define CL_TARGET_OPENCL_VERSION 300

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else 
#include <CL/opencl.h>
#endif

#include "console.h"

class Setup
{
private:
    cl_platform_id platformId       {};
    cl_context context              {};
    cl_device_type devType          {};
    cl_device_id device             {};   
    cl_command_queue commandQueue   {};
    cl_program program              {};
    cl_kernel kernel                {};
    cl_mem memoryObject             {};

    void                printWelcomeBanner      ();
    void                readErrorCode           (cl_int errorCode);
    [[noreturn]] void   throwError              (std::string stringErrorCode);
    void                ignoreInput             ();
    void                checkNumbersOfPlatform  (cl_uint nPlatforms);
    void                displayPlatformInfo     (cl_platform_id platform, 
                                                 cl_platform_info parameter,
                                                 std::string infoMessage);
    cl_platform_id      checkPlatformChoice     (int choice, 
                                                 cl_uint maxPlatforms, 
                                                 cl_platform_id *platforms);
    cl_platform_id      selectPlatform          ();
    void                checkTypeChoice         (int &choice);
    cl_device_type      selectContextType       ();
    std::string         typeToString            (cl_device_type devType);
    cl_context          createContext           ();
    void                checkAviableDevices     (size_t devicesBufferSize);
    void                listDevices             ();
    void                displaySpecificInfo     (cl_device_id deviceId,
                                                 cl_device_info paramName,
                                                 std::string paramNameString);
    void                checkDeviceChoice       (int &choice, 
                                                    size_t aviableDevices);
    cl_device_id        selectDevice            ();
    cl_command_queue    createCommandQueue      ();
    cl_program          createProgram           ();
    cl_kernel           createKernel            ();
    cl_mem              createMemoryObject      ();

public:
    Setup();

};

#endif

