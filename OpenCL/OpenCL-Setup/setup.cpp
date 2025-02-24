#include "setup.h"

Setup::Setup()
{
    printWelcomeBanner();
    platformId = selectPlatform();
    context = createContext();
    device = selectDevice();
}

cl_device_id Setup::selectDevice()
{
    cl_int errorCode             {};
    cl_device_id *aviableDevices {};
    cl_device_id selectedDevice  {};
    size_t devicesBufferSize     {};

    errorCode = clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL, &devicesBufferSize);
    readErrorCode(errorCode);
    checkAviableDevices(devicesBufferSize);

    aviableDevices = (cl_device_id*) malloc(devicesBufferSize / sizeof(cl_device_id));
    errorCode = clGetContextInfo(context, CL_CONTEXT_DEVICES, devicesBufferSize, 
                                 aviableDevices, NULL);
    readErrorCode(errorCode);

    listDevices();

    size_t numberOfDevices = (sizeof(aviableDevices) / sizeof(cl_device_id)); 
    int deviceChoice {};

    std::cout << "Enter device number: ";
    std::cin >> deviceChoice;
    checkDeviceChoice(deviceChoice, numberOfDevices);

    colcout("\n******** Selected device: " + std::to_string(deviceChoice)
     + " ********\n\n", Color::blue); 

    free(aviableDevices);
    return selectedDevice;
}

void Setup::checkDeviceChoice(int &choice, 
                              size_t aviableDevices)
{
    while (choice < 0 || choice > static_cast<int>(aviableDevices) || std::cin.fail())
    {
        ignoreInput();
        std::cin >> choice;
    }
}

void Setup::displaySpecificInfo(cl_device_id deviceId,
                                cl_device_info paramName,
                                std::string paramNameString)
{
    cl_int errorCode        {};
    size_t paramValueSize   {};

    errorCode = clGetDeviceInfo(deviceId, paramName, 0, NULL, &paramValueSize);
    readErrorCode(errorCode);

    char *info = (char*) malloc(sizeof(char) * paramValueSize);
    errorCode = clGetDeviceInfo(deviceId, paramName, paramValueSize, info, NULL);
    readErrorCode(errorCode);

    // using printf because the line down here print wrong tabulation
    // with the parameter CL_DEVICE_NAME
    // std::cout << "\t" << paramNameString << "\t" << info << "\n";
    printf("\t %s \t %s \n", paramNameString.c_str(), info);

    free(info);
}

void Setup::listDevices()
{
    cl_int errorCode            {};
    size_t paramValueSize       {};
    cl_uint numberOfDevices     {};
    cl_device_id *devices       {};

    errorCode = clGetDeviceIDs(platformId, devType, 0, NULL, &numberOfDevices);
    readErrorCode(errorCode);
    devices = (cl_device_id*) malloc(sizeof(cl_device_id) * numberOfDevices);

    errorCode = clGetDeviceIDs(platformId, devType, numberOfDevices, devices, NULL);
    readErrorCode(errorCode);

    for (size_t i = 0; i < (size_t)numberOfDevices; ++i)
    {
        std::cout << "\tDevieces n: " << i << "\n";
        displaySpecificInfo(devices[i], CL_DEVICE_VENDOR, "CL_DEVICE_VENDOR");
        displaySpecificInfo(devices[i], CL_DEVICE_NAME,   "CL_DEVICE_NAME");
        std::cout << "\n";
    }

    free(devices);
}

void Setup::checkAviableDevices(size_t devicesBufferSize)
{
    if (devicesBufferSize <= 0)
    {
        throwError("No aviable devices!");
    }
}

cl_context Setup::createContext()
{
    cl_int errorCode   {};
    cl_context context {};
    cl_context_properties contextProperties[] =
    {
        CL_CONTEXT_PLATFORM,
        (cl_context_properties)platformId,
        0
    };
    cl_device_type deviceType = selectContextType();

    context = clCreateContextFromType(contextProperties, deviceType, NULL, NULL, &errorCode);
    readErrorCode(errorCode);


    colcout("******** Selected device type: " + typeToString(deviceType)
             + " ********\n\n", Color::blue); 

    return context;
}

