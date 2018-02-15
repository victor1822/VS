__kernel void RayTracer(__global float4* matrix,
                          __global float4* vector,
                          __global float* result) {

   int i = get_global_id(0);
   printf(" %d ",&i);
   result[i] = dot(matrix[i], vector[0]);
}

