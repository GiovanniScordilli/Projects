__kernel void vectorAddition(__global const float *elementOfVectorA,
                             __global const float *elementOfVectorB,
                             __global float *result)
{
    int gid  = get_global_id(0);
    result[gid] = elementOfVectorA[gid] + elementOfVectorB[gid];
}