std::string Setup::typeToString(cl_device_type type)
{
    std::string str {};

    switch(type)
    {
        case CL_DEVICE_TYPE_CPU:
            str = "CL_DEVICE_TYPE_CPU";
            break;
        case CL_DEVICE_TYPE_GPU:
            str = "CL_DEVICE_TYPE_GPU";
            break;
        case CL_DEVICE_TYPE_ACCELERATOR:
            str = "CL_DEVICE_TYPE_ACCELERATOR";
            break;
        default:
            break;
    }
    return str;
}

cl_device_type Setup::selectContextType()
{
    int typeChoice {};
    
    std::cout << "OpenCL device type: \n\n";
    std::cout << "\t1 CPU\n";
    std::cout << "\t2 GPU\n";
    std::cout << "\t3 ACCELERATOR\n\n";

    std::cout << "Enter device type number: ";
    std::cin >> typeChoice;
    std::cout << "\n";

    checkTypeChoice(typeChoice);

    switch (typeChoice)
    {
        case 1:
            devType = CL_DEVICE_TYPE_CPU;
            return CL_DEVICE_TYPE_CPU;
            break;
        case 2:
            devType = CL_DEVICE_TYPE_GPU;
            return CL_DEVICE_TYPE_GPU;
            break;
        case 3:
            devType = CL_DEVICE_TYPE_ACCELERATOR;
            return CL_DEVICE_TYPE_ACCELERATOR;
            break;
        default:
            return -1;
            break;
    }
}

void Setup::checkTypeChoice(int &choice)
{
    while (choice >= 4 || choice <= 0 || std::cin.fail())
    {
        ignoreInput();
        std::cin >> choice;
    }   
}

cl_platform_id Setup::selectPlatform()
{
    cl_int errorCode                 {};
    cl_uint numberOfPlatformsAviable {};
    cl_platform_id *platformIds      {};
    cl_platform_id selectedPlatform  {};

    errorCode = clGetPlatformIDs(0, NULL, &numberOfPlatformsAviable);
    readErrorCode(errorCode);
    checkNumbersOfPlatform(numberOfPlatformsAviable);

    platformIds = (cl_platform_id*) malloc(sizeof(cl_platform_id) * numberOfPlatformsAviable);
    errorCode = clGetPlatformIDs(numberOfPlatformsAviable, platformIds, NULL);
    readErrorCode(errorCode);

    std::cout << "Listing aviable platforms: \n\n";
    for (size_t i = 0; i < numberOfPlatformsAviable; ++i)
    {
        std::cout << "\tPlatform n: " << i << "\n";
        displayPlatformInfo(platformIds[i], CL_PLATFORM_PROFILE, "CL_PLATFORM_PROFILE");
        displayPlatformInfo(platformIds[i], CL_PLATFORM_VERSION, "CL_PLATFORM_VERSION");
        displayPlatformInfo(platformIds[i], CL_PLATFORM_VENDOR,  "CL_PLATFORM_VENDOR");
        std::cout << "\n\n";
    }
    
    int platformChoice {};

    std::cout << "Enter platform number: ";
    std::cin >> platformChoice;
    std::cout << "\n";

    selectedPlatform = checkPlatformChoice(platformChoice, 
                                           numberOfPlatformsAviable, 
                                           platformIds);

    colcout("******** Selected platform: " + std::to_string(platformChoice)
             + " ********\n\n", Color::blue);

    return selectedPlatform;
}

cl_platform_id Setup::checkPlatformChoice(int choice,
                                          cl_uint maxPlatforms,
                                          cl_platform_id *platforms)
{
    while (choice >= maxPlatforms || choice <= -1 || std::cin.fail())
    {
        ignoreInput();
        std::cin >> choice;
    }   
    return platforms[choice];
}

void Setup::checkNumbersOfPlatform(cl_uint nPlatforms)
{
    if (nPlatforms <= 0) throwError("No aviable paltforms");
}

void Setup::displayPlatformInfo(cl_platform_id platform,
                                cl_platform_info parameter,
                                std::string infoMessage)
{
    cl_int errorCode      {};
    size_t paramValueSize {};

    errorCode = clGetPlatformInfo(platform, parameter, 0, NULL, &paramValueSize);
    readErrorCode(errorCode);

    char *infoOutput = (char*) malloc(sizeof(char) * paramValueSize);
    errorCode = clGetPlatformInfo(platform, parameter, paramValueSize, infoOutput, NULL);
    readErrorCode(errorCode);

    std::cout << "\t" << infoMessage << "\t" << infoOutput << "\n";

    free(infoOutput);
}

