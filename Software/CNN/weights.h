#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV1D_KERNEL_0 {-11, 17, -15, 26, 0, -32, 29, 47, -50, -24, 0, -2, -55, 20, -3, -32, 36, -10, 46, -17, 0, 38, -33, -30, 12, -45, -24, 6, 28, 6, 41, 50, -35, 27, 51, 18, 48, 11, 17, 34, 18, -25, 44, 22, -6, -38, -62, 23, -20, -32, -23, 22, -29, -12, 0, 32, 27, -26, 37, -7, -41, 31, -30, -19, -28, -8, -48, -20, 3, -52, -8, -4, 27, -64, -46, 1, -47, 4, -29, -73, -50, -32, -31, -19, -13, -19, 4, 9, 10, 23, -51, 49, -10, -36, 1, 15, -18, 18, -18, 38, -28, 65, 13, -45, 64, 5, -10, 51, 28, 22, -38, 7, 3, -40, 48, 17, -31, -40, -14, -31, -44, -32, 11, -32, 13, -13, 16, -47, 50, 22, -12, 52, 13, 5, 12, 3, 39, 50, -12, 42, 42, -36, 53, 66, 0, 17, -44, -11, -31, -33, -18, -39, -60, 8, 9, 10, 52, 0, 20, 36, 29, 52, 1, 24, -32, 44, -16, -39, 16, -24, -60, 35, -26, 73, -25, -61, 10, 27, -9, 36, -1, -42, -4, 53, -14, 45, 18, -18, 52, 27, 33, -50, 25, 17, -29, 28, 7, -29, -21, 24, -53, -18, -4, -25, -35, -15, -60, 23, -51, -22, 52, -61, 1, 56, -32, 23, 46, 28, -36, 27, 37, 11, 47, 46, -13, -36, -6, -48, -10, 16, -49, 8, -36, -32, 29, -2, -38, 37, -11, -6, 13, 5, -40, -12, -75, -2, -34, -73, 28, 18, -14, 29, 30, 35, -55, 36, 8, -8, 38, -24, -15, -3, -10, -37, -28, -50, -39, -20, -56, 6}

#define TENSOR_CONV1D_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV1D_BIAS_0 {-41, 92, 117, -5, 66, 124, 20, 34, 127, -1, 98, 8, 82, 35, 4, 102, -10, 111, 73, 2, 103, 26, 10, 101, -15, 14, 37, 127, 0, 107}

#define TENSOR_CONV1D_BIAS_0_DEC_BITS {9}

#define CONV1D_BIAS_LSHIFT {3}

#define CONV1D_OUTPUT_RSHIFT {7}

