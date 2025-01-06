#include "info.h"

void displayIntroLogo()
{
    NLINE
    printf("\t+-----------------+\n");
    printf("\t|                 |\n");
    printf("\t|   OpenCL Info   |\n");
    printf("\t|                 |\n");
    printf("\t+-----------------+\n");
    NLINE
}

void displayPlatformsInfo()
{
    cl_int errorId;
    cl_uint numberOfPlatforms;
    cl_platform_id *platformIds; 

    errorId = clGetPlatformIDs(0, NULL, &numberOfPlatforms);

    if (errorId != CL_SUCCESS || numberOfPlatforms <= 0)
    {
        ERROR_FPRINTF("Failed to find any OpenCL platform\n");
        exit(EXIT_FAILURE);
    }
    SUCCESS_FPRINTF("OpenCL platform found!\n");
    printf("Number of platforms found: %zu\n", numberOfPlatforms);

    platformIds = (cl_platform_id*)malloc(sizeof(cl_platform_id) * numberOfPlatforms);
    errorId = clGetPlatformIDs(numberOfPlatforms, platformIds, NULL);

    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Failed to find any OpenCL platform or malloc()" 
                      " cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < numberOfPlatforms; ++i)
    {
        NLINE
        displaySpecificPlatformInfo(platformIds[i], CL_PLATFORM_PROFILE, "CL_PLATFORM_PROFILE");
        displaySpecificPlatformInfo(platformIds[i], CL_PLATFORM_VERSION, "CL_PLATFORM_VERSION");
        displaySpecificPlatformInfo(platformIds[i], CL_PLATFORM_VENDOR,  "CL_PLATFORM_VENDOR");
        NLINE
        displayDevicesInfo(platformIds + i);
        NLINE NLINE
    }
    free(platformIds);
}

void displaySpecificPlatformInfo(cl_platform_id id,
                                 cl_platform_info param_name,
                                 char* string)
{
    cl_int errorId;
    size_t paramValueSize;

    errorId = clGetPlatformInfo(id, param_name, 0, NULL, &paramValueSize);

    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Error returned by clGetPlatformInfo\n");
        exit(EXIT_FAILURE);
    }

    char *info = (char*)malloc(sizeof(char) * paramValueSize);
    errorId = clGetPlatformInfo(id, param_name, paramValueSize, info, NULL);

    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Error returned by clGetPlatformInfo\n");
        exit(EXIT_FAILURE);
    }

    printf("\t %s: \t %s \n", string, info);
    free(info);
}

