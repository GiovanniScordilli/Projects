#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "init.h"

int main(int argc, char** argv)
{
    srand(time(NULL));

    cl_context context = 0;
    cl_command_queue commandQueue = 0;
    cl_program program = 0;
    cl_device_id device = 0;
    cl_kernel kernel = 0;
    cl_mem memObjects[MEMOBJECTSBUFFER] = {0, 0, 0};
    cl_int errorId = 0;
    const char* kernelName = "vectorAddition";
    const char* kernelFileName = "../src/kernel.cl";
    float *arrayOutput = (float*)malloc(ARRAYBUFFER * sizeof(float));
    float *arrayInputA = (float*)malloc(ARRAYBUFFER * sizeof(float));
    float *arrayInputB = (float*)malloc(ARRAYBUFFER * sizeof(float));

    for (size_t i = 0; i < ARRAYBUFFER; ++i)
    {
        arrayInputA[i] = (float)rand();
        arrayInputB[i] = (float)rand();
    }

    context = createContext();
    checkContext(context);
    commandQueue = createQueue(context, &device); 
    checkQueue(commandQueue);
    program = createProgram(context, device, kernelFileName);
    checkProgram(program);
    kernel = clCreateKernel(program, kernelName, NULL);
    checkKernel(kernel);
    createMemoryObjects(context, memObjects, arrayInputA, arrayInputB);

    errorId = clSetKernelArg(kernel, 0, sizeof(cl_mem), &memObjects[0]);
    errorId |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &memObjects[1]);
    errorId |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &memObjects[2]);
    checkKernelArg(errorId);
    errorId = 0; 
    
    size_t globalWorkSize[1] = {ARRAYBUFFER};
    size_t localWorkSize[1] = { 1 };
    errorId = clEnqueueNDRangeKernel(commandQueue, kernel, 1, 
                                     NULL, globalWorkSize, localWorkSize,
                                     0, NULL, NULL);
    checkKernelQueue(errorId);
    errorId = 0;

    errorId = clEnqueueReadBuffer(commandQueue, memObjects[2],
                                  CL_TRUE, 0,
                                  ARRAYBUFFER * sizeof(float), arrayOutput,
                                  0, NULL, NULL);
    checkReadBuffer(errorId);
    errorId = 0;

    SUCCESS_FPRINTF("OpenCL program executed successfully\nexiting...\n");
    
    free(arrayOutput);
    free(arrayInputA);
    free(arrayInputB);
    return 0;
} 