#define TENSOR_CONV1D_1_KERNEL_0 {-26, -17, 43, -26, 44, 43, -15, -26, -9, -11, 28, -51, 42, -9, -36, 34, -40, 26, -1, -52, 27, -33, -19, -1, -13, -8, 17, 28, -4, 30, -31, 1, 31, -20, 7, 13, -40, -30, 43, -5, -18, -45, 17, -9, -50, 6, -17, 36, 49, -36, 11, -12, -43, 41, -24, -29, 4, 15, -30, -7, -25, -18, 31, -36, 9, 37, -9, -11, 43, -24, 15, -23, 22, -43, -44, 16, -4, 8, 17, 3, 21, -1, -47, 29, -34, -12, -3, 29, 7, 39, 28, 29, 20, 35, -12, -20, 15, -2, -7, -37, 16, 4, 18, 7, -8, 59, 0, 37, -18, 29, 22, 21, 4, -11, 15, 15, -16, 17, 16, 22, 10, -9, 15, 8, -17, 25, 40, -32, 12, -33, 6, -4, 27, -14, -6, 24, -18, 44, 20, -6, 49, -17, 7, 13, -26, -3, -13, -10, -21, -18, -20, 15, -9, 1, 39, -30, 16, -5, -10, 8, 34, 6, -11, -30, 24, 35, 7, 11, -20, -11, 29, 3, -1, 8, -4, -11, -33, 13, -28, -10, -20, 40, 34, -31, -29, 64, -22, 20, 45, -3, 17, -19, -4, 21, 12, -19, 29, -24, 7, 30, -9, 13, 30, 11, -33, 45, -4, 38, 2, 19, 3, 20, 7, 15, -18, 21, -22, 12, 18, 6, 42, 12, -11, -4, 22, 33, -5, 12, -9, 53, -14, -31, 3, 19, -17, 20, -29, 29, -21, 48, -26, 44, 30, -19, -26, 38, -32, 19, 31, 22, -9, -14, -32, 7, 16, 30, -33, 6, -25, 46, 7, -16, -18, -31, -33, 7, -28, 53, -12, 21, 11, 6, 4, -28, 19, -14, -23, -3, -56, 21, -28, 15, 10, 4, 41, 14, -8, 23, -8, 22, 13, -17, -14, 25, 11, -6, -14, -4, 20, -46, -3, -16, 17, 7, -6, -27, -38, 18, 0, 7, -17, 8, -27, 0, 47, 44, 24, 4, -26, 28, 17, -27, 18, 11, -16, 1, 14, -21, 3, -34, 14, -31, -24, -9, -18, 22, -20, -11, -31, 13, -34, 46, 16, -14, 38, 28, -11, 11, -26, 19, 30, 12, 0, 6, -2, 9, -4, 28, -11, -33, 13, -24, -28, -19, -29, -20, 10, -26, 16, -8, 26, -10, 17, 13, 12, -29, 5, -28, 6, 20, -13, 23, 18, 1, -21, 40, 6, -29, 24, 41, 17, 8, 26, -11, 2, 4, 0, 15, -3, -4, -22, 6, 18, -21, 16, -1, 40, -17, 29, -8, -22, 43, 15, -43, -14, 11, 15, 0, -17, -21, 14, 10, 28, 1, -15, 10, -33, -1, 13, -5, 0, 16, 28, -2, -1, -45, 33, -47, 28, -2, 6, 19, 28, -18, -4, 23, 4, -10, 22, -20, -10, 36, -24, -10, -36, 33, 41, 13, -14, 11, 37, 19, 5, 29, 35, 22, 13, -7, -40, -18, -47, -21, 8, -35, -23, 5, -34, -15, -30, 17, -5, 4, -38, -4, 10, 7, 0, 26, 6, -9, 1, -10, 1, 32, 31, 22, 38, 8, -5, -9, -54, 2, 35, -47, -20, 19, -42, -27, -16, 6, -5, 46, 6, 13, 11, 0, 46, 23, 18, 19, 30, 4, -1, 25, 9, -31, 55, -27, 8, -11, -44, -32, 21, -19, 24, 21, -10, 17, 14, 45, -29, -69, 60, -55, 3, 13, -36, -25, 29, -16, -64, 27, -9, -41, 51, -20, -25, 34, -15, 34, 12, -30, -13, 63, -22, -11, 48, 35, -21, -14, -13, -8, 33, -22, 0, 28, -24, -6, 64, 5, -41, 32, 16, -55, -12, -32, -39, -29, 14, 17, -14, -35, -41, 24, -41, -27, -3, 46, -25, 14, -35, -6, 39, -13, -33, 65, 23, 30, 57, -8, -16, -40, 25, 2, -3, -8, -17, -6, 37, -35, 11, 0, -19, 35, -6, -24, -6, 21, 7, 22, -12, 0, 44, 6, 32, -3, 5, -34, 7, 10, -14, -28, 7, -21, 8, -39, 17, 21, 38, -29, -23, 27, 20, 25, 54, 32, 42, -33, 19, -7, 35, -42, 34, 30, 39, -14, -22, -17, -9, -23, -30, -23, 33, 18, 14, -26, 23, 34, 28, -13, -2, 7, -17, 16, 56, 23, 44, -41, 37, 7, -17, -31, 1, 17, 55, -26, -10, -8, -6, 16, -39, 27, 45, 12, 14, -21, 23, 21, 10, -13, 35, 2, 3, 36, 13, 22, 24, -26, 37, -3, -29, -55, 36, -12, 5, 7, -8, -11, -9, -24, -15, 63, -46, -56, 45, 20, -58, 53, -41, 44, 24, -34, -46, 4, 30, -11, -18, 23, 12, -5, -48, -37, 22, 18, 32, -10, -8, 20, 30, -6, -7, 43, -40, -34, 46, 29, -20, 14, -34, 63, 38, -48, -12, 42, 21, -59, -30, 5, 6, -11, -4, 30, 19, 15, 15, -10, 8, -3, -13, 18, -19, 51, -17, 10, 28, 10, -20, 29, -21, 17, 54, -40, -26, -1, 22, 4, -24, 20, -22, -23, 37, 14, 21, 28, 27, 31, -24, -11, 37, -12, 37, 6, 20, 19, -25, 22, -10, 15, 23, 9, -44, 25, 16, 2, 24, 7, 1, 3, -8, 6, -2, 13, 19, 32, -14, 23, -19, -12, 35, 22, 17, -39, 43, 20, -5, -11, 20, -1, 16, -8, -14, 6, 5, -36, 9, 13, 6, 17, 6, 10, 33, 41, 33, -4, 32, 27, 11, 21, 38, -12, 21, -14, 24, 19, 19, -18, 31, 28, 18, 3, -23, 19, 17, -25, 31, 20, 6, 2, -16, 42, 8, -34, 32, 37, 42, -28, 15, -26, -4, -27, -22, -4, 35, -26, -4, -20, 27, 28, 20, -22, -32, 26, -11, 5, 40, 20, 41, -13, 11, -2, 31, -18, 39, 50, 33, -15, -28, -3, 27, 20, -27, -38, 43, -12, 6, -18, 27, -3, 20, -6, 16, -2, 30, 30, 5, -4, 20, -34, 37, -18, 40, -23, 16, 33, -7, -38, -27, -1, -8, -20, -30, 14, 10, 3, 29, -7, 30, 10, 46, -11, 8, 39, 10, 20, 37, -7, 54, -52, 46, -23, -28, 29, 25, -29, -11, -3, 17, -30, -3, -8, -1, 22, 8, 19, 35, 43, -29, 9, -40, 44, 28, -9, 14, 22, -50, -16, 10, 17, -26, -15, -20, 23, -1, -51, 17, 37, -20, -37, -15, 17, 11, 25, -12, -2, 2, 16, 3, 5, 1, 30, 32, 0, -10, 19, -33, 22, -16, 21, -10, 16, -33, -6, 32, -38, 29, -21, 9, -33, 7, 4, -17, 1, 12, -31, 11, 1, -31, 44, -2, 49, 12, -1, 5, -1, -21, -8, 9, -12, -5, 1, -1, -10, 10, 22, 29, -4, -36, 15, -40, 11, -38, 10, -26, -23, 36, 37, -1, 41, 6, 19, 49, 35, 18, -1, 39, -7, -28, -9, 22, -35, 44, -21, 3, 26, 22, -24, -20, -23, -11, 22, -10, 49, 20, 17, 52, -19, 19, 28, -13, 3, 43, -8, 17, 19, 11, -22, 4, -6, 18, -23, 38, -36, 6, 21, 21, 0, 3, -17, -34, 8, -56, 28, 2, -25, 42, -15, 39, 27, -16, 10, 38, 32, -27, 41, 26, -3, -7, 30, -8, -9, 13, -36, 45, -9, 20, 35, -16, 10, 49, 28, -36, 30, 28, 4, 12, -45, 2, -18, 47, 19, 8, -6, 14, 34, -23, 7, 14, 57, 22, 38, -1, -33, 3, -18, 6, 3, -9, -13, 60, 0, -25, -1, 11, 8, 8, -47, 27, -25, 5, 36, 15, 22, 7, 41, -25, 28, 2, 14, -10, 35, 0, -10, 20, -8, -32, 44, -11, -7, 7, 34, 11, -7, 2, 30, -30, -33, 19, 7, -2, -8, 5, -4, 4, 25, 5, 11, 14, 36, 14, 40, 2, -36, 16, 3, 14, 20, -47, -43, 7, -36, -1, 1, 0, -64, -6, -14, 0, -4, 45, 12, 15, -6, -27, 35, 20, 22, 7, 32, 22, -11, -18, -59, 32, -14, -4, 11, -36, -17, 25, -35, -35, -34, 44, -41, -10, -20, 29, 24, 26, 36, 34, 29, -32, 46, 15, -28, 13, 4, 43, 26, -16, 0, 46, -14, 32, 36, 7, -9, 46, -33, -33, 0, 8, -16, -19, -26, 1, 0, 28, -14, 13, 19, -41, 13, -2, -29, 51, 14, 17, -2}

