/*
 *  Copyright (c) 2013, Stefan Johnson
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list
 *     of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice, this
 *     list of conditions and the following disclaimer in the documentation and/or other
 *     materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VecOp_VecOpStd_h
#define VecOp_VecOpStd_h
#define VEC_OP_STANDARD 1

#include <stdint.h>


#define VEC_OP_VEC2(type) \
union { \
    struct { \
        type x; \
        type y; \
    }; \
    struct { \
        type r; \
        type g; \
    }; \
    struct { \
        type s; \
        type t; \
    }; \
    type v[2]; \
}

#define VEC_OP_VEC3(type) \
union { \
    struct { \
        type x; \
        type y; \
        type z; \
    }; \
    struct { \
        type r; \
        type g; \
        type b; \
    }; \
    struct { \
        type s; \
        type t; \
        type p; \
    }; \
    type v[3]; \
}

#define VEC_OP_VEC4(type) \
union { \
    struct { \
        type x; \
        type y; \
        type z; \
        type w; \
    }; \
    struct { \
        type r; \
        type g; \
        type b; \
        type a; \
    }; \
    struct { \
        type s; \
        type t; \
        type p; \
        type q; \
    }; \
    type v[4]; \
}

#define VEC_OP_VEC8(type) \
union { \
    type v[8]; \
}

#define VEC_OP_VEC16(type) \
union { \
    type v[16]; \
}

//float32
typedef VEC_OP_VEC2(float) vec_op_std_v2float32;
typedef VEC_OP_VEC3(float) vec_op_std_v3float32;
typedef VEC_OP_VEC4(float) vec_op_std_v4float32;
typedef VEC_OP_VEC8(float) vec_op_std_v8float32;
typedef VEC_OP_VEC16(float) vec_op_std_v16float32;
//float64
typedef VEC_OP_VEC2(double) vec_op_std_v2float64;
typedef VEC_OP_VEC3(double) vec_op_std_v3float64;
typedef VEC_OP_VEC4(double) vec_op_std_v4float64;
typedef VEC_OP_VEC8(double) vec_op_std_v8float64;
typedef VEC_OP_VEC16(double) vec_op_std_v16float64;
//int8
typedef VEC_OP_VEC2(int8_t) vec_op_std_v2int8;
typedef VEC_OP_VEC3(int8_t) vec_op_std_v3int8;
typedef VEC_OP_VEC4(int8_t) vec_op_std_v4int8;
typedef VEC_OP_VEC8(int8_t) vec_op_std_v8int8;
typedef VEC_OP_VEC16(int8_t) vec_op_std_v16int8;
//int16
typedef VEC_OP_VEC2(int16_t) vec_op_std_v2int16;
typedef VEC_OP_VEC3(int16_t) vec_op_std_v3int16;
typedef VEC_OP_VEC4(int16_t) vec_op_std_v4int16;
typedef VEC_OP_VEC8(int16_t) vec_op_std_v8int16;
typedef VEC_OP_VEC16(int16_t) vec_op_std_v16int16;
//int32
typedef VEC_OP_VEC2(int32_t) vec_op_std_v2int32;
typedef VEC_OP_VEC3(int32_t) vec_op_std_v3int32;
typedef VEC_OP_VEC4(int32_t) vec_op_std_v4int32;
typedef VEC_OP_VEC8(int32_t) vec_op_std_v8int32;
typedef VEC_OP_VEC16(int32_t) vec_op_std_v16int32;
//int64
typedef VEC_OP_VEC2(int64_t) vec_op_std_v2int64;
typedef VEC_OP_VEC3(int64_t) vec_op_std_v3int64;
typedef VEC_OP_VEC4(int64_t) vec_op_std_v4int64;
typedef VEC_OP_VEC8(int64_t) vec_op_std_v8int64;
typedef VEC_OP_VEC16(int64_t) vec_op_std_v16int64;
//native size
#if VEC_OP_NATIVE_VECTOR_SIZE == 128
typedef vec_op_std_v16float64 vec_op_std_vfloat64;
typedef vec_op_std_v16int64 vec_op_std_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 64
typedef vec_op_std_v16float32 vec_op_std_vfloat32;
typedef vec_op_std_v8float64 vec_op_std_vfloat64;
typedef vec_op_std_v16int32 vec_op_std_vint32;
typedef vec_op_std_v8int64 vec_op_std_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 32
typedef vec_op_std_v8float32 vec_op_std_vfloat32;
typedef vec_op_std_v4float64 vec_op_std_vfloat64;
typedef vec_op_std_v16int16 vec_op_std_vint16;
typedef vec_op_std_v8int32 vec_op_std_vint32;
typedef vec_op_std_v4int64 vec_op_std_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 24
typedef vec_op_std_v3float64 vec_op_std_vfloat64;
typedef vec_op_std_v3int64 vec_op_std_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 16
typedef vec_op_std_v4float32 vec_op_std_vfloat32;
typedef vec_op_std_v2float64 vec_op_std_vfloat64;
typedef vec_op_std_v16int8 vec_op_std_vint8;
typedef vec_op_std_v8int16 vec_op_std_vint16;
typedef vec_op_std_v4int32 vec_op_std_vint32;
typedef vec_op_std_v2int64 vec_op_std_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 12
typedef vec_op_std_v3int32 vec_op_std_vint32;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 8
typedef vec_op_std_v2float32 vec_op_std_vfloat32;
typedef vec_op_std_v8int8 vec_op_std_vint8;
typedef vec_op_std_v4int16 vec_op_std_vint16;
typedef vec_op_std_v2int32 vec_op_std_vint32;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 6
typedef vec_op_std_v3int16 vec_op_std_vint16;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 4
typedef vec_op_std_v4int8 vec_op_std_vint8;
typedef vec_op_std_v2int16 vec_op_std_vint16;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 3
typedef vec_op_std_v3int8 vec_op_std_vint8;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 2
typedef vec_op_std_v2int8 vec_op_std_vint8;
#endif


#define VEC_OP_STD_FUNC(type, name) (_Generic(*(type*)0, \
    vec_op_std_v2float32: vec_op_std_##name##_v2f32, \
    vec_op_std_v3float32: vec_op_std_##name##_v3f32, \
    vec_op_std_v4float32: vec_op_std_##name##_v4f32, \
    vec_op_std_v8float32: vec_op_std_##name##_v8f32, \
    vec_op_std_v16float32: vec_op_std_##name##_v16f32, \
    \
    vec_op_std_v2float64: vec_op_std_##name##_v2f64, \
    vec_op_std_v3float64: vec_op_std_##name##_v3f64, \
    vec_op_std_v4float64: vec_op_std_##name##_v4f64, \
    vec_op_std_v8float64: vec_op_std_##name##_v8f64, \
    vec_op_std_v16float64: vec_op_std_##name##_v16f64, \
    \
    vec_op_std_v2int8: vec_op_std_##name##_v2i8, \
    vec_op_std_v3int8: vec_op_std_##name##_v3i8, \
    vec_op_std_v4int8: vec_op_std_##name##_v4i8, \
    vec_op_std_v8int8: vec_op_std_##name##_v8i8, \
    vec_op_std_v16int8: vec_op_std_##name##_v16i8, \
    \
    vec_op_std_v2int16: vec_op_std_##name##_v2i16, \
    vec_op_std_v3int16: vec_op_std_##name##_v3i16, \
    vec_op_std_v4int16: vec_op_std_##name##_v4i16, \
    vec_op_std_v8int16: vec_op_std_##name##_v8i16, \
    vec_op_std_v16int16: vec_op_std_##name##_v16i16, \
    \
    vec_op_std_v2int32: vec_op_std_##name##_v2i32, \
    vec_op_std_v3int32: vec_op_std_##name##_v3i32, \
    vec_op_std_v4int32: vec_op_std_##name##_v4i32, \
    vec_op_std_v8int32: vec_op_std_##name##_v8i32, \
    vec_op_std_v16int32: vec_op_std_##name##_v16i32, \
    \
    vec_op_std_v2int64: vec_op_std_##name##_v2i64, \
    vec_op_std_v3int64: vec_op_std_##name##_v3i64, \
    vec_op_std_v4int64: vec_op_std_##name##_v4i64, \
    vec_op_std_v8int64: vec_op_std_##name##_v8i64, \
    vec_op_std_v16int64: vec_op_std_##name##_v16i64 \
))


//vector make
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_make_v2f32(float v0, float v1)
{
    return (vec_op_std_v2float32){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_make_v3f32(float v0, float v1, float v2)
{
    return (vec_op_std_v3float32){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_make_v4f32(float v0, float v1, float v2, float v3)
{
    return (vec_op_std_v4float32){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_make_v8f32(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7)
{
    return (vec_op_std_v8float32){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_make_v16f32(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15)
{
    return (vec_op_std_v16float32){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_make_v2f64(double v0, double v1)
{
    return (vec_op_std_v2float64){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_make_v3f64(double v0, double v1, double v2)
{
    return (vec_op_std_v3float64){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_make_v4f64(double v0, double v1, double v2, double v3)
{
    return (vec_op_std_v4float64){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_make_v8f64(double v0, double v1, double v2, double v3, double v4, double v5, double v6, double v7)
{
    return (vec_op_std_v8float64){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_make_v16f64(double v0, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9, double v10, double v11, double v12, double v13, double v14, double v15)
{
    return (vec_op_std_v16float64){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_make_v2i8(int8_t v0, int8_t v1)
{
    return (vec_op_std_v2int8){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_make_v3i8(int8_t v0, int8_t v1, int8_t v2)
{
    return (vec_op_std_v3int8){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_make_v4i8(int8_t v0, int8_t v1, int8_t v2, int8_t v3)
{
    return (vec_op_std_v4int8){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_make_v8i8(int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5, int8_t v6, int8_t v7)
{
    return (vec_op_std_v8int8){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_make_v16i8(int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5, int8_t v6, int8_t v7, int8_t v8, int8_t v9, int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15)
{
    return (vec_op_std_v16int8){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_make_v2i16(int16_t v0, int16_t v1)
{
    return (vec_op_std_v2int16){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_make_v3i16(int16_t v0, int16_t v1, int16_t v2)
{
    return (vec_op_std_v3int16){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_make_v4i16(int16_t v0, int16_t v1, int16_t v2, int16_t v3)
{
    return (vec_op_std_v4int16){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_make_v8i16(int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4, int16_t v5, int16_t v6, int16_t v7)
{
    return (vec_op_std_v8int16){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_make_v16i16(int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4, int16_t v5, int16_t v6, int16_t v7, int16_t v8, int16_t v9, int16_t v10, int16_t v11, int16_t v12, int16_t v13, int16_t v14, int16_t v15)
{
    return (vec_op_std_v16int16){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_make_v2i32(int32_t v0, int32_t v1)
{
    return (vec_op_std_v2int32){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_make_v3i32(int32_t v0, int32_t v1, int32_t v2)
{
    return (vec_op_std_v3int32){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_make_v4i32(int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
    return (vec_op_std_v4int32){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_make_v8i32(int32_t v0, int32_t v1, int32_t v2, int32_t v3, int32_t v4, int32_t v5, int32_t v6, int32_t v7)
{
    return (vec_op_std_v8int32){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_make_v16i32(int32_t v0, int32_t v1, int32_t v2, int32_t v3, int32_t v4, int32_t v5, int32_t v6, int32_t v7, int32_t v8, int32_t v9, int32_t v10, int32_t v11, int32_t v12, int32_t v13, int32_t v14, int32_t v15)
{
    return (vec_op_std_v16int32){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_make_v2i64(int64_t v0, int64_t v1)
{
    return (vec_op_std_v2int64){ v0, v1 };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_make_v3i64(int64_t v0, int64_t v1, int64_t v2)
{
    return (vec_op_std_v3int64){ v0, v1, v2 };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_make_v4i64(int64_t v0, int64_t v1, int64_t v2, int64_t v3)
{
    return (vec_op_std_v4int64){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_make_v8i64(int64_t v0, int64_t v1, int64_t v2, int64_t v3, int64_t v4, int64_t v5, int64_t v6, int64_t v7)
{
    return (vec_op_std_v8int64){
        v0, v1, v2, v3,
        v4, v5, v6, v7
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_make_v16i64(int64_t v0, int64_t v1, int64_t v2, int64_t v3, int64_t v4, int64_t v5, int64_t v6, int64_t v7, int64_t v8, int64_t v9, int64_t v10, int64_t v11, int64_t v12, int64_t v13, int64_t v14, int64_t v15)
{
    return (vec_op_std_v16int64){
        v0, v1, v2, v3,
        v4, v5, v6, v7,
        v8, v9, v10, v11,
        v12, v13, v14, v15
    };
}

//vector fill
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_fill_v2f32(float v0)
{
    return vec_op_std_make_v2f32(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_fill_v3f32(float v0)
{
    return vec_op_std_make_v3f32(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_fill_v4f32(float v0)
{
    return vec_op_std_make_v4f32(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_fill_v8f32(float v0)
{
    return vec_op_std_make_v8f32(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_fill_v16f32(float v0)
{
    return vec_op_std_make_v16f32(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_fill_v2f64(double v0)
{
    return vec_op_std_make_v2f64(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_fill_v3f64(double v0)
{
    return vec_op_std_make_v3f64(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_fill_v4f64(double v0)
{
    return vec_op_std_make_v4f64(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_fill_v8f64(double v0)
{
    return vec_op_std_make_v8f64(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_fill_v16f64(double v0)
{
    return vec_op_std_make_v16f64(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_fill_v2i8(int8_t v0)
{
    return vec_op_std_make_v2i8(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_fill_v3i8(int8_t v0)
{
    return vec_op_std_make_v3i8(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_fill_v4i8(int8_t v0)
{
    return vec_op_std_make_v4i8(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_fill_v8i8(int8_t v0)
{
    return vec_op_std_make_v8i8(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_fill_v16i8(int8_t v0)
{
    return vec_op_std_make_v16i8(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_fill_v2i16(int16_t v0)
{
    return vec_op_std_make_v2i16(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_fill_v3i16(int16_t v0)
{
    return vec_op_std_make_v3i16(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_fill_v4i16(int16_t v0)
{
    return vec_op_std_make_v4i16(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_fill_v8i16(int16_t v0)
{
    return vec_op_std_make_v8i16(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_fill_v16i16(int16_t v0)
{
    return vec_op_std_make_v16i16(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_fill_v2i32(int32_t v0)
{
    return vec_op_std_make_v2i32(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_fill_v3i32(int32_t v0)
{
    return vec_op_std_make_v3i32(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_fill_v4i32(int32_t v0)
{
    return vec_op_std_make_v4i32(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_fill_v8i32(int32_t v0)
{
    return vec_op_std_make_v8i32(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_fill_v16i32(int32_t v0)
{
    return vec_op_std_make_v16i32(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_fill_v2i64(int64_t v0)
{
    return vec_op_std_make_v2i64(v0, v0);
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_fill_v3i64(int64_t v0)
{
    return vec_op_std_make_v3i64(v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_fill_v4i64(int64_t v0)
{
    return vec_op_std_make_v4i64(v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_fill_v8i64(int64_t v0)
{
    return vec_op_std_make_v8i64(v0, v0, v0, v0, v0, v0, v0, v0);
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_fill_v16i64(int64_t v0)
{
    return vec_op_std_make_v16i64(v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0, v0);
}

//vector get
static VEC_OP_INLINE float vec_op_std_get_v2f32(vec_op_std_v2float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE float vec_op_std_get_v3f32(vec_op_std_v3float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE float vec_op_std_get_v4f32(vec_op_std_v4float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE float vec_op_std_get_v8f32(vec_op_std_v8float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE float vec_op_std_get_v16f32(vec_op_std_v16float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE double vec_op_std_get_v2f64(vec_op_std_v2float64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE double vec_op_std_get_v3f64(vec_op_std_v3float64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE double vec_op_std_get_v4f64(vec_op_std_v4float64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE double vec_op_std_get_v8f64(vec_op_std_v8float64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE double vec_op_std_get_v16f64(vec_op_std_v16float64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int8_t vec_op_std_get_v2i8(vec_op_std_v2int8 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int8_t vec_op_std_get_v3i8(vec_op_std_v3int8 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int8_t vec_op_std_get_v4i8(vec_op_std_v4int8 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int8_t vec_op_std_get_v8i8(vec_op_std_v8int8 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int8_t vec_op_std_get_v16i8(vec_op_std_v16int8 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int16_t vec_op_std_get_v2i16(vec_op_std_v2int16 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int16_t vec_op_std_get_v3i16(vec_op_std_v3int16 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int16_t vec_op_std_get_v4i16(vec_op_std_v4int16 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int16_t vec_op_std_get_v8i16(vec_op_std_v8int16 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int16_t vec_op_std_get_v16i16(vec_op_std_v16int16 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int32_t vec_op_std_get_v2i32(vec_op_std_v2int32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int32_t vec_op_std_get_v3i32(vec_op_std_v3int32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int32_t vec_op_std_get_v4i32(vec_op_std_v4int32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int32_t vec_op_std_get_v8i32(vec_op_std_v8int32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int32_t vec_op_std_get_v16i32(vec_op_std_v16int32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int64_t vec_op_std_get_v2i64(vec_op_std_v2int64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int64_t vec_op_std_get_v3i64(vec_op_std_v3int64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int64_t vec_op_std_get_v4i64(vec_op_std_v4int64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int64_t vec_op_std_get_v8i64(vec_op_std_v8int64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    return v.v[Index];
}

static VEC_OP_INLINE int64_t vec_op_std_get_v16i64(vec_op_std_v16int64 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    return v.v[Index];
}

//vector set
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_set_v2f32(vec_op_std_v2float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_set_v3f32(vec_op_std_v3float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_set_v4f32(vec_op_std_v4float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_set_v8f32(vec_op_std_v8float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_set_v16f32(vec_op_std_v16float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_set_v2f64(vec_op_std_v2float64 v, size_t Index, double Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_set_v3f64(vec_op_std_v3float64 v, size_t Index, double Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_set_v4f64(vec_op_std_v4float64 v, size_t Index, double Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_set_v8f64(vec_op_std_v8float64 v, size_t Index, double Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_set_v16f64(vec_op_std_v16float64 v, size_t Index, double Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_set_v2i8(vec_op_std_v2int8 v, size_t Index, int8_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_set_v3i8(vec_op_std_v3int8 v, size_t Index, int8_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_set_v4i8(vec_op_std_v4int8 v, size_t Index, int8_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_set_v8i8(vec_op_std_v8int8 v, size_t Index, int8_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_set_v16i8(vec_op_std_v16int8 v, size_t Index, int8_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_set_v2i16(vec_op_std_v2int16 v, size_t Index, int16_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_set_v3i16(vec_op_std_v3int16 v, size_t Index, int16_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_set_v4i16(vec_op_std_v4int16 v, size_t Index, int16_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_set_v8i16(vec_op_std_v8int16 v, size_t Index, int16_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_set_v16i16(vec_op_std_v16int16 v, size_t Index, int16_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_set_v2i32(vec_op_std_v2int32 v, size_t Index, int32_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_set_v3i32(vec_op_std_v3int32 v, size_t Index, int32_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_set_v4i32(vec_op_std_v4int32 v, size_t Index, int32_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_set_v8i32(vec_op_std_v8int32 v, size_t Index, int32_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_set_v16i32(vec_op_std_v16int32 v, size_t Index, int32_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_set_v2i64(vec_op_std_v2int64 v, size_t Index, int64_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 2);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_set_v3i64(vec_op_std_v3int64 v, size_t Index, int64_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 3);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_set_v4i64(vec_op_std_v4int64 v, size_t Index, int64_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_set_v8i64(vec_op_std_v8int64 v, size_t Index, int64_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 8);
#endif
    v.v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_set_v16i64(vec_op_std_v16int64 v, size_t Index, int64_t Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 16);
#endif
    v.v[Index] = Value;
    return v;
}

//vector swizzle
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_swizzle_v2f32(vec_op_std_v2float32 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2float32){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_swizzle_v3f32(vec_op_std_v3float32 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3float32){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_swizzle_v4f32(vec_op_std_v4float32 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4float32){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_swizzle_v8f32(vec_op_std_v8float32 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8float32){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_swizzle_v16f32(vec_op_std_v16float32 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16float32){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_swizzle_v2f64(vec_op_std_v2float64 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2float64){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_swizzle_v3f64(vec_op_std_v3float64 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3float64){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_swizzle_v4f64(vec_op_std_v4float64 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4float64){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_swizzle_v8f64(vec_op_std_v8float64 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8float64){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_swizzle_v16f64(vec_op_std_v16float64 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16float64){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_swizzle_v2i8(vec_op_std_v2int8 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2int8){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_swizzle_v3i8(vec_op_std_v3int8 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3int8){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_swizzle_v4i8(vec_op_std_v4int8 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4int8){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_swizzle_v8i8(vec_op_std_v8int8 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8int8){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_swizzle_v16i8(vec_op_std_v16int8 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16int8){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_swizzle_v2i16(vec_op_std_v2int16 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2int16){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_swizzle_v3i16(vec_op_std_v3int16 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3int16){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_swizzle_v4i16(vec_op_std_v4int16 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4int16){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_swizzle_v8i16(vec_op_std_v8int16 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8int16){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_swizzle_v16i16(vec_op_std_v16int16 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16int16){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_swizzle_v2i32(vec_op_std_v2int32 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2int32){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_swizzle_v3i32(vec_op_std_v3int32 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3int32){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_swizzle_v4i32(vec_op_std_v4int32 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4int32){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_swizzle_v8i32(vec_op_std_v8int32 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8int32){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_swizzle_v16i32(vec_op_std_v16int32 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16int32){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_swizzle_v2i64(vec_op_std_v2int64 a, size_t v0, size_t v1)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 2 && v1 < 2);
#endif
    return (vec_op_std_v2int64){ a.v[v0], a.v[v1] };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_swizzle_v3i64(vec_op_std_v3int64 a, size_t v0, size_t v1, size_t v2)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 3 && v1 < 3 && v2 < 3);
#endif
    return (vec_op_std_v3int64){ a.v[v0], a.v[v1], a.v[v2] };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_swizzle_v4i64(vec_op_std_v4int64 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_std_v4int64){ a.v[v0], a.v[v1], a.v[v2], a.v[v3] };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_swizzle_v8i64(vec_op_std_v8int64 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 8 && v1 < 8 && v2 < 8 && v3 < 8 && v4 < 8 && v5 < 8 && v6 < 8 && v7 < 8);
#endif
    return (vec_op_std_v8int64){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_swizzle_v16i64(vec_op_std_v16int64 a, size_t v0, size_t v1, size_t v2, size_t v3, size_t v4, size_t v5, size_t v6, size_t v7, size_t v8, size_t v9, size_t v10, size_t v11, size_t v12, size_t v13, size_t v14, size_t v15)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 16 && v1 < 16 && v2 < 16 && v3 < 16 && v4 < 16 && v5 < 16 && v6 < 16 && v7 < 16 && v8 < 16 && v9 < 16 && v10 < 16 && v11 < 16 && v12 < 16 && v13 < 16 && v14 < 16 && v15 < 16);
#endif
    return (vec_op_std_v16int64){
        a.v[v0], a.v[v1], a.v[v2], a.v[v3],
        a.v[v4], a.v[v5], a.v[v6], a.v[v7],
        a.v[v8], a.v[v9], a.v[v10], a.v[v11],
        a.v[v12], a.v[v13], a.v[v14], a.v[v15]
    };
}

//vector addition
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_add_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_add_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_add_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_add_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_add_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_add_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_add_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_add_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_add_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_add_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_add_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_add_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_add_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_add_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_add_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_add_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_add_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_add_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_add_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_add_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_add_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_add_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_add_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_add_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_add_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_add_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x + b.x, a.y + b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_add_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x + b.x, a.y + b.y, a.z + b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_add_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_add_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_add_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3],
        a.v[4] + b.v[4], a.v[5] + b.v[5], a.v[6] + b.v[6], a.v[7] + b.v[7],
        a.v[8] + b.v[8], a.v[9] + b.v[9], a.v[10] + b.v[10], a.v[11] + b.v[11],
        a.v[12] + b.v[12], a.v[13] + b.v[13], a.v[14] + b.v[14], a.v[15] + b.v[15]
    };
}

//vector subtraction
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_sub_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_sub_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_sub_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_sub_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_sub_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_sub_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_sub_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_sub_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_sub_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_sub_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_sub_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_sub_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_sub_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_sub_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_sub_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_sub_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_sub_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_sub_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_sub_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_sub_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_sub_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_sub_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_sub_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_sub_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_sub_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_sub_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x - b.x, a.y - b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_sub_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x - b.x, a.y - b.y, a.z - b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_sub_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_sub_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_sub_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2], a.v[3] - b.v[3],
        a.v[4] - b.v[4], a.v[5] - b.v[5], a.v[6] - b.v[6], a.v[7] - b.v[7],
        a.v[8] - b.v[8], a.v[9] - b.v[9], a.v[10] - b.v[10], a.v[11] - b.v[11],
        a.v[12] - b.v[12], a.v[13] - b.v[13], a.v[14] - b.v[14], a.v[15] - b.v[15]
    };
}

//vector multiply
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_mul_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_mul_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_mul_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_mul_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_mul_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_mul_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_mul_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_mul_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_mul_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_mul_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_mul_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_mul_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_mul_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_mul_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_mul_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_mul_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_mul_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_mul_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_mul_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_mul_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_mul_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_mul_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_mul_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_mul_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_mul_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_mul_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x * b.x, a.y * b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_mul_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x * b.x, a.y * b.y, a.z * b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_mul_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_mul_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_mul_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3],
        a.v[4] * b.v[4], a.v[5] * b.v[5], a.v[6] * b.v[6], a.v[7] * b.v[7],
        a.v[8] * b.v[8], a.v[9] * b.v[9], a.v[10] * b.v[10], a.v[11] * b.v[11],
        a.v[12] * b.v[12], a.v[13] * b.v[13], a.v[14] * b.v[14], a.v[15] * b.v[15]
    };
}

//vector divide
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_div_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_div_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_div_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_div_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_div_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_div_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_div_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_div_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_div_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_div_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_div_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_div_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_div_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_div_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_div_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_div_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_div_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_div_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_div_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_div_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_div_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_div_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_div_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_div_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_div_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_div_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x / b.x, a.y / b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_div_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x / b.x, a.y / b.y, a.z / b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_div_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_div_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_div_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] / b.v[0], a.v[1] / b.v[1], a.v[2] / b.v[2], a.v[3] / b.v[3],
        a.v[4] / b.v[4], a.v[5] / b.v[5], a.v[6] / b.v[6], a.v[7] / b.v[7],
        a.v[8] / b.v[8], a.v[9] / b.v[9], a.v[10] / b.v[10], a.v[11] / b.v[11],
        a.v[12] / b.v[12], a.v[13] / b.v[13], a.v[14] / b.v[14], a.v[15] / b.v[15]
    };
}

//vector reciprocal
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_recip_v2f32(vec_op_std_v2float32 a)
{
    return (vec_op_std_v2float32){ 1.0f / a.x, 1.0f / a.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_recip_v3f32(vec_op_std_v3float32 a)
{
    return (vec_op_std_v3float32){ 1.0f / a.x, 1.0f / a.y, 1.0f / a.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_recip_v4f32(vec_op_std_v4float32 a)
{
    return (vec_op_std_v4float32){ 1.0f / a.x, 1.0f / a.y, 1.0f / a.z, 1.0f / a.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_recip_v8f32(vec_op_std_v8float32 a)
{
    return (vec_op_std_v8float32){
        1.0f / a.v[0], 1.0f / a.v[1], 1.0f / a.v[2], 1.0f / a.v[3],
        1.0f / a.v[4], 1.0f / a.v[5], 1.0f / a.v[6], 1.0f / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_recip_v16f32(vec_op_std_v16float32 a)
{
    return (vec_op_std_v16float32){
        1.0f / a.v[0], 1.0f / a.v[1], 1.0f / a.v[2], 1.0f / a.v[3],
        1.0f / a.v[4], 1.0f / a.v[5], 1.0f / a.v[6], 1.0f / a.v[7],
        1.0f / a.v[8], 1.0f / a.v[9], 1.0f / a.v[10], 1.0f / a.v[11],
        1.0f / a.v[12], 1.0f / a.v[13], 1.0f / a.v[14], 1.0f / a.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_recip_v2f64(vec_op_std_v2float64 a)
{
    return (vec_op_std_v2float64){ 1.0 / a.x, 1.0 / a.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_recip_v3f64(vec_op_std_v3float64 a)
{
    return (vec_op_std_v3float64){ 1.0 / a.x, 1.0 / a.y, 1.0 / a.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_recip_v4f64(vec_op_std_v4float64 a)
{
    return (vec_op_std_v4float64){ 1.0 / a.x, 1.0 / a.y, 1.0 / a.z, 1.0 / a.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_recip_v8f64(vec_op_std_v8float64 a)
{
    return (vec_op_std_v8float64){
        1.0 / a.v[0], 1.0 / a.v[1], 1.0 / a.v[2], 1.0 / a.v[3],
        1.0 / a.v[4], 1.0 / a.v[5], 1.0 / a.v[6], 1.0 / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_recip_v16f64(vec_op_std_v16float64 a)
{
    return (vec_op_std_v16float64){
        1.0 / a.v[0], 1.0 / a.v[1], 1.0 / a.v[2], 1.0 / a.v[3],
        1.0 / a.v[4], 1.0 / a.v[5], 1.0 / a.v[6], 1.0 / a.v[7],
        1.0 / a.v[8], 1.0 / a.v[9], 1.0 / a.v[10], 1.0 / a.v[11],
        1.0 / a.v[12], 1.0 / a.v[13], 1.0 / a.v[14], 1.0 / a.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_recip_v2i8(vec_op_std_v2int8 a)
{
    return (vec_op_std_v2int8){ 1 / a.x, 1 / a.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_recip_v3i8(vec_op_std_v3int8 a)
{
    return (vec_op_std_v3int8){ 1 / a.x, 1 / a.y, 1 / a.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_recip_v4i8(vec_op_std_v4int8 a)
{
    return (vec_op_std_v4int8){ 1 / a.x, 1 / a.y, 1 / a.z, 1 / a.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_recip_v8i8(vec_op_std_v8int8 a)
{
    return (vec_op_std_v8int8){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_recip_v16i8(vec_op_std_v16int8 a)
{
    return (vec_op_std_v16int8){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7],
        1 / a.v[8], 1 / a.v[9], 1 / a.v[10], 1 / a.v[11],
        1 / a.v[12], 1 / a.v[13], 1 / a.v[14], 1 / a.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_recip_v2i16(vec_op_std_v2int16 a)
{
    return (vec_op_std_v2int16){ 1 / a.x, 1 / a.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_recip_v3i16(vec_op_std_v3int16 a)
{
    return (vec_op_std_v3int16){ 1 / a.x, 1 / a.y, 1 / a.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_recip_v4i16(vec_op_std_v4int16 a)
{
    return (vec_op_std_v4int16){ 1 / a.x, 1 / a.y, 1 / a.z, 1 / a.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_recip_v8i16(vec_op_std_v8int16 a)
{
    return (vec_op_std_v8int16){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_recip_v16i16(vec_op_std_v16int16 a)
{
    return (vec_op_std_v16int16){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7],
        1 / a.v[8], 1 / a.v[9], 1 / a.v[10], 1 / a.v[11],
        1 / a.v[12], 1 / a.v[13], 1 / a.v[14], 1 / a.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_recip_v2i32(vec_op_std_v2int32 a)
{
    return (vec_op_std_v2int32){ 1 / a.x, 1 / a.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_recip_v3i32(vec_op_std_v3int32 a)
{
    return (vec_op_std_v3int32){ 1 / a.x, 1 / a.y, 1 / a.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_recip_v4i32(vec_op_std_v4int32 a)
{
    return (vec_op_std_v4int32){ 1 / a.x, 1 / a.y, 1 / a.z, 1 / a.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_recip_v8i32(vec_op_std_v8int32 a)
{
    return (vec_op_std_v8int32){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_recip_v16i32(vec_op_std_v16int32 a)
{
    return (vec_op_std_v16int32){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7],
        1 / a.v[8], 1 / a.v[9], 1 / a.v[10], 1 / a.v[11],
        1 / a.v[12], 1 / a.v[13], 1 / a.v[14], 1 / a.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_recip_v2i64(vec_op_std_v2int64 a)
{
    return (vec_op_std_v2int64){ 1 / a.x, 1 / a.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_recip_v3i64(vec_op_std_v3int64 a)
{
    return (vec_op_std_v3int64){ 1 / a.x, 1 / a.y, 1 / a.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_recip_v4i64(vec_op_std_v4int64 a)
{
    return (vec_op_std_v4int64){ 1 / a.x, 1 / a.y, 1 / a.z, 1 / a.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_recip_v8i64(vec_op_std_v8int64 a)
{
    return (vec_op_std_v8int64){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_recip_v16i64(vec_op_std_v16int64 a)
{
    return (vec_op_std_v16int64){
        1 / a.v[0], 1 / a.v[1], 1 / a.v[2], 1 / a.v[3],
        1 / a.v[4], 1 / a.v[5], 1 / a.v[6], 1 / a.v[7],
        1 / a.v[8], 1 / a.v[9], 1 / a.v[10], 1 / a.v[11],
        1 / a.v[12], 1 / a.v[13], 1 / a.v[14], 1 / a.v[15]
    };
}

//vector square root
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_sqrt_v2f32(vec_op_std_v2float32 a)
{
    return (vec_op_std_v2float32){ sqrtf(a.x), sqrtf(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_sqrt_v3f32(vec_op_std_v3float32 a)
{
    return (vec_op_std_v3float32){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_sqrt_v4f32(vec_op_std_v4float32 a)
{
    return (vec_op_std_v4float32){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z), sqrtf(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_sqrt_v8f32(vec_op_std_v8float32 a)
{
    return (vec_op_std_v8float32){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_sqrt_v16f32(vec_op_std_v16float32 a)
{
    return (vec_op_std_v16float32){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7]),
        sqrtf(a.v[8]), sqrtf(a.v[9]), sqrtf(a.v[10]), sqrtf(a.v[11]),
        sqrtf(a.v[12]), sqrtf(a.v[13]), sqrtf(a.v[14]), sqrtf(a.v[15])
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_sqrt_v2f64(vec_op_std_v2float64 a)
{
    return (vec_op_std_v2float64){ sqrt(a.x), sqrt(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_sqrt_v3f64(vec_op_std_v3float64 a)
{
    return (vec_op_std_v3float64){ sqrt(a.x), sqrt(a.y), sqrt(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_sqrt_v4f64(vec_op_std_v4float64 a)
{
    return (vec_op_std_v4float64){ sqrt(a.x), sqrt(a.y), sqrt(a.z), sqrt(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_sqrt_v8f64(vec_op_std_v8float64 a)
{
    return (vec_op_std_v8float64){
        sqrt(a.v[0]), sqrt(a.v[1]), sqrt(a.v[2]), sqrt(a.v[3]),
        sqrt(a.v[4]), sqrt(a.v[5]), sqrt(a.v[6]), sqrt(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_sqrt_v16f64(vec_op_std_v16float64 a)
{
    return (vec_op_std_v16float64){
        sqrt(a.v[0]), sqrt(a.v[1]), sqrt(a.v[2]), sqrt(a.v[3]),
        sqrt(a.v[4]), sqrt(a.v[5]), sqrt(a.v[6]), sqrt(a.v[7]),
        sqrt(a.v[8]), sqrt(a.v[9]), sqrt(a.v[10]), sqrt(a.v[11]),
        sqrt(a.v[12]), sqrt(a.v[13]), sqrt(a.v[14]), sqrt(a.v[15])
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_sqrt_v2i8(vec_op_std_v2int8 a)
{
    return (vec_op_std_v2int8){ sqrtf(a.x), sqrtf(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_sqrt_v3i8(vec_op_std_v3int8 a)
{
    return (vec_op_std_v3int8){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_sqrt_v4i8(vec_op_std_v4int8 a)
{
    return (vec_op_std_v4int8){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z), sqrtf(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_sqrt_v8i8(vec_op_std_v8int8 a)
{
    return (vec_op_std_v8int8){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_sqrt_v16i8(vec_op_std_v16int8 a)
{
    return (vec_op_std_v16int8){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7]),
        sqrtf(a.v[8]), sqrtf(a.v[9]), sqrtf(a.v[10]), sqrtf(a.v[11]),
        sqrtf(a.v[12]), sqrtf(a.v[13]), sqrtf(a.v[14]), sqrtf(a.v[15])
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_sqrt_v2i16(vec_op_std_v2int16 a)
{
    return (vec_op_std_v2int16){ sqrtf(a.x), sqrtf(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_sqrt_v3i16(vec_op_std_v3int16 a)
{
    return (vec_op_std_v3int16){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_sqrt_v4i16(vec_op_std_v4int16 a)
{
    return (vec_op_std_v4int16){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z), sqrtf(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_sqrt_v8i16(vec_op_std_v8int16 a)
{
    return (vec_op_std_v8int16){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_sqrt_v16i16(vec_op_std_v16int16 a)
{
    return (vec_op_std_v16int16){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7]),
        sqrtf(a.v[8]), sqrtf(a.v[9]), sqrtf(a.v[10]), sqrtf(a.v[11]),
        sqrtf(a.v[12]), sqrtf(a.v[13]), sqrtf(a.v[14]), sqrtf(a.v[15])
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_sqrt_v2i32(vec_op_std_v2int32 a)
{
    return (vec_op_std_v2int32){ sqrtf(a.x), sqrtf(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_sqrt_v3i32(vec_op_std_v3int32 a)
{
    return (vec_op_std_v3int32){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_sqrt_v4i32(vec_op_std_v4int32 a)
{
    return (vec_op_std_v4int32){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z), sqrtf(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_sqrt_v8i32(vec_op_std_v8int32 a)
{
    return (vec_op_std_v8int32){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_sqrt_v16i32(vec_op_std_v16int32 a)
{
    return (vec_op_std_v16int32){
        sqrtf(a.v[0]), sqrtf(a.v[1]), sqrtf(a.v[2]), sqrtf(a.v[3]),
        sqrtf(a.v[4]), sqrtf(a.v[5]), sqrtf(a.v[6]), sqrtf(a.v[7]),
        sqrtf(a.v[8]), sqrtf(a.v[9]), sqrtf(a.v[10]), sqrtf(a.v[11]),
        sqrtf(a.v[12]), sqrtf(a.v[13]), sqrtf(a.v[14]), sqrtf(a.v[15])
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_sqrt_v2i64(vec_op_std_v2int64 a)
{
    return (vec_op_std_v2int64){ sqrt(a.x), sqrt(a.y) };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_sqrt_v3i64(vec_op_std_v3int64 a)
{
    return (vec_op_std_v3int64){ sqrt(a.x), sqrt(a.y), sqrt(a.z) };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_sqrt_v4i64(vec_op_std_v4int64 a)
{
    return (vec_op_std_v4int64){ sqrt(a.x), sqrt(a.y), sqrt(a.z), sqrt(a.w) };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_sqrt_v8i64(vec_op_std_v8int64 a)
{
    return (vec_op_std_v8int64){
        sqrt(a.v[0]), sqrt(a.v[1]), sqrt(a.v[2]), sqrt(a.v[3]),
        sqrt(a.v[4]), sqrt(a.v[5]), sqrt(a.v[6]), sqrt(a.v[7])
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_sqrt_v16i64(vec_op_std_v16int64 a)
{
    return (vec_op_std_v16int64){
        sqrt(a.v[0]), sqrt(a.v[1]), sqrt(a.v[2]), sqrt(a.v[3]),
        sqrt(a.v[4]), sqrt(a.v[5]), sqrt(a.v[6]), sqrt(a.v[7]),
        sqrt(a.v[8]), sqrt(a.v[9]), sqrt(a.v[10]), sqrt(a.v[11]),
        sqrt(a.v[12]), sqrt(a.v[13]), sqrt(a.v[14]), sqrt(a.v[15])
    };
}

//vector reciprocal square root
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_rsqrt_v2f32(vec_op_std_v2float32 a)
{
    return vec_op_std_recip_v2f32(vec_op_std_sqrt_v2f32(a));
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_rsqrt_v3f32(vec_op_std_v3float32 a)
{
    return vec_op_std_recip_v3f32(vec_op_std_sqrt_v3f32(a));
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_rsqrt_v4f32(vec_op_std_v4float32 a)
{
    return vec_op_std_recip_v4f32(vec_op_std_sqrt_v4f32(a));
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_rsqrt_v8f32(vec_op_std_v8float32 a)
{
    return vec_op_std_recip_v8f32(vec_op_std_sqrt_v8f32(a));
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_rsqrt_v16f32(vec_op_std_v16float32 a)
{
    return vec_op_std_recip_v16f32(vec_op_std_sqrt_v16f32(a));
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_rsqrt_v2f64(vec_op_std_v2float64 a)
{
    return vec_op_std_recip_v2f64(vec_op_std_sqrt_v2f64(a));
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_rsqrt_v3f64(vec_op_std_v3float64 a)
{
    return vec_op_std_recip_v3f64(vec_op_std_sqrt_v3f64(a));
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_rsqrt_v4f64(vec_op_std_v4float64 a)
{
    return vec_op_std_recip_v4f64(vec_op_std_sqrt_v4f64(a));
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_rsqrt_v8f64(vec_op_std_v8float64 a)
{
    return vec_op_std_recip_v8f64(vec_op_std_sqrt_v8f64(a));
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_rsqrt_v16f64(vec_op_std_v16float64 a)
{
    return vec_op_std_recip_v16f64(vec_op_std_sqrt_v16f64(a));
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_rsqrt_v2i8(vec_op_std_v2int8 a)
{
    return vec_op_std_recip_v2i8(vec_op_std_sqrt_v2i8(a));
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_rsqrt_v3i8(vec_op_std_v3int8 a)
{
    return vec_op_std_recip_v3i8(vec_op_std_sqrt_v3i8(a));
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_rsqrt_v4i8(vec_op_std_v4int8 a)
{
    return vec_op_std_recip_v4i8(vec_op_std_sqrt_v4i8(a));
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_rsqrt_v8i8(vec_op_std_v8int8 a)
{
    return vec_op_std_recip_v8i8(vec_op_std_sqrt_v8i8(a));
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_rsqrt_v16i8(vec_op_std_v16int8 a)
{
    return vec_op_std_recip_v16i8(vec_op_std_sqrt_v16i8(a));
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_rsqrt_v2i16(vec_op_std_v2int16 a)
{
    return vec_op_std_recip_v2i16(vec_op_std_sqrt_v2i16(a));
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_rsqrt_v3i16(vec_op_std_v3int16 a)
{
    return vec_op_std_recip_v3i16(vec_op_std_sqrt_v3i16(a));
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_rsqrt_v4i16(vec_op_std_v4int16 a)
{
    return vec_op_std_recip_v4i16(vec_op_std_sqrt_v4i16(a));
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_rsqrt_v8i16(vec_op_std_v8int16 a)
{
    return vec_op_std_recip_v8i16(vec_op_std_sqrt_v8i16(a));
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_rsqrt_v16i16(vec_op_std_v16int16 a)
{
    return vec_op_std_recip_v16i16(vec_op_std_sqrt_v16i16(a));
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_rsqrt_v2i32(vec_op_std_v2int32 a)
{
    return vec_op_std_recip_v2i32(vec_op_std_sqrt_v2i32(a));
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_rsqrt_v3i32(vec_op_std_v3int32 a)
{
    return vec_op_std_recip_v3i32(vec_op_std_sqrt_v3i32(a));
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_rsqrt_v4i32(vec_op_std_v4int32 a)
{
    return vec_op_std_recip_v4i32(vec_op_std_sqrt_v4i32(a));
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_rsqrt_v8i32(vec_op_std_v8int32 a)
{
    return vec_op_std_recip_v8i32(vec_op_std_sqrt_v8i32(a));
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_rsqrt_v16i32(vec_op_std_v16int32 a)
{
    return vec_op_std_recip_v16i32(vec_op_std_sqrt_v16i32(a));
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_rsqrt_v2i64(vec_op_std_v2int64 a)
{
    return vec_op_std_recip_v2i64(vec_op_std_sqrt_v2i64(a));
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_rsqrt_v3i64(vec_op_std_v3int64 a)
{
    return vec_op_std_recip_v3i64(vec_op_std_sqrt_v3i64(a));
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_rsqrt_v4i64(vec_op_std_v4int64 a)
{
    return vec_op_std_recip_v4i64(vec_op_std_sqrt_v4i64(a));
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_rsqrt_v8i64(vec_op_std_v8int64 a)
{
    return vec_op_std_recip_v8i64(vec_op_std_sqrt_v8i64(a));
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_rsqrt_v16i64(vec_op_std_v16int64 a)
{
    return vec_op_std_recip_v16i64(vec_op_std_sqrt_v16i64(a));
}

//vector minima
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_min_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_min_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_min_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_min_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_min_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_min_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_min_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_min_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_min_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_min_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_min_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_min_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_min_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_min_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_min_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_min_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_min_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_min_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_min_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_min_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_min_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_min_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_min_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_min_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_min_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_min_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_min_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_min_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_min_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_min_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] < b.v[0] ? a.v[0] : b.v[0], a.v[1] < b.v[1] ? a.v[1] : b.v[1], a.v[2] < b.v[2] ? a.v[2] : b.v[2], a.v[3] < b.v[3] ? a.v[3] : b.v[3],
        a.v[4] < b.v[4] ? a.v[4] : b.v[4], a.v[5] < b.v[5] ? a.v[5] : b.v[5], a.v[6] < b.v[6] ? a.v[6] : b.v[6], a.v[7] < b.v[7] ? a.v[7] : b.v[7],
        a.v[8] < b.v[8] ? a.v[8] : b.v[8], a.v[9] < b.v[9] ? a.v[9] : b.v[9], a.v[10] < b.v[10] ? a.v[10] : b.v[10], a.v[11] < b.v[11] ? a.v[11] : b.v[11],
        a.v[12] < b.v[12] ? a.v[12] : b.v[12], a.v[13] < b.v[13] ? a.v[13] : b.v[13], a.v[14] < b.v[14] ? a.v[14] : b.v[14], a.v[15] < b.v[15] ? a.v[15] : b.v[15]
    };
}

//vector maxima
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_max_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (vec_op_std_v2float32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_max_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (vec_op_std_v3float32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_max_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (vec_op_std_v4float32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_max_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return (vec_op_std_v8float32){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_max_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return (vec_op_std_v16float32){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_max_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (vec_op_std_v2float64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_max_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (vec_op_std_v3float64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_max_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (vec_op_std_v4float64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_max_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return (vec_op_std_v8float64){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_max_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return (vec_op_std_v16float64){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_max_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (vec_op_std_v2int8){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_max_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (vec_op_std_v3int8){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_max_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (vec_op_std_v4int8){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_max_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return (vec_op_std_v8int8){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_max_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return (vec_op_std_v16int8){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_max_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (vec_op_std_v2int16){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_max_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (vec_op_std_v3int16){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_max_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (vec_op_std_v4int16){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_max_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return (vec_op_std_v8int16){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_max_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return (vec_op_std_v16int16){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_max_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (vec_op_std_v2int32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_max_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (vec_op_std_v3int32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_max_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (vec_op_std_v4int32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_max_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return (vec_op_std_v8int32){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_max_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return (vec_op_std_v16int32){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_max_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (vec_op_std_v2int64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y };
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_max_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (vec_op_std_v3int64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z };
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_max_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (vec_op_std_v4int64){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_max_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return (vec_op_std_v8int64){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7]
    };
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_max_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return (vec_op_std_v16int64){
        a.v[0] > b.v[0] ? a.v[0] : b.v[0], a.v[1] > b.v[1] ? a.v[1] : b.v[1], a.v[2] > b.v[2] ? a.v[2] : b.v[2], a.v[3] > b.v[3] ? a.v[3] : b.v[3],
        a.v[4] > b.v[4] ? a.v[4] : b.v[4], a.v[5] > b.v[5] ? a.v[5] : b.v[5], a.v[6] > b.v[6] ? a.v[6] : b.v[6], a.v[7] > b.v[7] ? a.v[7] : b.v[7],
        a.v[8] > b.v[8] ? a.v[8] : b.v[8], a.v[9] > b.v[9] ? a.v[9] : b.v[9], a.v[10] > b.v[10] ? a.v[10] : b.v[10], a.v[11] > b.v[11] ? a.v[11] : b.v[11],
        a.v[12] > b.v[12] ? a.v[12] : b.v[12], a.v[13] > b.v[13] ? a.v[13] : b.v[13], a.v[14] > b.v[14] ? a.v[14] : b.v[14], a.v[15] > b.v[15] ? a.v[15] : b.v[15]
    };
}

//vector dot product -> scalar
static VEC_OP_INLINE float vec_op_std_dots_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE float vec_op_std_dots_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE float vec_op_std_dots_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE float vec_op_std_dots_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE float vec_op_std_dots_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

static VEC_OP_INLINE double vec_op_std_dots_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE double vec_op_std_dots_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE double vec_op_std_dots_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE double vec_op_std_dots_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE double vec_op_std_dots_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

static VEC_OP_INLINE int8_t vec_op_std_dots_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE int8_t vec_op_std_dots_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE int8_t vec_op_std_dots_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE int8_t vec_op_std_dots_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE int8_t vec_op_std_dots_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

static VEC_OP_INLINE int16_t vec_op_std_dots_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE int16_t vec_op_std_dots_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE int16_t vec_op_std_dots_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE int16_t vec_op_std_dots_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE int16_t vec_op_std_dots_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

static VEC_OP_INLINE int32_t vec_op_std_dots_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE int32_t vec_op_std_dots_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE int32_t vec_op_std_dots_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE int32_t vec_op_std_dots_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE int32_t vec_op_std_dots_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

static VEC_OP_INLINE int64_t vec_op_std_dots_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

static VEC_OP_INLINE int64_t vec_op_std_dots_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static VEC_OP_INLINE int64_t vec_op_std_dots_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static VEC_OP_INLINE int64_t vec_op_std_dots_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]);
}

static VEC_OP_INLINE int64_t vec_op_std_dots_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return  (a.v[0] * b.v[0]) + (a.v[1] * b.v[1]) + (a.v[2] * b.v[2]) + (a.v[3] * b.v[3]) +
    (a.v[4] * b.v[4]) + (a.v[5] * b.v[5]) + (a.v[6] * b.v[6]) + (a.v[7] * b.v[7]) +
    (a.v[8] * b.v[8]) + (a.v[9] * b.v[9]) + (a.v[10] * b.v[10]) + (a.v[11] * b.v[11]) +
    (a.v[12] * b.v[12]) + (a.v[13] * b.v[13]) + (a.v[14] * b.v[14]) + (a.v[15] * b.v[15]);
}

//vector dot product -> vector
static VEC_OP_INLINE vec_op_std_v2float32 vec_op_std_dot_v2f32(vec_op_std_v2float32 a, vec_op_std_v2float32 b)
{
    return vec_op_std_fill_v2f32(vec_op_std_dots_v2f32(a, b));
}

static VEC_OP_INLINE vec_op_std_v3float32 vec_op_std_dot_v3f32(vec_op_std_v3float32 a, vec_op_std_v3float32 b)
{
    return vec_op_std_fill_v3f32(vec_op_std_dots_v3f32(a, b));
}

static VEC_OP_INLINE vec_op_std_v4float32 vec_op_std_dot_v4f32(vec_op_std_v4float32 a, vec_op_std_v4float32 b)
{
    return vec_op_std_fill_v4f32(vec_op_std_dots_v4f32(a, b));
}

static VEC_OP_INLINE vec_op_std_v8float32 vec_op_std_dot_v8f32(vec_op_std_v8float32 a, vec_op_std_v8float32 b)
{
    return vec_op_std_fill_v8f32(vec_op_std_dots_v8f32(a, b));
}

static VEC_OP_INLINE vec_op_std_v16float32 vec_op_std_dot_v16f32(vec_op_std_v16float32 a, vec_op_std_v16float32 b)
{
    return vec_op_std_fill_v16f32(vec_op_std_dots_v16f32(a, b));
}

static VEC_OP_INLINE vec_op_std_v2float64 vec_op_std_dot_v2f64(vec_op_std_v2float64 a, vec_op_std_v2float64 b)
{
    return vec_op_std_fill_v2f64(vec_op_std_dots_v2f64(a, b));
}

static VEC_OP_INLINE vec_op_std_v3float64 vec_op_std_dot_v3f64(vec_op_std_v3float64 a, vec_op_std_v3float64 b)
{
    return vec_op_std_fill_v3f64(vec_op_std_dots_v3f64(a, b));
}

static VEC_OP_INLINE vec_op_std_v4float64 vec_op_std_dot_v4f64(vec_op_std_v4float64 a, vec_op_std_v4float64 b)
{
    return vec_op_std_fill_v4f64(vec_op_std_dots_v4f64(a, b));
}

static VEC_OP_INLINE vec_op_std_v8float64 vec_op_std_dot_v8f64(vec_op_std_v8float64 a, vec_op_std_v8float64 b)
{
    return vec_op_std_fill_v8f64(vec_op_std_dots_v8f64(a, b));
}

static VEC_OP_INLINE vec_op_std_v16float64 vec_op_std_dot_v16f64(vec_op_std_v16float64 a, vec_op_std_v16float64 b)
{
    return vec_op_std_fill_v16f64(vec_op_std_dots_v16f64(a, b));
}

static VEC_OP_INLINE vec_op_std_v2int8 vec_op_std_dot_v2i8(vec_op_std_v2int8 a, vec_op_std_v2int8 b)
{
    return vec_op_std_fill_v2i8(vec_op_std_dots_v2i8(a, b));
}

static VEC_OP_INLINE vec_op_std_v3int8 vec_op_std_dot_v3i8(vec_op_std_v3int8 a, vec_op_std_v3int8 b)
{
    return vec_op_std_fill_v3i8(vec_op_std_dots_v3i8(a, b));
}

static VEC_OP_INLINE vec_op_std_v4int8 vec_op_std_dot_v4i8(vec_op_std_v4int8 a, vec_op_std_v4int8 b)
{
    return vec_op_std_fill_v4i8(vec_op_std_dots_v4i8(a, b));
}

static VEC_OP_INLINE vec_op_std_v8int8 vec_op_std_dot_v8i8(vec_op_std_v8int8 a, vec_op_std_v8int8 b)
{
    return vec_op_std_fill_v8i8(vec_op_std_dots_v8i8(a, b));
}

static VEC_OP_INLINE vec_op_std_v16int8 vec_op_std_dot_v16i8(vec_op_std_v16int8 a, vec_op_std_v16int8 b)
{
    return vec_op_std_fill_v16i8(vec_op_std_dots_v16i8(a, b));
}

static VEC_OP_INLINE vec_op_std_v2int16 vec_op_std_dot_v2i16(vec_op_std_v2int16 a, vec_op_std_v2int16 b)
{
    return vec_op_std_fill_v2i16(vec_op_std_dots_v2i16(a, b));
}

static VEC_OP_INLINE vec_op_std_v3int16 vec_op_std_dot_v3i16(vec_op_std_v3int16 a, vec_op_std_v3int16 b)
{
    return vec_op_std_fill_v3i16(vec_op_std_dots_v3i16(a, b));
}

static VEC_OP_INLINE vec_op_std_v4int16 vec_op_std_dot_v4i16(vec_op_std_v4int16 a, vec_op_std_v4int16 b)
{
    return vec_op_std_fill_v4i16(vec_op_std_dots_v4i16(a, b));
}

static VEC_OP_INLINE vec_op_std_v8int16 vec_op_std_dot_v8i16(vec_op_std_v8int16 a, vec_op_std_v8int16 b)
{
    return vec_op_std_fill_v8i16(vec_op_std_dots_v8i16(a, b));
}

static VEC_OP_INLINE vec_op_std_v16int16 vec_op_std_dot_v16i16(vec_op_std_v16int16 a, vec_op_std_v16int16 b)
{
    return vec_op_std_fill_v16i16(vec_op_std_dots_v16i16(a, b));
}

static VEC_OP_INLINE vec_op_std_v2int32 vec_op_std_dot_v2i32(vec_op_std_v2int32 a, vec_op_std_v2int32 b)
{
    return vec_op_std_fill_v2i32(vec_op_std_dots_v2i32(a, b));
}

static VEC_OP_INLINE vec_op_std_v3int32 vec_op_std_dot_v3i32(vec_op_std_v3int32 a, vec_op_std_v3int32 b)
{
    return vec_op_std_fill_v3i32(vec_op_std_dots_v3i32(a, b));
}

static VEC_OP_INLINE vec_op_std_v4int32 vec_op_std_dot_v4i32(vec_op_std_v4int32 a, vec_op_std_v4int32 b)
{
    return vec_op_std_fill_v4i32(vec_op_std_dots_v4i32(a, b));
}

static VEC_OP_INLINE vec_op_std_v8int32 vec_op_std_dot_v8i32(vec_op_std_v8int32 a, vec_op_std_v8int32 b)
{
    return vec_op_std_fill_v8i32(vec_op_std_dots_v8i32(a, b));
}

static VEC_OP_INLINE vec_op_std_v16int32 vec_op_std_dot_v16i32(vec_op_std_v16int32 a, vec_op_std_v16int32 b)
{
    return vec_op_std_fill_v16i32(vec_op_std_dots_v16i32(a, b));
}

static VEC_OP_INLINE vec_op_std_v2int64 vec_op_std_dot_v2i64(vec_op_std_v2int64 a, vec_op_std_v2int64 b)
{
    return vec_op_std_fill_v2i64(vec_op_std_dots_v2i64(a, b));
}

static VEC_OP_INLINE vec_op_std_v3int64 vec_op_std_dot_v3i64(vec_op_std_v3int64 a, vec_op_std_v3int64 b)
{
    return vec_op_std_fill_v3i64(vec_op_std_dots_v3i64(a, b));
}

static VEC_OP_INLINE vec_op_std_v4int64 vec_op_std_dot_v4i64(vec_op_std_v4int64 a, vec_op_std_v4int64 b)
{
    return vec_op_std_fill_v4i64(vec_op_std_dots_v4i64(a, b));
}

static VEC_OP_INLINE vec_op_std_v8int64 vec_op_std_dot_v8i64(vec_op_std_v8int64 a, vec_op_std_v8int64 b)
{
    return vec_op_std_fill_v8i64(vec_op_std_dots_v8i64(a, b));
}

static VEC_OP_INLINE vec_op_std_v16int64 vec_op_std_dot_v16i64(vec_op_std_v16int64 a, vec_op_std_v16int64 b)
{
    return vec_op_std_fill_v16i64(vec_op_std_dots_v16i64(a, b));
}


#undef VEC_OP_VEC2
#undef VEC_OP_VEC3
#undef VEC_OP_VEC4
#undef VEC_OP_VEC8
#undef VEC_OP_VEC16
#endif

//vector float32's
#if !VEC_OP_SUPPORTS_VF32
#define VEC_OP_SUPPORTS_VF32 VEC_OP_STANDARD

#define vfloat32_t vec_op_std_vfloat32
#define vf32make VEC_OP_STD_FUNC(vfloat32_t, make)
#define vf32fill VEC_OP_STD_FUNC(vfloat32_t, fill)
#define vf32get VEC_OP_STD_FUNC(vfloat32_t, get)
#define vf32set VEC_OP_STD_FUNC(vfloat32_t, set)
#define vf32swizzle VEC_OP_STD_FUNC(vfloat32_t, swizzle)
#define vf32add VEC_OP_STD_FUNC(vfloat32_t, add)
#define vf32sub VEC_OP_STD_FUNC(vfloat32_t, sub)
#define vf32mul VEC_OP_STD_FUNC(vfloat32_t, mul)
#define vf32div VEC_OP_STD_FUNC(vfloat32_t, div)
#define vf32recip VEC_OP_STD_FUNC(vfloat32_t, recip)
#define vf32sqrt VEC_OP_STD_FUNC(vfloat32_t, sqrt)
#define vf32rsqrt VEC_OP_STD_FUNC(vfloat32_t, rsqrt)
#define vf32min VEC_OP_STD_FUNC(vfloat32_t, min)
#define vf32max VEC_OP_STD_FUNC(vfloat32_t, max)
#define vf32dot VEC_OP_STD_FUNC(vfloat32_t, dot)
#define vf32dots VEC_OP_STD_FUNC(vfloat32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2F32
#define VEC_OP_SUPPORTS_V2F32 VEC_OP_STANDARD

#define v2float32_t vec_op_std_v2float32
#define v2f32make VEC_OP_STD_FUNC(v2float32_t, make)
#define v2f32fill VEC_OP_STD_FUNC(v2float32_t, fill)
#define v2f32get VEC_OP_STD_FUNC(v2float32_t, get)
#define v2f32set VEC_OP_STD_FUNC(v2float32_t, set)
#define v2f32swizzle VEC_OP_STD_FUNC(v2float32_t, swizzle)
#define v2f32add VEC_OP_STD_FUNC(v2float32_t, add)
#define v2f32sub VEC_OP_STD_FUNC(v2float32_t, sub)
#define v2f32mul VEC_OP_STD_FUNC(v2float32_t, mul)
#define v2f32div VEC_OP_STD_FUNC(v2float32_t, div)
#define v2f32recip VEC_OP_STD_FUNC(v2float32_t, recip)
#define v2f32sqrt VEC_OP_STD_FUNC(v2float32_t, sqrt)
#define v2f32rsqrt VEC_OP_STD_FUNC(v2float32_t, rsqrt)
#define v2f32min VEC_OP_STD_FUNC(v2float32_t, min)
#define v2f32max VEC_OP_STD_FUNC(v2float32_t, max)
#define v2f32dot VEC_OP_STD_FUNC(v2float32_t, dot)
#define v2f32dots VEC_OP_STD_FUNC(v2float32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3F32
#define VEC_OP_SUPPORTS_V3F32 VEC_OP_STANDARD

#define v3float32_t vec_op_std_v3float32
#define v3f32make VEC_OP_STD_FUNC(v3float32_t, make)
#define v3f32fill VEC_OP_STD_FUNC(v3float32_t, fill)
#define v3f32get VEC_OP_STD_FUNC(v3float32_t, get)
#define v3f32set VEC_OP_STD_FUNC(v3float32_t, set)
#define v3f32swizzle VEC_OP_STD_FUNC(v3float32_t, swizzle)
#define v3f32add VEC_OP_STD_FUNC(v3float32_t, add)
#define v3f32sub VEC_OP_STD_FUNC(v3float32_t, sub)
#define v3f32mul VEC_OP_STD_FUNC(v3float32_t, mul)
#define v3f32div VEC_OP_STD_FUNC(v3float32_t, div)
#define v3f32recip VEC_OP_STD_FUNC(v3float32_t, recip)
#define v3f32sqrt VEC_OP_STD_FUNC(v3float32_t, sqrt)
#define v3f32rsqrt VEC_OP_STD_FUNC(v3float32_t, rsqrt)
#define v3f32min VEC_OP_STD_FUNC(v3float32_t, min)
#define v3f32max VEC_OP_STD_FUNC(v3float32_t, max)
#define v3f32dot VEC_OP_STD_FUNC(v3float32_t, dot)
#define v3f32dots VEC_OP_STD_FUNC(v3float32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4F32
#define VEC_OP_SUPPORTS_V4F32 VEC_OP_STANDARD

#define v4float32_t vec_op_std_v4float32
#define v4f32make VEC_OP_STD_FUNC(v4float32_t, make)
#define v4f32fill VEC_OP_STD_FUNC(v4float32_t, fill)
#define v4f32get VEC_OP_STD_FUNC(v4float32_t, get)
#define v4f32set VEC_OP_STD_FUNC(v4float32_t, set)
#define v4f32swizzle VEC_OP_STD_FUNC(v4float32_t, swizzle)
#define v4f32add VEC_OP_STD_FUNC(v4float32_t, add)
#define v4f32sub VEC_OP_STD_FUNC(v4float32_t, sub)
#define v4f32mul VEC_OP_STD_FUNC(v4float32_t, mul)
#define v4f32div VEC_OP_STD_FUNC(v4float32_t, div)
#define v4f32recip VEC_OP_STD_FUNC(v4float32_t, recip)
#define v4f32sqrt VEC_OP_STD_FUNC(v4float32_t, sqrt)
#define v4f32rsqrt VEC_OP_STD_FUNC(v4float32_t, rsqrt)
#define v4f32min VEC_OP_STD_FUNC(v4float32_t, min)
#define v4f32max VEC_OP_STD_FUNC(v4float32_t, max)
#define v4f32dot VEC_OP_STD_FUNC(v4float32_t, dot)
#define v4f32dots VEC_OP_STD_FUNC(v4float32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8F32
#define VEC_OP_SUPPORTS_V8F32 VEC_OP_STANDARD

#define v8float32_t vec_op_std_v8float32
#define v8f32make VEC_OP_STD_FUNC(v8float32_t, make)
#define v8f32fill VEC_OP_STD_FUNC(v8float32_t, fill)
#define v8f32get VEC_OP_STD_FUNC(v8float32_t, get)
#define v8f32set VEC_OP_STD_FUNC(v8float32_t, set)
#define v8f32swizzle VEC_OP_STD_FUNC(v8float32_t, swizzle)
#define v8f32add VEC_OP_STD_FUNC(v8float32_t, add)
#define v8f32sub VEC_OP_STD_FUNC(v8float32_t, sub)
#define v8f32mul VEC_OP_STD_FUNC(v8float32_t, mul)
#define v8f32div VEC_OP_STD_FUNC(v8float32_t, div)
#define v8f32recip VEC_OP_STD_FUNC(v8float32_t, recip)
#define v8f32sqrt VEC_OP_STD_FUNC(v8float32_t, sqrt)
#define v8f32rsqrt VEC_OP_STD_FUNC(v8float32_t, rsqrt)
#define v8f32min VEC_OP_STD_FUNC(v8float32_t, min)
#define v8f32max VEC_OP_STD_FUNC(v8float32_t, max)
#define v8f32dot VEC_OP_STD_FUNC(v8float32_t, dot)
#define v8f32dots VEC_OP_STD_FUNC(v8float32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16F32
#define VEC_OP_SUPPORTS_V16F32 VEC_OP_STANDARD

#define v16float32_t vec_op_std_v16float32
#define v16f32make VEC_OP_STD_FUNC(v16float32_t, make)
#define v16f32fill VEC_OP_STD_FUNC(v16float32_t, fill)
#define v16f32get VEC_OP_STD_FUNC(v16float32_t, get)
#define v16f32set VEC_OP_STD_FUNC(v16float32_t, set)
#define v16f32swizzle VEC_OP_STD_FUNC(v16float32_t, swizzle)
#define v16f32add VEC_OP_STD_FUNC(v16float32_t, add)
#define v16f32sub VEC_OP_STD_FUNC(v16float32_t, sub)
#define v16f32mul VEC_OP_STD_FUNC(v16float32_t, mul)
#define v16f32div VEC_OP_STD_FUNC(v16float32_t, div)
#define v16f32recip VEC_OP_STD_FUNC(v16float32_t, recip)
#define v16f32sqrt VEC_OP_STD_FUNC(v16float32_t, sqrt)
#define v16f32rsqrt VEC_OP_STD_FUNC(v16float32_t, rsqrt)
#define v16f32min VEC_OP_STD_FUNC(v16float32_t, min)
#define v16f32max VEC_OP_STD_FUNC(v16float32_t, max)
#define v16f32dot VEC_OP_STD_FUNC(v16float32_t, dot)
#define v16f32dots VEC_OP_STD_FUNC(v16float32_t, dots)
#endif


//vector float64's
#if !VEC_OP_SUPPORTS_VF64
#define VEC_OP_SUPPORTS_VF64 VEC_OP_STANDARD

#define vfloat64_t vec_op_std_vfloat64
#define vf64make VEC_OP_STD_FUNC(vfloat64_t, make)
#define vf64fill VEC_OP_STD_FUNC(vfloat64_t, fill)
#define vf64get VEC_OP_STD_FUNC(vfloat64_t, get)
#define vf64set VEC_OP_STD_FUNC(vfloat64_t, set)
#define vf64swizzle VEC_OP_STD_FUNC(vfloat64_t, swizzle)
#define vf64add VEC_OP_STD_FUNC(vfloat64_t, add)
#define vf64sub VEC_OP_STD_FUNC(vfloat64_t, sub)
#define vf64mul VEC_OP_STD_FUNC(vfloat64_t, mul)
#define vf64div VEC_OP_STD_FUNC(vfloat64_t, div)
#define vf64recip VEC_OP_STD_FUNC(vfloat64_t, recip)
#define vf64sqrt VEC_OP_STD_FUNC(vfloat64_t, sqrt)
#define vf64rsqrt VEC_OP_STD_FUNC(vfloat64_t, rsqrt)
#define vf64min VEC_OP_STD_FUNC(vfloat64_t, min)
#define vf64max VEC_OP_STD_FUNC(vfloat64_t, max)
#define vf64dot VEC_OP_STD_FUNC(vfloat64_t, dot)
#define vf64dots VEC_OP_STD_FUNC(vfloat64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2F64
#define VEC_OP_SUPPORTS_V2F64 VEC_OP_STANDARD

#define v2float64_t vec_op_std_v2float64
#define v2f64make VEC_OP_STD_FUNC(v2float64_t, make)
#define v2f64fill VEC_OP_STD_FUNC(v2float64_t, fill)
#define v2f64get VEC_OP_STD_FUNC(v2float64_t, get)
#define v2f64set VEC_OP_STD_FUNC(v2float64_t, set)
#define v2f64swizzle VEC_OP_STD_FUNC(v2float64_t, swizzle)
#define v2f64add VEC_OP_STD_FUNC(v2float64_t, add)
#define v2f64sub VEC_OP_STD_FUNC(v2float64_t, sub)
#define v2f64mul VEC_OP_STD_FUNC(v2float64_t, mul)
#define v2f64div VEC_OP_STD_FUNC(v2float64_t, div)
#define v2f64recip VEC_OP_STD_FUNC(v2float64_t, recip)
#define v2f64sqrt VEC_OP_STD_FUNC(v2float64_t, sqrt)
#define v2f64rsqrt VEC_OP_STD_FUNC(v2float64_t, rsqrt)
#define v2f64min VEC_OP_STD_FUNC(v2float64_t, min)
#define v2f64max VEC_OP_STD_FUNC(v2float64_t, max)
#define v2f64dot VEC_OP_STD_FUNC(v2float64_t, dot)
#define v2f64dots VEC_OP_STD_FUNC(v2float64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3F64
#define VEC_OP_SUPPORTS_V3F64 VEC_OP_STANDARD

#define v3float64_t vec_op_std_v3float64
#define v3f64make VEC_OP_STD_FUNC(v3float64_t, make)
#define v3f64fill VEC_OP_STD_FUNC(v3float64_t, fill)
#define v3f64get VEC_OP_STD_FUNC(v3float64_t, get)
#define v3f64set VEC_OP_STD_FUNC(v3float64_t, set)
#define v3f64swizzle VEC_OP_STD_FUNC(v3float64_t, swizzle)
#define v3f64add VEC_OP_STD_FUNC(v3float64_t, add)
#define v3f64sub VEC_OP_STD_FUNC(v3float64_t, sub)
#define v3f64mul VEC_OP_STD_FUNC(v3float64_t, mul)
#define v3f64div VEC_OP_STD_FUNC(v3float64_t, div)
#define v3f64recip VEC_OP_STD_FUNC(v3float64_t, recip)
#define v3f64sqrt VEC_OP_STD_FUNC(v3float64_t, sqrt)
#define v3f64rsqrt VEC_OP_STD_FUNC(v3float64_t, rsqrt)
#define v3f64min VEC_OP_STD_FUNC(v3float64_t, min)
#define v3f64max VEC_OP_STD_FUNC(v3float64_t, max)
#define v3f64dot VEC_OP_STD_FUNC(v3float64_t, dot)
#define v3f64dots VEC_OP_STD_FUNC(v3float64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4F64
#define VEC_OP_SUPPORTS_V4F64 VEC_OP_STANDARD

#define v4float64_t vec_op_std_v4float64
#define v4f64make VEC_OP_STD_FUNC(v4float64_t, make)
#define v4f64fill VEC_OP_STD_FUNC(v4float64_t, fill)
#define v4f64get VEC_OP_STD_FUNC(v4float64_t, get)
#define v4f64set VEC_OP_STD_FUNC(v4float64_t, set)
#define v4f64swizzle VEC_OP_STD_FUNC(v4float64_t, swizzle)
#define v4f64add VEC_OP_STD_FUNC(v4float64_t, add)
#define v4f64sub VEC_OP_STD_FUNC(v4float64_t, sub)
#define v4f64mul VEC_OP_STD_FUNC(v4float64_t, mul)
#define v4f64div VEC_OP_STD_FUNC(v4float64_t, div)
#define v4f64recip VEC_OP_STD_FUNC(v4float64_t, recip)
#define v4f64sqrt VEC_OP_STD_FUNC(v4float64_t, sqrt)
#define v4f64rsqrt VEC_OP_STD_FUNC(v4float64_t, rsqrt)
#define v4f64min VEC_OP_STD_FUNC(v4float64_t, min)
#define v4f64max VEC_OP_STD_FUNC(v4float64_t, max)
#define v4f64dot VEC_OP_STD_FUNC(v4float64_t, dot)
#define v4f64dots VEC_OP_STD_FUNC(v4float64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8F64
#define VEC_OP_SUPPORTS_V8F64 VEC_OP_STANDARD

#define v8float64_t vec_op_std_v8float64
#define v8f64make VEC_OP_STD_FUNC(v8float64_t, make)
#define v8f64fill VEC_OP_STD_FUNC(v8float64_t, fill)
#define v8f64get VEC_OP_STD_FUNC(v8float64_t, get)
#define v8f64set VEC_OP_STD_FUNC(v8float64_t, set)
#define v8f64swizzle VEC_OP_STD_FUNC(v8float64_t, swizzle)
#define v8f64add VEC_OP_STD_FUNC(v8float64_t, add)
#define v8f64sub VEC_OP_STD_FUNC(v8float64_t, sub)
#define v8f64mul VEC_OP_STD_FUNC(v8float64_t, mul)
#define v8f64div VEC_OP_STD_FUNC(v8float64_t, div)
#define v8f64recip VEC_OP_STD_FUNC(v8float64_t, recip)
#define v8f64sqrt VEC_OP_STD_FUNC(v8float64_t, sqrt)
#define v8f64rsqrt VEC_OP_STD_FUNC(v8float64_t, rsqrt)
#define v8f64min VEC_OP_STD_FUNC(v8float64_t, min)
#define v8f64max VEC_OP_STD_FUNC(v8float64_t, max)
#define v8f64dot VEC_OP_STD_FUNC(v8float64_t, dot)
#define v8f64dots VEC_OP_STD_FUNC(v8float64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16F64
#define VEC_OP_SUPPORTS_V16F64 VEC_OP_STANDARD

#define v16float64_t vec_op_std_v16float64
#define v16f64make VEC_OP_STD_FUNC(v16float64_t, make)
#define v16f64fill VEC_OP_STD_FUNC(v16float64_t, fill)
#define v16f64get VEC_OP_STD_FUNC(v16float64_t, get)
#define v16f64set VEC_OP_STD_FUNC(v16float64_t, set)
#define v16f64swizzle VEC_OP_STD_FUNC(v16float64_t, swizzle)
#define v16f64add VEC_OP_STD_FUNC(v16float64_t, add)
#define v16f64sub VEC_OP_STD_FUNC(v16float64_t, sub)
#define v16f64mul VEC_OP_STD_FUNC(v16float64_t, mul)
#define v16f64div VEC_OP_STD_FUNC(v16float64_t, div)
#define v16f64recip VEC_OP_STD_FUNC(v16float64_t, recip)
#define v16f64sqrt VEC_OP_STD_FUNC(v16float64_t, sqrt)
#define v16f64rsqrt VEC_OP_STD_FUNC(v16float64_t, rsqrt)
#define v16f64min VEC_OP_STD_FUNC(v16float64_t, min)
#define v16f64max VEC_OP_STD_FUNC(v16float64_t, max)
#define v16f64dot VEC_OP_STD_FUNC(v16float64_t, dot)
#define v16f64dots VEC_OP_STD_FUNC(v16float64_t, dots)
#endif


//vector int8's
#if !VEC_OP_SUPPORTS_VI8
#define VEC_OP_SUPPORTS_VI8 VEC_OP_STANDARD

#define vint8_t vec_op_std_vint8
#define vi8make VEC_OP_STD_FUNC(vint8_t, make)
#define vi8fill VEC_OP_STD_FUNC(vint8_t, fill)
#define vi8get VEC_OP_STD_FUNC(vint8_t, get)
#define vi8set VEC_OP_STD_FUNC(vint8_t, set)
#define vi8swizzle VEC_OP_STD_FUNC(vint8_t, swizzle)
#define vi8add VEC_OP_STD_FUNC(vint8_t, add)
#define vi8sub VEC_OP_STD_FUNC(vint8_t, sub)
#define vi8mul VEC_OP_STD_FUNC(vint8_t, mul)
#define vi8div VEC_OP_STD_FUNC(vint8_t, div)
#define vi8recip VEC_OP_STD_FUNC(vint8_t, recip)
#define vi8sqrt VEC_OP_STD_FUNC(vint8_t, sqrt)
#define vi8rsqrt VEC_OP_STD_FUNC(vint8_t, rsqrt)
#define vi8min VEC_OP_STD_FUNC(vint8_t, min)
#define vi8max VEC_OP_STD_FUNC(vint8_t, max)
#define vi8dot VEC_OP_STD_FUNC(vint8_t, dot)
#define vi8dots VEC_OP_STD_FUNC(vint8_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2I8
#define VEC_OP_SUPPORTS_V2I8 VEC_OP_STANDARD

#define v2int8_t vec_op_std_v2int8
#define v2i8make VEC_OP_STD_FUNC(v2int8_t, make)
#define v2i8fill VEC_OP_STD_FUNC(v2int8_t, fill)
#define v2i8get VEC_OP_STD_FUNC(v2int8_t, get)
#define v2i8set VEC_OP_STD_FUNC(v2int8_t, set)
#define v2i8swizzle VEC_OP_STD_FUNC(v2int8_t, swizzle)
#define v2i8add VEC_OP_STD_FUNC(v2int8_t, add)
#define v2i8sub VEC_OP_STD_FUNC(v2int8_t, sub)
#define v2i8mul VEC_OP_STD_FUNC(v2int8_t, mul)
#define v2i8div VEC_OP_STD_FUNC(v2int8_t, div)
#define v2i8recip VEC_OP_STD_FUNC(v2int8_t, recip)
#define v2i8sqrt VEC_OP_STD_FUNC(v2int8_t, sqrt)
#define v2i8rsqrt VEC_OP_STD_FUNC(v2int8_t, rsqrt)
#define v2i8min VEC_OP_STD_FUNC(v2int8_t, min)
#define v2i8max VEC_OP_STD_FUNC(v2int8_t, max)
#define v2i8dot VEC_OP_STD_FUNC(v2int8_t, dot)
#define v2i8dots VEC_OP_STD_FUNC(v2int8_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3I8
#define VEC_OP_SUPPORTS_V3I8 VEC_OP_STANDARD

#define v3int8_t vec_op_std_v3int8
#define v3i8make VEC_OP_STD_FUNC(v3int8_t, make)
#define v3i8fill VEC_OP_STD_FUNC(v3int8_t, fill)
#define v3i8get VEC_OP_STD_FUNC(v3int8_t, get)
#define v3i8set VEC_OP_STD_FUNC(v3int8_t, set)
#define v3i8swizzle VEC_OP_STD_FUNC(v3int8_t, swizzle)
#define v3i8add VEC_OP_STD_FUNC(v3int8_t, add)
#define v3i8sub VEC_OP_STD_FUNC(v3int8_t, sub)
#define v3i8mul VEC_OP_STD_FUNC(v3int8_t, mul)
#define v3i8div VEC_OP_STD_FUNC(v3int8_t, div)
#define v3i8recip VEC_OP_STD_FUNC(v3int8_t, recip)
#define v3i8sqrt VEC_OP_STD_FUNC(v3int8_t, sqrt)
#define v3i8rsqrt VEC_OP_STD_FUNC(v3int8_t, rsqrt)
#define v3i8min VEC_OP_STD_FUNC(v3int8_t, min)
#define v3i8max VEC_OP_STD_FUNC(v3int8_t, max)
#define v3i8dot VEC_OP_STD_FUNC(v3int8_t, dot)
#define v3i8dots VEC_OP_STD_FUNC(v3int8_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4I8
#define VEC_OP_SUPPORTS_V4I8 VEC_OP_STANDARD

#define v4int8_t vec_op_std_v4int8
#define v4i8make VEC_OP_STD_FUNC(v4int8_t, make)
#define v4i8fill VEC_OP_STD_FUNC(v4int8_t, fill)
#define v4i8get VEC_OP_STD_FUNC(v4int8_t, get)
#define v4i8set VEC_OP_STD_FUNC(v4int8_t, set)
#define v4i8swizzle VEC_OP_STD_FUNC(v4int8_t, swizzle)
#define v4i8add VEC_OP_STD_FUNC(v4int8_t, add)
#define v4i8sub VEC_OP_STD_FUNC(v4int8_t, sub)
#define v4i8mul VEC_OP_STD_FUNC(v4int8_t, mul)
#define v4i8div VEC_OP_STD_FUNC(v4int8_t, div)
#define v4i8recip VEC_OP_STD_FUNC(v4int8_t, recip)
#define v4i8sqrt VEC_OP_STD_FUNC(v4int8_t, sqrt)
#define v4i8rsqrt VEC_OP_STD_FUNC(v4int8_t, rsqrt)
#define v4i8min VEC_OP_STD_FUNC(v4int8_t, min)
#define v4i8max VEC_OP_STD_FUNC(v4int8_t, max)
#define v4i8dot VEC_OP_STD_FUNC(v4int8_t, dot)
#define v4i8dots VEC_OP_STD_FUNC(v4int8_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8I8
#define VEC_OP_SUPPORTS_V8I8 VEC_OP_STANDARD

#define v8int8_t vec_op_std_v8int8
#define v8i8make VEC_OP_STD_FUNC(v8int8_t, make)
#define v8i8fill VEC_OP_STD_FUNC(v8int8_t, fill)
#define v8i8get VEC_OP_STD_FUNC(v8int8_t, get)
#define v8i8set VEC_OP_STD_FUNC(v8int8_t, set)
#define v8i8swizzle VEC_OP_STD_FUNC(v8int8_t, swizzle)
#define v8i8add VEC_OP_STD_FUNC(v8int8_t, add)
#define v8i8sub VEC_OP_STD_FUNC(v8int8_t, sub)
#define v8i8mul VEC_OP_STD_FUNC(v8int8_t, mul)
#define v8i8div VEC_OP_STD_FUNC(v8int8_t, div)
#define v8i8recip VEC_OP_STD_FUNC(v8int8_t, recip)
#define v8i8sqrt VEC_OP_STD_FUNC(v8int8_t, sqrt)
#define v8i8rsqrt VEC_OP_STD_FUNC(v8int8_t, rsqrt)
#define v8i8min VEC_OP_STD_FUNC(v8int8_t, min)
#define v8i8max VEC_OP_STD_FUNC(v8int8_t, max)
#define v8i8dot VEC_OP_STD_FUNC(v8int8_t, dot)
#define v8i8dots VEC_OP_STD_FUNC(v8int8_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16I8
#define VEC_OP_SUPPORTS_V16I8 VEC_OP_STANDARD

#define v16int8_t vec_op_std_v16int8
#define v16i8make VEC_OP_STD_FUNC(v16int8_t, make)
#define v16i8fill VEC_OP_STD_FUNC(v16int8_t, fill)
#define v16i8get VEC_OP_STD_FUNC(v16int8_t, get)
#define v16i8set VEC_OP_STD_FUNC(v16int8_t, set)
#define v16i8swizzle VEC_OP_STD_FUNC(v16int8_t, swizzle)
#define v16i8add VEC_OP_STD_FUNC(v16int8_t, add)
#define v16i8sub VEC_OP_STD_FUNC(v16int8_t, sub)
#define v16i8mul VEC_OP_STD_FUNC(v16int8_t, mul)
#define v16i8div VEC_OP_STD_FUNC(v16int8_t, div)
#define v16i8recip VEC_OP_STD_FUNC(v16int8_t, recip)
#define v16i8sqrt VEC_OP_STD_FUNC(v16int8_t, sqrt)
#define v16i8rsqrt VEC_OP_STD_FUNC(v16int8_t, rsqrt)
#define v16i8min VEC_OP_STD_FUNC(v16int8_t, min)
#define v16i8max VEC_OP_STD_FUNC(v16int8_t, max)
#define v16i8dot VEC_OP_STD_FUNC(v16int8_t, dot)
#define v16i8dots VEC_OP_STD_FUNC(v16int8_t, dots)
#endif



//vector int16's
#if !VEC_OP_SUPPORTS_VI16
#define VEC_OP_SUPPORTS_VI16 VEC_OP_STANDARD

#define vint16_t vec_op_std_vint16
#define vi16make VEC_OP_STD_FUNC(vint16_t, make)
#define vi16fill VEC_OP_STD_FUNC(vint16_t, fill)
#define vi16get VEC_OP_STD_FUNC(vint16_t, get)
#define vi16set VEC_OP_STD_FUNC(vint16_t, set)
#define vi16swizzle VEC_OP_STD_FUNC(vint16_t, swizzle)
#define vi16add VEC_OP_STD_FUNC(vint16_t, add)
#define vi16sub VEC_OP_STD_FUNC(vint16_t, sub)
#define vi16mul VEC_OP_STD_FUNC(vint16_t, mul)
#define vi16div VEC_OP_STD_FUNC(vint16_t, div)
#define vi16recip VEC_OP_STD_FUNC(vint16_t, recip)
#define vi16sqrt VEC_OP_STD_FUNC(vint16_t, sqrt)
#define vi16rsqrt VEC_OP_STD_FUNC(vint16_t, rsqrt)
#define vi16min VEC_OP_STD_FUNC(vint16_t, min)
#define vi16max VEC_OP_STD_FUNC(vint16_t, max)
#define vi16dot VEC_OP_STD_FUNC(vint16_t, dot)
#define vi16dots VEC_OP_STD_FUNC(vint16_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2I16
#define VEC_OP_SUPPORTS_V2I16 VEC_OP_STANDARD

#define v2int16_t vec_op_std_v2int16
#define v2i16make VEC_OP_STD_FUNC(v2int16_t, make)
#define v2i16fill VEC_OP_STD_FUNC(v2int16_t, fill)
#define v2i16get VEC_OP_STD_FUNC(v2int16_t, get)
#define v2i16set VEC_OP_STD_FUNC(v2int16_t, set)
#define v2i16swizzle VEC_OP_STD_FUNC(v2int16_t, swizzle)
#define v2i16add VEC_OP_STD_FUNC(v2int16_t, add)
#define v2i16sub VEC_OP_STD_FUNC(v2int16_t, sub)
#define v2i16mul VEC_OP_STD_FUNC(v2int16_t, mul)
#define v2i16div VEC_OP_STD_FUNC(v2int16_t, div)
#define v2i16recip VEC_OP_STD_FUNC(v2int16_t, recip)
#define v2i16sqrt VEC_OP_STD_FUNC(v2int16_t, sqrt)
#define v2i16rsqrt VEC_OP_STD_FUNC(v2int16_t, rsqrt)
#define v2i16min VEC_OP_STD_FUNC(v2int16_t, min)
#define v2i16max VEC_OP_STD_FUNC(v2int16_t, max)
#define v2i16dot VEC_OP_STD_FUNC(v2int16_t, dot)
#define v2i16dots VEC_OP_STD_FUNC(v2int16_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3I16
#define VEC_OP_SUPPORTS_V3I16 VEC_OP_STANDARD

#define v3int16_t vec_op_std_v3int16
#define v3i16make VEC_OP_STD_FUNC(v3int16_t, make)
#define v3i16fill VEC_OP_STD_FUNC(v3int16_t, fill)
#define v3i16get VEC_OP_STD_FUNC(v3int16_t, get)
#define v3i16set VEC_OP_STD_FUNC(v3int16_t, set)
#define v3i16swizzle VEC_OP_STD_FUNC(v3int16_t, swizzle)
#define v3i16add VEC_OP_STD_FUNC(v3int16_t, add)
#define v3i16sub VEC_OP_STD_FUNC(v3int16_t, sub)
#define v3i16mul VEC_OP_STD_FUNC(v3int16_t, mul)
#define v3i16div VEC_OP_STD_FUNC(v3int16_t, div)
#define v3i16recip VEC_OP_STD_FUNC(v3int16_t, recip)
#define v3i16sqrt VEC_OP_STD_FUNC(v3int16_t, sqrt)
#define v3i16rsqrt VEC_OP_STD_FUNC(v3int16_t, rsqrt)
#define v3i16min VEC_OP_STD_FUNC(v3int16_t, min)
#define v3i16max VEC_OP_STD_FUNC(v3int16_t, max)
#define v3i16dot VEC_OP_STD_FUNC(v3int16_t, dot)
#define v3i16dots VEC_OP_STD_FUNC(v3int16_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4I16
#define VEC_OP_SUPPORTS_V4I16 VEC_OP_STANDARD

#define v4int16_t vec_op_std_v4int16
#define v4i16make VEC_OP_STD_FUNC(v4int16_t, make)
#define v4i16fill VEC_OP_STD_FUNC(v4int16_t, fill)
#define v4i16get VEC_OP_STD_FUNC(v4int16_t, get)
#define v4i16set VEC_OP_STD_FUNC(v4int16_t, set)
#define v4i16swizzle VEC_OP_STD_FUNC(v4int16_t, swizzle)
#define v4i16add VEC_OP_STD_FUNC(v4int16_t, add)
#define v4i16sub VEC_OP_STD_FUNC(v4int16_t, sub)
#define v4i16mul VEC_OP_STD_FUNC(v4int16_t, mul)
#define v4i16div VEC_OP_STD_FUNC(v4int16_t, div)
#define v4i16recip VEC_OP_STD_FUNC(v4int16_t, recip)
#define v4i16sqrt VEC_OP_STD_FUNC(v4int16_t, sqrt)
#define v4i16rsqrt VEC_OP_STD_FUNC(v4int16_t, rsqrt)
#define v4i16min VEC_OP_STD_FUNC(v4int16_t, min)
#define v4i16max VEC_OP_STD_FUNC(v4int16_t, max)
#define v4i16dot VEC_OP_STD_FUNC(v4int16_t, dot)
#define v4i16dots VEC_OP_STD_FUNC(v4int16_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8I16
#define VEC_OP_SUPPORTS_V8I16 VEC_OP_STANDARD

#define v8int16_t vec_op_std_v8int16
#define v8i16make VEC_OP_STD_FUNC(v8int16_t, make)
#define v8i16fill VEC_OP_STD_FUNC(v8int16_t, fill)
#define v8i16get VEC_OP_STD_FUNC(v8int16_t, get)
#define v8i16set VEC_OP_STD_FUNC(v8int16_t, set)
#define v8i16swizzle VEC_OP_STD_FUNC(v8int16_t, swizzle)
#define v8i16add VEC_OP_STD_FUNC(v8int16_t, add)
#define v8i16sub VEC_OP_STD_FUNC(v8int16_t, sub)
#define v8i16mul VEC_OP_STD_FUNC(v8int16_t, mul)
#define v8i16div VEC_OP_STD_FUNC(v8int16_t, div)
#define v8i16recip VEC_OP_STD_FUNC(v8int16_t, recip)
#define v8i16sqrt VEC_OP_STD_FUNC(v8int16_t, sqrt)
#define v8i16rsqrt VEC_OP_STD_FUNC(v8int16_t, rsqrt)
#define v8i16min VEC_OP_STD_FUNC(v8int16_t, min)
#define v8i16max VEC_OP_STD_FUNC(v8int16_t, max)
#define v8i16dot VEC_OP_STD_FUNC(v8int16_t, dot)
#define v8i16dots VEC_OP_STD_FUNC(v8int16_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16I16
#define VEC_OP_SUPPORTS_V16I16 VEC_OP_STANDARD

#define v16int16_t vec_op_std_v16int16
#define v16i16make VEC_OP_STD_FUNC(v16int16_t, make)
#define v16i16fill VEC_OP_STD_FUNC(v16int16_t, fill)
#define v16i16get VEC_OP_STD_FUNC(v16int16_t, get)
#define v16i16set VEC_OP_STD_FUNC(v16int16_t, set)
#define v16i16swizzle VEC_OP_STD_FUNC(v16int16_t, swizzle)
#define v16i16add VEC_OP_STD_FUNC(v16int16_t, add)
#define v16i16sub VEC_OP_STD_FUNC(v16int16_t, sub)
#define v16i16mul VEC_OP_STD_FUNC(v16int16_t, mul)
#define v16i16div VEC_OP_STD_FUNC(v16int16_t, div)
#define v16i16recip VEC_OP_STD_FUNC(v16int16_t, recip)
#define v16i16sqrt VEC_OP_STD_FUNC(v16int16_t, sqrt)
#define v16i16rsqrt VEC_OP_STD_FUNC(v16int16_t, rsqrt)
#define v16i16min VEC_OP_STD_FUNC(v16int16_t, min)
#define v16i16max VEC_OP_STD_FUNC(v16int16_t, max)
#define v16i16dot VEC_OP_STD_FUNC(v16int16_t, dot)
#define v16i16dots VEC_OP_STD_FUNC(v16int16_t, dots)
#endif



//vector int32's
#if !VEC_OP_SUPPORTS_VI32
#define VEC_OP_SUPPORTS_VI32 VEC_OP_STANDARD

#define vint32_t vec_op_std_vint32
#define vi32make VEC_OP_STD_FUNC(vint32_t, make)
#define vi32fill VEC_OP_STD_FUNC(vint32_t, fill)
#define vi32get VEC_OP_STD_FUNC(vint32_t, get)
#define vi32set VEC_OP_STD_FUNC(vint32_t, set)
#define vi32swizzle VEC_OP_STD_FUNC(vint32_t, swizzle)
#define vi32add VEC_OP_STD_FUNC(vint32_t, add)
#define vi32sub VEC_OP_STD_FUNC(vint32_t, sub)
#define vi32mul VEC_OP_STD_FUNC(vint32_t, mul)
#define vi32div VEC_OP_STD_FUNC(vint32_t, div)
#define vi32recip VEC_OP_STD_FUNC(vint32_t, recip)
#define vi32sqrt VEC_OP_STD_FUNC(vint32_t, sqrt)
#define vi32rsqrt VEC_OP_STD_FUNC(vint32_t, rsqrt)
#define vi32min VEC_OP_STD_FUNC(vint32_t, min)
#define vi32max VEC_OP_STD_FUNC(vint32_t, max)
#define vi32dot VEC_OP_STD_FUNC(vint32_t, dot)
#define vi32dots VEC_OP_STD_FUNC(vint32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2I32
#define VEC_OP_SUPPORTS_V2I32 VEC_OP_STANDARD

#define v2int32_t vec_op_std_v2int32
#define v2i32make VEC_OP_STD_FUNC(v2int32_t, make)
#define v2i32fill VEC_OP_STD_FUNC(v2int32_t, fill)
#define v2i32get VEC_OP_STD_FUNC(v2int32_t, get)
#define v2i32set VEC_OP_STD_FUNC(v2int32_t, set)
#define v2i32swizzle VEC_OP_STD_FUNC(v2int32_t, swizzle)
#define v2i32add VEC_OP_STD_FUNC(v2int32_t, add)
#define v2i32sub VEC_OP_STD_FUNC(v2int32_t, sub)
#define v2i32mul VEC_OP_STD_FUNC(v2int32_t, mul)
#define v2i32div VEC_OP_STD_FUNC(v2int32_t, div)
#define v2i32recip VEC_OP_STD_FUNC(v2int32_t, recip)
#define v2i32sqrt VEC_OP_STD_FUNC(v2int32_t, sqrt)
#define v2i32rsqrt VEC_OP_STD_FUNC(v2int32_t, rsqrt)
#define v2i32min VEC_OP_STD_FUNC(v2int32_t, min)
#define v2i32max VEC_OP_STD_FUNC(v2int32_t, max)
#define v2i32dot VEC_OP_STD_FUNC(v2int32_t, dot)
#define v2i32dots VEC_OP_STD_FUNC(v2int32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3I32
#define VEC_OP_SUPPORTS_V3I32 VEC_OP_STANDARD

#define v3int32_t vec_op_std_v3int32
#define v3i32make VEC_OP_STD_FUNC(v3int32_t, make)
#define v3i32fill VEC_OP_STD_FUNC(v3int32_t, fill)
#define v3i32get VEC_OP_STD_FUNC(v3int32_t, get)
#define v3i32set VEC_OP_STD_FUNC(v3int32_t, set)
#define v3i32swizzle VEC_OP_STD_FUNC(v3int32_t, swizzle)
#define v3i32add VEC_OP_STD_FUNC(v3int32_t, add)
#define v3i32sub VEC_OP_STD_FUNC(v3int32_t, sub)
#define v3i32mul VEC_OP_STD_FUNC(v3int32_t, mul)
#define v3i32div VEC_OP_STD_FUNC(v3int32_t, div)
#define v3i32recip VEC_OP_STD_FUNC(v3int32_t, recip)
#define v3i32sqrt VEC_OP_STD_FUNC(v3int32_t, sqrt)
#define v3i32rsqrt VEC_OP_STD_FUNC(v3int32_t, rsqrt)
#define v3i32min VEC_OP_STD_FUNC(v3int32_t, min)
#define v3i32max VEC_OP_STD_FUNC(v3int32_t, max)
#define v3i32dot VEC_OP_STD_FUNC(v3int32_t, dot)
#define v3i32dots VEC_OP_STD_FUNC(v3int32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4I32
#define VEC_OP_SUPPORTS_V4I32 VEC_OP_STANDARD

#define v4int32_t vec_op_std_v4int32
#define v4i32make VEC_OP_STD_FUNC(v4int32_t, make)
#define v4i32fill VEC_OP_STD_FUNC(v4int32_t, fill)
#define v4i32get VEC_OP_STD_FUNC(v4int32_t, get)
#define v4i32set VEC_OP_STD_FUNC(v4int32_t, set)
#define v4i32swizzle VEC_OP_STD_FUNC(v4int32_t, swizzle)
#define v4i32add VEC_OP_STD_FUNC(v4int32_t, add)
#define v4i32sub VEC_OP_STD_FUNC(v4int32_t, sub)
#define v4i32mul VEC_OP_STD_FUNC(v4int32_t, mul)
#define v4i32div VEC_OP_STD_FUNC(v4int32_t, div)
#define v4i32recip VEC_OP_STD_FUNC(v4int32_t, recip)
#define v4i32sqrt VEC_OP_STD_FUNC(v4int32_t, sqrt)
#define v4i32rsqrt VEC_OP_STD_FUNC(v4int32_t, rsqrt)
#define v4i32min VEC_OP_STD_FUNC(v4int32_t, min)
#define v4i32max VEC_OP_STD_FUNC(v4int32_t, max)
#define v4i32dot VEC_OP_STD_FUNC(v4int32_t, dot)
#define v4i32dots VEC_OP_STD_FUNC(v4int32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8I32
#define VEC_OP_SUPPORTS_V8I32 VEC_OP_STANDARD

#define v8int32_t vec_op_std_v8int32
#define v8i32make VEC_OP_STD_FUNC(v8int32_t, make)
#define v8i32fill VEC_OP_STD_FUNC(v8int32_t, fill)
#define v8i32get VEC_OP_STD_FUNC(v8int32_t, get)
#define v8i32set VEC_OP_STD_FUNC(v8int32_t, set)
#define v8i32swizzle VEC_OP_STD_FUNC(v8int32_t, swizzle)
#define v8i32add VEC_OP_STD_FUNC(v8int32_t, add)
#define v8i32sub VEC_OP_STD_FUNC(v8int32_t, sub)
#define v8i32mul VEC_OP_STD_FUNC(v8int32_t, mul)
#define v8i32div VEC_OP_STD_FUNC(v8int32_t, div)
#define v8i32recip VEC_OP_STD_FUNC(v8int32_t, recip)
#define v8i32sqrt VEC_OP_STD_FUNC(v8int32_t, sqrt)
#define v8i32rsqrt VEC_OP_STD_FUNC(v8int32_t, rsqrt)
#define v8i32min VEC_OP_STD_FUNC(v8int32_t, min)
#define v8i32max VEC_OP_STD_FUNC(v8int32_t, max)
#define v8i32dot VEC_OP_STD_FUNC(v8int32_t, dot)
#define v8i32dots VEC_OP_STD_FUNC(v8int32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16I32
#define VEC_OP_SUPPORTS_V16I32 VEC_OP_STANDARD

#define v16int32_t vec_op_std_v16int32
#define v16i32make VEC_OP_STD_FUNC(v16int32_t, make)
#define v16i32fill VEC_OP_STD_FUNC(v16int32_t, fill)
#define v16i32get VEC_OP_STD_FUNC(v16int32_t, get)
#define v16i32set VEC_OP_STD_FUNC(v16int32_t, set)
#define v16i32swizzle VEC_OP_STD_FUNC(v16int32_t, swizzle)
#define v16i32add VEC_OP_STD_FUNC(v16int32_t, add)
#define v16i32sub VEC_OP_STD_FUNC(v16int32_t, sub)
#define v16i32mul VEC_OP_STD_FUNC(v16int32_t, mul)
#define v16i32div VEC_OP_STD_FUNC(v16int32_t, div)
#define v16i32recip VEC_OP_STD_FUNC(v16int32_t, recip)
#define v16i32sqrt VEC_OP_STD_FUNC(v16int32_t, sqrt)
#define v16i32rsqrt VEC_OP_STD_FUNC(v16int32_t, rsqrt)
#define v16i32min VEC_OP_STD_FUNC(v16int32_t, min)
#define v16i32max VEC_OP_STD_FUNC(v16int32_t, max)
#define v16i32dot VEC_OP_STD_FUNC(v16int32_t, dot)
#define v16i32dots VEC_OP_STD_FUNC(v16int32_t, dots)
#endif



//vector int64's
#if !VEC_OP_SUPPORTS_VI64
#define VEC_OP_SUPPORTS_VI64 VEC_OP_STANDARD

#define vint64_t vec_op_std_vint64
#define vi64make VEC_OP_STD_FUNC(vint64_t, make)
#define vi64fill VEC_OP_STD_FUNC(vint64_t, fill)
#define vi64get VEC_OP_STD_FUNC(vint64_t, get)
#define vi64set VEC_OP_STD_FUNC(vint64_t, set)
#define vi64swizzle VEC_OP_STD_FUNC(vint64_t, swizzle)
#define vi64add VEC_OP_STD_FUNC(vint64_t, add)
#define vi64sub VEC_OP_STD_FUNC(vint64_t, sub)
#define vi64mul VEC_OP_STD_FUNC(vint64_t, mul)
#define vi64div VEC_OP_STD_FUNC(vint64_t, div)
#define vi64recip VEC_OP_STD_FUNC(vint64_t, recip)
#define vi64sqrt VEC_OP_STD_FUNC(vint64_t, sqrt)
#define vi64rsqrt VEC_OP_STD_FUNC(vint64_t, rsqrt)
#define vi64min VEC_OP_STD_FUNC(vint64_t, min)
#define vi64max VEC_OP_STD_FUNC(vint64_t, max)
#define vi64dot VEC_OP_STD_FUNC(vint64_t, dot)
#define vi64dots VEC_OP_STD_FUNC(vint64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V2I64
#define VEC_OP_SUPPORTS_V2I64 VEC_OP_STANDARD

#define v2int64_t vec_op_std_v2int64
#define v2i64make VEC_OP_STD_FUNC(v2int64_t, make)
#define v2i64fill VEC_OP_STD_FUNC(v2int64_t, fill)
#define v2i64get VEC_OP_STD_FUNC(v2int64_t, get)
#define v2i64set VEC_OP_STD_FUNC(v2int64_t, set)
#define v2i64swizzle VEC_OP_STD_FUNC(v2int64_t, swizzle)
#define v2i64add VEC_OP_STD_FUNC(v2int64_t, add)
#define v2i64sub VEC_OP_STD_FUNC(v2int64_t, sub)
#define v2i64mul VEC_OP_STD_FUNC(v2int64_t, mul)
#define v2i64div VEC_OP_STD_FUNC(v2int64_t, div)
#define v2i64recip VEC_OP_STD_FUNC(v2int64_t, recip)
#define v2i64sqrt VEC_OP_STD_FUNC(v2int64_t, sqrt)
#define v2i64rsqrt VEC_OP_STD_FUNC(v2int64_t, rsqrt)
#define v2i64min VEC_OP_STD_FUNC(v2int64_t, min)
#define v2i64max VEC_OP_STD_FUNC(v2int64_t, max)
#define v2i64dot VEC_OP_STD_FUNC(v2int64_t, dot)
#define v2i64dots VEC_OP_STD_FUNC(v2int64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V3I64
#define VEC_OP_SUPPORTS_V3I64 VEC_OP_STANDARD

#define v3int64_t vec_op_std_v3int64
#define v3i64make VEC_OP_STD_FUNC(v3int64_t, make)
#define v3i64fill VEC_OP_STD_FUNC(v3int64_t, fill)
#define v3i64get VEC_OP_STD_FUNC(v3int64_t, get)
#define v3i64set VEC_OP_STD_FUNC(v3int64_t, set)
#define v3i64swizzle VEC_OP_STD_FUNC(v3int64_t, swizzle)
#define v3i64add VEC_OP_STD_FUNC(v3int64_t, add)
#define v3i64sub VEC_OP_STD_FUNC(v3int64_t, sub)
#define v3i64mul VEC_OP_STD_FUNC(v3int64_t, mul)
#define v3i64div VEC_OP_STD_FUNC(v3int64_t, div)
#define v3i64recip VEC_OP_STD_FUNC(v3int64_t, recip)
#define v3i64sqrt VEC_OP_STD_FUNC(v3int64_t, sqrt)
#define v3i64rsqrt VEC_OP_STD_FUNC(v3int64_t, rsqrt)
#define v3i64min VEC_OP_STD_FUNC(v3int64_t, min)
#define v3i64max VEC_OP_STD_FUNC(v3int64_t, max)
#define v3i64dot VEC_OP_STD_FUNC(v3int64_t, dot)
#define v3i64dots VEC_OP_STD_FUNC(v3int64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4I64
#define VEC_OP_SUPPORTS_V4I64 VEC_OP_STANDARD

#define v4int64_t vec_op_std_v4int64
#define v4i64make VEC_OP_STD_FUNC(v4int64_t, make)
#define v4i64fill VEC_OP_STD_FUNC(v4int64_t, fill)
#define v4i64get VEC_OP_STD_FUNC(v4int64_t, get)
#define v4i64set VEC_OP_STD_FUNC(v4int64_t, set)
#define v4i64swizzle VEC_OP_STD_FUNC(v4int64_t, swizzle)
#define v4i64add VEC_OP_STD_FUNC(v4int64_t, add)
#define v4i64sub VEC_OP_STD_FUNC(v4int64_t, sub)
#define v4i64mul VEC_OP_STD_FUNC(v4int64_t, mul)
#define v4i64div VEC_OP_STD_FUNC(v4int64_t, div)
#define v4i64recip VEC_OP_STD_FUNC(v4int64_t, recip)
#define v4i64sqrt VEC_OP_STD_FUNC(v4int64_t, sqrt)
#define v4i64rsqrt VEC_OP_STD_FUNC(v4int64_t, rsqrt)
#define v4i64min VEC_OP_STD_FUNC(v4int64_t, min)
#define v4i64max VEC_OP_STD_FUNC(v4int64_t, max)
#define v4i64dot VEC_OP_STD_FUNC(v4int64_t, dot)
#define v4i64dots VEC_OP_STD_FUNC(v4int64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V8I64
#define VEC_OP_SUPPORTS_V8I64 VEC_OP_STANDARD

#define v8int64_t vec_op_std_v8int64
#define v8i64make VEC_OP_STD_FUNC(v8int64_t, make)
#define v8i64fill VEC_OP_STD_FUNC(v8int64_t, fill)
#define v8i64get VEC_OP_STD_FUNC(v8int64_t, get)
#define v8i64set VEC_OP_STD_FUNC(v8int64_t, set)
#define v8i64swizzle VEC_OP_STD_FUNC(v8int64_t, swizzle)
#define v8i64add VEC_OP_STD_FUNC(v8int64_t, add)
#define v8i64sub VEC_OP_STD_FUNC(v8int64_t, sub)
#define v8i64mul VEC_OP_STD_FUNC(v8int64_t, mul)
#define v8i64div VEC_OP_STD_FUNC(v8int64_t, div)
#define v8i64recip VEC_OP_STD_FUNC(v8int64_t, recip)
#define v8i64sqrt VEC_OP_STD_FUNC(v8int64_t, sqrt)
#define v8i64rsqrt VEC_OP_STD_FUNC(v8int64_t, rsqrt)
#define v8i64min VEC_OP_STD_FUNC(v8int64_t, min)
#define v8i64max VEC_OP_STD_FUNC(v8int64_t, max)
#define v8i64dot VEC_OP_STD_FUNC(v8int64_t, dot)
#define v8i64dots VEC_OP_STD_FUNC(v8int64_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V16I64
#define VEC_OP_SUPPORTS_V16I64 VEC_OP_STANDARD

#define v16int64_t vec_op_std_v16int64
#define v16i64make VEC_OP_STD_FUNC(v16int64_t, make)
#define v16i64fill VEC_OP_STD_FUNC(v16int64_t, fill)
#define v16i64get VEC_OP_STD_FUNC(v16int64_t, get)
#define v16i64set VEC_OP_STD_FUNC(v16int64_t, set)
#define v16i64swizzle VEC_OP_STD_FUNC(v16int64_t, swizzle)
#define v16i64add VEC_OP_STD_FUNC(v16int64_t, add)
#define v16i64sub VEC_OP_STD_FUNC(v16int64_t, sub)
#define v16i64mul VEC_OP_STD_FUNC(v16int64_t, mul)
#define v16i64div VEC_OP_STD_FUNC(v16int64_t, div)
#define v16i64recip VEC_OP_STD_FUNC(v16int64_t, recip)
#define v16i64sqrt VEC_OP_STD_FUNC(v16int64_t, sqrt)
#define v16i64rsqrt VEC_OP_STD_FUNC(v16int64_t, rsqrt)
#define v16i64min VEC_OP_STD_FUNC(v16int64_t, min)
#define v16i64max VEC_OP_STD_FUNC(v16int64_t, max)
#define v16i64dot VEC_OP_STD_FUNC(v16int64_t, dot)
#define v16i64dots VEC_OP_STD_FUNC(v16int64_t, dots)
#endif
