#include "init.h"

cl_context createContext()
{
    cl_int errorId;
    cl_uint numberOfPlatforms;
    cl_platform_id firstPlatformId;
    cl_context context = NULL;

    errorId = clGetPlatformIDs(1, &firstPlatformId, &numberOfPlatforms);
    if (errorId != CL_SUCCESS | numberOfPlatforms <= 0)
    {
        ERROR_FPRINTF("Failed to find any OpenCL Platforms.\n");
        return NULL;
    }

    cl_context_properties contextProperties[] = 
    {
        CL_CONTEXT_PLATFORM,
        (cl_context_properties)firstPlatformId,
        0
    };

    printf("Trying to create CPU context...\n");

    context = clCreateContextFromType(contextProperties, CL_DEVICE_TYPE_CPU, NULL, NULL, &errorId);
    if (errorId != CL_SUCCESS)
    {
        printf("Failed to create CPU context\n");
        printf("Trying to create GPU context...\n");

        context = clCreateContextFromType(contextProperties, CL_DEVICE_TYPE_GPU, NULL, NULL, &errorId);
        if (errorId != CL_SUCCESS)
        {
            ERROR_FPRINTF("Failed to create CPU or GPU context\n");
            return NULL;
        }
    }
 
    return context;
}

cl_command_queue createQueue(cl_context context, cl_device_id *device)
{
    cl_int errorId;
    cl_device_id *aviableDevices;
    cl_command_queue commandQueue = NULL;
    size_t deviceBufferSize = -1;

    errorId = clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL, &deviceBufferSize);
    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Failed call to clGetContextInfo(...)\n");
        return NULL;
    }

    if (deviceBufferSize <= 0)
    {
        ERROR_FPRINTF("No devices available\n");
        return NULL;
    }

    aviableDevices = malloc(deviceBufferSize / sizeof(cl_device_id));
    errorId = clGetContextInfo(context, CL_CONTEXT_DEVICES, deviceBufferSize, aviableDevices, NULL);
    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("Failed to get devices IDs\n" );
        return NULL;
    }

    commandQueue = clCreateCommandQueue(context, aviableDevices[0], 0, NULL);
    if (commandQueue == NULL)
    {
        ERROR_FPRINTF("Failed to create OpenCL commandQueue for device 0\n");
        return NULL;
    }

    *device = aviableDevices[0];
    free(aviableDevices);
    return commandQueue;
}

cl_program createProgram(cl_context context, cl_device_id device, const char* fileName)
{
    cl_int errorId;
    cl_program program;
    FILE *kernelFile;

    kernelFile = fopen(fileName, "rb");
    if (kernelFile == NULL)
    {
        ERROR_FPRINTF("Cannot open kernel file\nexiting...\n");
        exit(EXIT_FAILURE);    
    }

    size_t fSize = fileSize(kernelFile);
    char* kernelToString = malloc(fSize * sizeof(char) + sizeof(char));
    kernelToString[fSize]= '\0';
    fread(kernelToString, 1, fSize, kernelFile);
    fclose(kernelFile);

    program = clCreateProgramWithSource(context, 1, (const char**)&kernelToString, NULL, NULL);
    if (program == NULL)
    {
        ERROR_FPRINTF("Failed to create OpenCL program from source\n");
        return NULL;
    }
    free(kernelToString);

    errorId = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (errorId != CL_SUCCESS)
    {
        char buildLog[COMPILE_LOG_BUFFER];
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, sizeof(buildLog), buildLog, NULL);
        ERROR_FPRINTF("Error compiling kernel!\t");
        printf(buildLog);

        clReleaseProgram(program);
        return NULL;
    }

    return program;
}

void createMemoryObjects(cl_context context, cl_mem memObjects[MEMOBJECTSBUFFER],
                         float *vectorA, float *vectorB)
{
    memObjects[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | 
                                   CL_MEM_COPY_HOST_PTR,
                                   sizeof(float) * ARRAYBUFFER, 
                                   vectorA, NULL);
    memObjects[1] = clCreateBuffer(context, CL_MEM_READ_ONLY | 
                                   CL_MEM_COPY_HOST_PTR,
                                   sizeof(float) * ARRAYBUFFER, 
                                   vectorB, NULL);
    memObjects[2] = clCreateBuffer(context, CL_MEM_READ_WRITE,
                                   sizeof(float) * ARRAYBUFFER, 
                                   NULL, NULL);
    checkMemObjects(memObjects[0], memObjects[1], memObjects[2]);
}
 

void checkContext(cl_context context)
{
    if (context == NULL)
    {
        ERROR_FPRINTF("NO OPENCL CONTEXT FOUND\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Context created successfully!\n");
}

void checkQueue(cl_command_queue commandQueue)
{
    if (commandQueue == NULL)
    {
        ERROR_FPRINTF("BAD COMMANDQUEUE\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Command queue created successfully!\n");

}

void checkProgram(cl_program program)
{
    if (program == NULL)
    {
        ERROR_FPRINTF("BAD PROGRAM\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Program created successfully!\nKernel compiled successfully!\n");
}

void checkKernel(cl_kernel kernel)
{
    if (kernel == NULL)
    {
        ERROR_FPRINTF("FAILED TO CREATE KERNEL\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Kernel created successfully!\n");
}

void checkMemObjects(cl_mem element1, cl_mem element2, cl_mem element3)
{
    if (element1 == NULL || element2 == NULL || element3 == NULL)
    {
        ERROR_FPRINTF("FAILED TO CREATE MEMORY OBJECTS\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Memory objects cretaed successfully!\n");
}

void checkKernelArg(cl_int errorId)
{
    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("FAILED TO SET KERNEL ARGUMENTS\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Kernel arguments set successfully!\n");
}

void checkKernelQueue(cl_int errorId)
{
    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("ERROR QUEUING KERNEL FOR EXECUTION\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Kernel queue set successfully!\n");
}

void checkReadBuffer(cl_int errorId)
{
    if (errorId != CL_SUCCESS)
    {
        ERROR_FPRINTF("FAILED TO READ RESULT BUFFER\nexiting...\n");
        exit(EXIT_FAILURE);
    }
    else SUCCESS_FPRINTF("Result buffer read successfully!\n");
}


size_t fileSize(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    size_t size = ftell(fptr);
    rewind(fptr);

    return size;
}