#define TENSOR_CONV1D_1_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV1D_1_BIAS_0 {75, 57, 74, -28, -25, 37, 55, -44, -3, 61, -42, 54, -19, -14, 42}

#define TENSOR_CONV1D_1_BIAS_0_DEC_BITS {9}

#define CONV1D_1_BIAS_LSHIFT {3}

#define CONV1D_1_OUTPUT_RSHIFT {9}

#define TENSOR_DENSE_KERNEL_0 {24, 38, 29, -2, -3, 18, -8, -17, -26, 36, 2, -30, -10, -42, 8, 50, 10, 13, -33, -69, 1, 17, -70, 25, -12, 42, -43, -24, 4, -21, 0, -14, -21, -65, 3, -36, -13, 22, 46, -57, -53, 4, -9, 42, 4, -52, -58, 17, -64, -63, 2, -17, 31, 9, -24, -12, 9, -78, 65, 41, 3, 13, -57, 9, 35, -11, -32, 20, 0, -53, -28, 33, -35, 0, -17, -36, 23, -56, -26, 15, -22, 37, 35, -12, 58, -29, 13, -4, 21, -27, -35, -35, -31, -31, -12, 28, -46, 40, 31, -5, -24, -29, -31, 14, 4, -9, -29, -30, 31, 14, -7, -29, 26, 39, 51, -41, -2, -49, -53, -47, 18, 3, -15, 1, -7, 22, -41, -56, -15, 41, -37, 12, -9, -3, 42, 35, -33, -21, -10, 11, 35, 18, 47, -39, 60, -6, -21, -21, -45, -25, 38, -30, 27, -43, -24, 5, 3, 32, -41, 34, 4, -45, -11, -37, -10, 35, 38, 4, 10, -24, 13, -35, -38, -4, 4, 19, 15, -55, -40, -27, -5, 21, -16, -4, 60, -5, -63, 56, -16, 2, -27, 19, -18, -60, -27, 11, 29, 22, 33, 25, 10, 13, 47, -51, -26, 9, -24, -67, -24, 4, -4, 2, 1, 29, 24, 13, -11, 2, -28, -13, -7, 22, 36, 10, -42, 6, -6, -6, -44, -15, -39, 5, 1, -42, 46, -50, 16, -9, 7, -16, 25, 30, -19, 28, -49, -3, -46, -25, -1, 5, -32, -10, 2, -32, -12, -20, 8, -16, 46, -4, 18, 17, -19, -13, -47, -4, 1, -62, 69, -41, 52, 2, 6, -43, -15, -1, 57, -11, 30, 41, -6, 30, 15, -30, 24, 25, -7, -43, -8, -34, -15, 27, -20, 9, -40, -4, 53, -56, -7, -12, -30, -8, 2, -19, -15, 40, 75, -50, 73, -19, -42, 15, -13, 45, 35, -10, 20, 10, 3, 40, -15, -5, -32, 52, -27, -36, 31, 7, -52, -12, 8, -5, -20, 23, 14, -40, 20, -46, 33, -21, -66, 2, -8, -20, -35, -49, 10, 1, 11, -33, -6, 4, -24, 28, 1, 2, 33, 47, -53, -13, 41, 5, 19, 36, -62, -26, -7, -52, 11, -7, -25, 39, 37, -58, -13}