void Setup::ignoreInput()
{
    std::cout << "Bad input! Enter a valid integer: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Setup::readErrorCode(cl_int errorCode)
{
    switch(errorCode)
    {
    case CL_DEVICE_NOT_FOUND:
        throwError("CL_DEVICE_NOT_FOUND");
        break;
    case CL_DEVICE_NOT_AVAILABLE:
        throwError("CL_DEVICE_NOT_AVAILABLE");    
        break;
    case CL_COMPILER_NOT_AVAILABLE:
        throwError("CL_COMPILER_NOT_AVAILABLE");    
        break;
    case CL_MEM_OBJECT_ALLOCATION_FAILURE:
        throwError("CL_MEM_OBJECT_ALLOCATION_FAILURE");
        break;
    case CL_OUT_OF_RESOURCES:
        throwError("CL_OUT_OF_RESOURCES");
        break;
    case CL_OUT_OF_HOST_MEMORY:
        throwError("CL_OUT_OF_HOST_MEMORY");
        break;
    case CL_PROFILING_INFO_NOT_AVAILABLE:
        throwError("CL_PROFILING_INFO_NOT_AVAILABLE");
        break;
    case CL_MEM_COPY_OVERLAP:
        throwError("CL_MEM_COPY_OVERLAP");
        break;
    case CL_IMAGE_FORMAT_MISMATCH:
        throwError("CL_IMAGE_FORMAT_MISMATCH");
        break;
    case CL_IMAGE_FORMAT_NOT_SUPPORTED:
        throwError("CL_IMAGE_FORMAT_NOT_SUPPORTED");
        break;
    case CL_BUILD_PROGRAM_FAILURE:
        throwError("CL_BUILD_PROGRAM_FAILURE");
        break;
    case CL_MAP_FAILURE:
        throwError("CL_MAP_FAILURE");
        break;
    case CL_MISALIGNED_SUB_BUFFER_OFFSET:
        throwError("CL_MISALIGNED_SUB_BUFFER_OFFSET");
        break;
    case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST:
        throwError("CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST");
        break;
    case CL_COMPILE_PROGRAM_FAILURE:
        throwError("CL_COMPILE_PROGRAM_FAILURE");
        break;
    case CL_LINKER_NOT_AVAILABLE:
        throwError("CL_LINKER_NOT_AVAILABLE");
        break;
    case CL_LINK_PROGRAM_FAILURE:
        throwError("CL_LINK_PROGRAM_FAILURE");
        break;
    case CL_DEVICE_PARTITION_FAILED:
        throwError("CL_DEVICE_PARTITION_FAILED");
        break;
    case CL_KERNEL_ARG_INFO_NOT_AVAILABLE:
        throwError("CL_KERNEL_ARG_INFO_NOT_AVAILABLE");
        break;
    case CL_INVALID_VALUE:
        throwError("CL_INVALID_VALUE");
        break;                            
    case CL_INVALID_DEVICE_TYPE:
        throwError("CL_INVALID_DEVICE_TYPE");
        break;                      
    case CL_INVALID_PLATFORM:
        throwError("CL_INVALID_PLATFORM");
        break;                         
    case CL_INVALID_DEVICE:
        throwError("CL_INVALID_DEVICE");
        break;                           
    case CL_INVALID_CONTEXT:
        throwError("CL_INVALID_CONTEXT");
        break;                          
    case CL_INVALID_QUEUE_PROPERTIES:
        throwError("CL_INVALID_QUEUE_PROPERTIES");
        break;                 
    case CL_INVALID_COMMAND_QUEUE:
        throwError("CL_INVALID_COMMAND_QUEUE");
        break;                    
    case CL_INVALID_HOST_PTR:
        throwError("CL_INVALID_HOST_PTR");
        break;
    case CL_INVALID_MEM_OBJECT:
        throwError("CL_INVALID_MEM_OBJECT");
        break;
    case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
        throwError("CL_INVALID_IMAGE_FORMAT_DESCRIPTOR");
        break;
    case CL_INVALID_IMAGE_SIZE:
        throwError("CL_INVALID_IMAGE_SIZE");
        break;                         
    case CL_INVALID_SAMPLER:
        throwError("CL_INVALID_SAMPLER");
        break;                          
    case CL_INVALID_BINARY:
        throwError("CL_INVALID_BINARY");
        break;                           
    case CL_INVALID_BUILD_OPTIONS:
        throwError("CL_INVALID_BUILD_OPTIONS");
        break;                    
    case CL_INVALID_PROGRAM:
        throwError("CL_INVALID_PROGRAM");
        break;                          
    case CL_INVALID_PROGRAM_EXECUTABLE:
        throwError("CL_INVALID_PROGRAM_EXECUTABLE");
        break;               
    case CL_INVALID_KERNEL_NAME:
        throwError("CL_INVALID_KERNEL_NAME");
        break;                      
    case CL_INVALID_KERNEL_DEFINITION:
        throwError("CL_INVALID_KERNEL_DEFINITION");
        break;                
    case CL_INVALID_KERNEL:
        throwError("CL_INVALID_KERNEL");
        break;                           
    case CL_INVALID_ARG_INDEX:
        throwError("CL_INVALID_ARG_INDEX");
        break;                       
    case CL_INVALID_ARG_VALUE:
        throwError("CL_INVALID_ARG_VALUE");
        break;                        
    case CL_INVALID_ARG_SIZE:
        throwError("CL_INVALID_ARG_SIZE");
        break;                         
    case CL_INVALID_KERNEL_ARGS:
        throwError("CL_INVALID_KERNEL_ARGS");
        break;                      
    case CL_INVALID_WORK_DIMENSION:
        throwError("CL_INVALID_WORK_DIMENSION");
        break;                 
    case CL_INVALID_WORK_GROUP_SIZE:
        throwError("CL_INVALID_WORK_GROUP_SIZE");
        break;                  
    case CL_INVALID_WORK_ITEM_SIZE:
        throwError("CL_INVALID_WORK_ITEM_SIZE");
        break;                   
    case CL_INVALID_GLOBAL_OFFSET:
        throwError("CL_INVALID_GLOBAL_OFFSET");
        break;                    
    case CL_INVALID_EVENT_WAIT_LIST:
        throwError("CL_INVALID_EVENT_WAIT_LIST");
        break;                  
    case CL_INVALID_EVENT:
        throwError("CL_INVALID_EVENT");
        break;                            
    case CL_INVALID_OPERATION:
        throwError("CL_INVALID_OPERATION");
        break;                        
    case CL_INVALID_GL_OBJECT:
        throwError("CL_INVALID_GL_OBJECT");
        break;                        
    case CL_INVALID_BUFFER_SIZE:
        throwError("CL_INVALID_BUFFER_SIZE");
        break;                      
    case CL_INVALID_MIP_LEVEL:
        throwError("CL_INVALID_MIP_LEVEL");
        break;                        
    case CL_INVALID_GLOBAL_WORK_SIZE:
        throwError("CL_INVALID_GLOBAL_WORK_SIZE");
        break;                
    case CL_INVALID_PROPERTY:
        throwError("CL_INVALID_PROPERTY");
        break;                         
    case CL_INVALID_IMAGE_DESCRIPTOR:
        throwError("CL_INVALID_IMAGE_DESCRIPTOR");
        break;                 
    case CL_INVALID_COMPILER_OPTIONS:
        throwError("CL_INVALID_COMPILER_OPTIONS");
        break;                 
    case CL_INVALID_LINKER_OPTIONS:
        throwError("CL_INVALID_LINKER_OPTIONS");
        break;                   
    case CL_INVALID_DEVICE_PARTITION_COUNT:
        throwError("CL_INVALID_DEVICE_PARTITION_COUNT");
        break;           
    case CL_INVALID_PIPE_SIZE:
        throwError("CL_INVALID_PIPE_SIZE");
        break;                        
    case CL_INVALID_DEVICE_QUEUE:
        throwError("CL_INVALID_DEVICE_QUEUE");
        break;                     
    case CL_INVALID_SPEC_ID:
        throwError("CL_INVALID_SPEC_ID");
        break;                          
    case CL_MAX_SIZE_RESTRICTION_EXCEEDED:
        throwError("CL_MAX_SIZE_RESTRICTION_EXCEEDED");
        break;            
    default:
        break;
    }
}

[[noreturn]] void Setup::throwError(std::string stringErrorCode)
{
    throw std::invalid_argument("Received error code: " + stringErrorCode);
}

void Setup::printWelcomeBanner()
{
    colcout("\n******** OpenCL Configuration ********\n\n", Color::green);
}