void displayDevicesInfo(cl_platform_id *platformId)
{
    cl_int errorId;
    cl_uint numberOfCPUs, numberOfGPUs, numberOfAccelerators;
    cl_device_id *deviceIdsCPU;
    cl_device_id *deviceIdsGPU;
    cl_device_id *deviceIdsAccelerator;

    errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_CPU, 0, NULL, &numberOfCPUs);

    if (errorId != CL_SUCCESS || numberOfCPUs <= 0)
    {
        ERROR_FPRINTF("No CPU devices found in this platform!\n");
    }
    else
    {
        SUCCESS_FPRINTF("CPU devices found in this platform!\n");
        printf("Number of CPU devices found: %zu\n", numberOfCPUs);

        deviceIdsCPU = (cl_device_id*)malloc(sizeof(cl_device_id) * numberOfCPUs);
        errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_CPU, numberOfCPUs, deviceIdsCPU, NULL);

        if (errorId != CL_SUCCESS)
        {
            ERROR_FPRINTF("Failed to find any CPU devices or malloc()" 
                          " cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < numberOfCPUs; ++i)
        {
            NLINE
            displaySpecificDeviceInfo(deviceIdsCPU[i], CL_DEVICE_PROFILE, "CL_DEVICE_PROFILE");
            displaySpecificDeviceInfo(deviceIdsCPU[i], CL_DEVICE_VERSION, "CL_DEVICE_VERSION");
            displaySpecificDeviceInfo(deviceIdsCPU[i], CL_DEVICE_VENDOR,  "CL_DEVICE_VENDOR");
            displaySpecificDeviceInfo(deviceIdsCPU[i], CL_DEVICE_NAME,    "CL_DEVICE_NAME");
            NLINE
        }
        free(deviceIdsCPU);
    }

    errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_GPU, 0, NULL, &numberOfGPUs); 

    if (errorId != CL_SUCCESS || numberOfGPUs <= 0)
    {
        ERROR_FPRINTF("No GPU devices found in this platform!\n");
    }
    else
    {
        SUCCESS_FPRINTF("GPU devices found in this platform!\n");
        printf("Number of GPU devices found: %zu\n", numberOfGPUs);

        deviceIdsGPU = (cl_device_id*)malloc(sizeof(cl_device_id) * numberOfGPUs);
        errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_GPU, numberOfGPUs, deviceIdsGPU, NULL);

        if (errorId != CL_SUCCESS)
        {
            ERROR_FPRINTF("Failed to find any GPU devices or malloc()" 
                          " cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < numberOfGPUs; ++i)
        {
            NLINE
            displaySpecificDeviceInfo(deviceIdsGPU[i], CL_DEVICE_PROFILE, "CL_DEVICE_PROFILE");
            displaySpecificDeviceInfo(deviceIdsGPU[i], CL_DEVICE_VERSION, "CL_DEVICE_VERSION");
            displaySpecificDeviceInfo(deviceIdsGPU[i], CL_DEVICE_VENDOR,  "CL_DEVICE_VENDOR");
            displaySpecificDeviceInfo(deviceIdsGPU[i], CL_DEVICE_NAME,  "CL_DEVICE_NAME");
            NLINE
        }
        free(deviceIdsGPU);
    }

    errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_ACCELERATOR, 0, NULL, &numberOfAccelerators); 

    if (errorId != CL_SUCCESS || numberOfAccelerators <= 0)
    {
        ERROR_FPRINTF("No Accelerator devices found in this platform!\n");
    }
    else
    {
        SUCCESS_FPRINTF("Accelerator devices found in this platform!\n");
        printf("Number of Accelerator devices found: %zu\n", numberOfAccelerators);

        deviceIdsAccelerator = (cl_device_id*)malloc(sizeof(cl_device_id) * numberOfAccelerators);
        errorId = clGetDeviceIDs(*platformId, CL_DEVICE_TYPE_ACCELERATOR, numberOfAccelerators, 
                                 deviceIdsAccelerator, NULL);

        if (errorId != CL_SUCCESS)
        {
            ERROR_FPRINTF("Failed to find any Accelerator devices or malloc()" 
                          " cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < numberOfGPUs; ++i)
        {
            NLINE
            displaySpecificDeviceInfo(deviceIdsAccelerator[i], CL_DEVICE_PROFILE, "CL_DEVICE_PROFILE");
            displaySpecificDeviceInfo(deviceIdsAccelerator[i], CL_DEVICE_VERSION, "CL_DEVICE_VERSION");
            displaySpecificDeviceInfo(deviceIdsAccelerator[i], CL_DEVICE_VENDOR,  "CL_DEVICE_VENDOR");
            displaySpecificDeviceInfo(deviceIdsAccelerator[i], CL_DEVICE_NAME,  "CL_DEVICE_NAME");
            NLINE
        }
        free(deviceIdsAccelerator);
    }
}

void displaySpecificDeviceInfo(cl_device_id deviceId,
                               cl_device_info param_name,
                               char *string)
{
    cl_int errorId;
    size_t paramValueSize;

    errorId = clGetDeviceInfo(deviceId, param_name, 0, NULL, &paramValueSize);

    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Error returned by clGetDeviceInfo\n");
        exit(EXIT_FAILURE);
    }

    char *info = (char*)malloc(sizeof(char) * paramValueSize);
    errorId = clGetDeviceInfo(deviceId, param_name, paramValueSize, info, NULL);

    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Error returned by clGetDeviceInfo\n");
        exit(EXIT_FAILURE);
    }

    printf("\t %s: \t %s \n", string, info);
    free(info);
}