#define TENSOR_DENSE_KERNEL_0_DEC_BITS {7}

#define TENSOR_DENSE_BIAS_0 {-49, 97, -60, -93, 61}

#define TENSOR_DENSE_BIAS_0_DEC_BITS {10}

#define DENSE_BIAS_LSHIFT {0}

#define DENSE_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define INPUT_1_OUTPUT_DEC 5
#define INPUT_1_OUTPUT_OFFSET 0
#define CONV1D_OUTPUT_DEC 5
#define CONV1D_OUTPUT_OFFSET 0
#define RE_LU_OUTPUT_DEC 5
#define RE_LU_OUTPUT_OFFSET 0
#define CONV1D_1_OUTPUT_DEC 3
#define CONV1D_1_OUTPUT_OFFSET 0
#define RE_LU_1_OUTPUT_DEC 3
#define RE_LU_1_OUTPUT_OFFSET 0
#define MAX_POOLING1D_OUTPUT_DEC 3
#define MAX_POOLING1D_OUTPUT_OFFSET 0
#define FLATTEN_OUTPUT_DEC 3
#define FLATTEN_OUTPUT_OFFSET 0
#define DENSE_OUTPUT_DEC 3
#define DENSE_OUTPUT_OFFSET 0
#define DROPOUT_OUTPUT_DEC 3
#define DROPOUT_OUTPUT_OFFSET 0
#define SOFTMAX_OUTPUT_DEC 7
#define SOFTMAX_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[450] = {0};

const nnom_shape_data_t tensor_input_1_dim[] = {150, 3};
const nnom_qformat_param_t tensor_input_1_dec[] = {5};
const nnom_qformat_param_t tensor_input_1_offset[] = {0};
const nnom_tensor_t tensor_input_1 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_input_1_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_input_1_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_input_1_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t input_1_config = {
    .super = {.name = "input_1"},
    .tensor = (nnom_tensor_t*)&tensor_input_1
};
const int8_t tensor_conv1d_kernel_0_data[] = TENSOR_CONV1D_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_kernel_0_dim[] = {3, 3, 30};
const nnom_qformat_param_t tensor_conv1d_kernel_0_dec[] = TENSOR_CONV1D_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_kernel_0 = {
    .p_data = (void*)tensor_conv1d_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_bias_0_data[] = TENSOR_CONV1D_BIAS_0;

const nnom_shape_data_t tensor_conv1d_bias_0_dim[] = {30};
const nnom_qformat_param_t tensor_conv1d_bias_0_dec[] = TENSOR_CONV1D_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_bias_0 = {
    .p_data = (void*)tensor_conv1d_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_output_shift[] = CONV1D_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_bias_shift[] = CONV1D_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_config = {
    .super = {.name = "conv1d"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_bias_shift, 
    .filter_size = 30,
    .kernel_size = {3},
    .stride_size = {3},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv1d_1_kernel_0_data[] = TENSOR_CONV1D_1_KERNEL_0;

const nnom_shape_data_t tensor_conv1d_1_kernel_0_dim[] = {3, 30, 15};
const nnom_qformat_param_t tensor_conv1d_1_kernel_0_dec[] = TENSOR_CONV1D_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_1_kernel_0 = {
    .p_data = (void*)tensor_conv1d_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};
const int8_t tensor_conv1d_1_bias_0_data[] = TENSOR_CONV1D_1_BIAS_0;

const nnom_shape_data_t tensor_conv1d_1_bias_0_dim[] = {15};
const nnom_qformat_param_t tensor_conv1d_1_bias_0_dec[] = TENSOR_CONV1D_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv1d_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv1d_1_bias_0 = {
    .p_data = (void*)tensor_conv1d_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv1d_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv1d_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv1d_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv1d_1_output_shift[] = CONV1D_1_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv1d_1_bias_shift[] = CONV1D_1_BIAS_LSHIFT;
const nnom_conv2d_config_t conv1d_1_config = {
    .super = {.name = "conv1d_1"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv1d_1_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv1d_1_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv1d_1_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv1d_1_bias_shift, 
    .filter_size = 15,
    .kernel_size = {3},
    .stride_size = {3},
    .padding_size = {0, 0},
    .dilation_size = {1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling1d_config = {
    .super = {.name = "max_pooling1d"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {3},
    .stride_size = {3},
    .num_dim = 1
};

const nnom_flatten_config_t flatten_config = {
    .super = {.name = "flatten"}
};
const int8_t tensor_dense_kernel_0_data[] = TENSOR_DENSE_KERNEL_0;

const nnom_shape_data_t tensor_dense_kernel_0_dim[] = {75, 5};
const nnom_qformat_param_t tensor_dense_kernel_0_dec[] = TENSOR_DENSE_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_kernel_0 = {
    .p_data = (void*)tensor_dense_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_bias_0_data[] = TENSOR_DENSE_BIAS_0;

const nnom_shape_data_t tensor_dense_bias_0_dim[] = {5};
const nnom_qformat_param_t tensor_dense_bias_0_dec[] = TENSOR_DENSE_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_bias_0 = {
    .p_data = (void*)tensor_dense_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_output_shift[] = DENSE_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_bias_shift[] = DENSE_BIAS_LSHIFT;
const nnom_dense_config_t dense_config = {
    .super = {.name = "dense"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_bias_shift
};

const nnom_softmax_config_t softmax_config = {
    .super = {.name = "softmax"}
};
static int8_t nnom_output_data[5] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {5};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_io_config_t output0_config = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create(void)
{
	static nnom_model_t model;
	nnom_layer_t* layer[10];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&input_1_config);
	layer[1] = model.hook(conv2d_s(&conv1d_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv1d_1_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(maxpool_s(&max_pooling1d_config), layer[4]);
	layer[6] = model.hook(flatten_s(&flatten_config), layer[5]);
	layer[7] = model.hook(dense_s(&dense_config), layer[6]);
	layer[8] = model.hook(softmax_s(&softmax_config), layer[7]);
	layer[9] = model.hook(output_s(&output0_config), layer[8]);
	model_compile(&model, layer[0], layer[9]);
	return &model;
}
