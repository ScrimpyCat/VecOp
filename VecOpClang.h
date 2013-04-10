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

#ifndef VecOp_VecOpClang_h
#define VecOp_VecOpClang_h
#define VEC_OP_CLANG 2

#include <stdint.h>


#define VEC_OP_VEC2(type) type __attribute__((ext_vector_type(2)))
#define VEC_OP_VEC3(type) type __attribute__((ext_vector_type(3)))
#define VEC_OP_VEC4(type) type __attribute__((ext_vector_type(4)))
#define VEC_OP_VEC8(type) type __attribute__((ext_vector_type(8)))
#define VEC_OP_VEC16(type) type __attribute__((ext_vector_type(16)))


//float32
typedef VEC_OP_VEC2(float) vec_op_clang_v2float32;
typedef VEC_OP_VEC3(float) vec_op_clang_v3float32;
typedef VEC_OP_VEC4(float) vec_op_clang_v4float32;
typedef VEC_OP_VEC8(float) vec_op_clang_v8float32;
typedef VEC_OP_VEC16(float) vec_op_clang_v16float32;
//float64
typedef VEC_OP_VEC2(double) vec_op_clang_v2float64;
typedef VEC_OP_VEC3(double) vec_op_clang_v3float64;
typedef VEC_OP_VEC4(double) vec_op_clang_v4float64;
typedef VEC_OP_VEC8(double) vec_op_clang_v8float64;
typedef VEC_OP_VEC16(double) vec_op_clang_v16float64;
//int8
typedef VEC_OP_VEC2(int8_t) vec_op_clang_v2int8;
typedef VEC_OP_VEC3(int8_t) vec_op_clang_v3int8;
typedef VEC_OP_VEC4(int8_t) vec_op_clang_v4int8;
typedef VEC_OP_VEC8(int8_t) vec_op_clang_v8int8;
typedef VEC_OP_VEC16(int8_t) vec_op_clang_v16int8;
//int16
typedef VEC_OP_VEC2(int16_t) vec_op_clang_v2int16;
typedef VEC_OP_VEC3(int16_t) vec_op_clang_v3int16;
typedef VEC_OP_VEC4(int16_t) vec_op_clang_v4int16;
typedef VEC_OP_VEC8(int16_t) vec_op_clang_v8int16;
typedef VEC_OP_VEC16(int16_t) vec_op_clang_v16int16;
//int32
typedef VEC_OP_VEC2(int32_t) vec_op_clang_v2int32;
typedef VEC_OP_VEC3(int32_t) vec_op_clang_v3int32;
typedef VEC_OP_VEC4(int32_t) vec_op_clang_v4int32;
typedef VEC_OP_VEC8(int32_t) vec_op_clang_v8int32;
typedef VEC_OP_VEC16(int32_t) vec_op_clang_v16int32;
//int64
typedef VEC_OP_VEC2(int64_t) vec_op_clang_v2int64;
typedef VEC_OP_VEC3(int64_t) vec_op_clang_v3int64;
typedef VEC_OP_VEC4(int64_t) vec_op_clang_v4int64;
typedef VEC_OP_VEC8(int64_t) vec_op_clang_v8int64;
typedef VEC_OP_VEC16(int64_t) vec_op_clang_v16int64;
//native size
#if VEC_OP_NATIVE_VECTOR_SIZE == 128
typedef vec_op_clang_v16float64 vec_op_clang_vfloat64;
typedef vec_op_clang_v16int64 vec_op_clang_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 64
typedef vec_op_clang_v16float32 vec_op_clang_vfloat32;
typedef vec_op_clang_v8float64 vec_op_clang_vfloat64;
typedef vec_op_clang_v16int32 vec_op_clang_vint32;
typedef vec_op_clang_v8int64 vec_op_clang_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 32
typedef vec_op_clang_v8float32 vec_op_clang_vfloat32;
typedef vec_op_clang_v4float64 vec_op_clang_vfloat64;
typedef vec_op_clang_v16int16 vec_op_clang_vint16;
typedef vec_op_clang_v8int32 vec_op_clang_vint32;
typedef vec_op_clang_v4int64 vec_op_clang_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 24
typedef vec_op_clang_v3float64 vec_op_clang_vfloat64;
typedef vec_op_clang_v3int64 vec_op_clang_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 16
typedef vec_op_clang_v4float32 vec_op_clang_vfloat32;
typedef vec_op_clang_v2float64 vec_op_clang_vfloat64;
typedef vec_op_clang_v16int8 vec_op_clang_vint8;
typedef vec_op_clang_v8int16 vec_op_clang_vint16;
typedef vec_op_clang_v4int32 vec_op_clang_vint32;
typedef vec_op_clang_v2int64 vec_op_clang_vint64;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 12
typedef vec_op_clang_v3int32 vec_op_clang_vint32;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 8
typedef vec_op_clang_v2float32 vec_op_clang_vfloat32;
typedef vec_op_clang_v8int8 vec_op_clang_vint8;
typedef vec_op_clang_v4int16 vec_op_clang_vint16;
typedef vec_op_clang_v2int32 vec_op_clang_vint32;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 6
typedef vec_op_clang_v3int16 vec_op_clang_vint16;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 4
typedef vec_op_clang_v4int8 vec_op_clang_vint8;
typedef vec_op_clang_v2int16 vec_op_clang_vint16;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 3
typedef vec_op_clang_v3int8 vec_op_clang_vint8;
#elif VEC_OP_NATIVE_VECTOR_SIZE == 2
typedef vec_op_clang_v2int8 vec_op_clang_vint8;
#endif


#define VEC_OP_CLANG_FUNC(type, name) (_Generic(*(type*)0, \
    /*vec_op_clang_v2float32: vec_op_clang_##name##_v2f32, \
    vec_op_clang_v3float32: vec_op_clang_##name##_v3f32, */\
    vec_op_clang_v4float32: vec_op_clang_##name##_v4f32/*, \
    vec_op_clang_v8float32: vec_op_clang_##name##_v8f32, \
    vec_op_clang_v16float32: vec_op_clang_##name##_v16f32, \
    \
    vec_op_clang_v2float64: vec_op_clang_##name##_v2f64, \
    vec_op_clang_v3float64: vec_op_clang_##name##_v3f64, \
    vec_op_clang_v4float64: vec_op_clang_##name##_v4f64, \
    vec_op_clang_v8float64: vec_op_clang_##name##_v8f64, \
    vec_op_clang_v16float64: vec_op_clang_##name##_v16f64, \
    \
    vec_op_clang_v2int8: vec_op_clang_##name##_v2i8, \
    vec_op_clang_v3int8: vec_op_clang_##name##_v3i8, \
    vec_op_clang_v4int8: vec_op_clang_##name##_v4i8, \
    vec_op_clang_v8int8: vec_op_clang_##name##_v8i8, \
    vec_op_clang_v16int8: vec_op_clang_##name##_v16i8, \
    \
    vec_op_clang_v2int16: vec_op_clang_##name##_v2i16, \
    vec_op_clang_v3int16: vec_op_clang_##name##_v3i16, \
    vec_op_clang_v4int16: vec_op_clang_##name##_v4i16, \
    vec_op_clang_v8int16: vec_op_clang_##name##_v8i16, \
    vec_op_clang_v16int16: vec_op_clang_##name##_v16i16, \
    \
    vec_op_clang_v2int32: vec_op_clang_##name##_v2i32, \
    vec_op_clang_v3int32: vec_op_clang_##name##_v3i32, \
    vec_op_clang_v4int32: vec_op_clang_##name##_v4i32, \
    vec_op_clang_v8int32: vec_op_clang_##name##_v8i32, \
    vec_op_clang_v16int32: vec_op_clang_##name##_v16i32, \
    \
    vec_op_clang_v2int64: vec_op_clang_##name##_v2i64, \
    vec_op_clang_v3int64: vec_op_clang_##name##_v3i64, \
    vec_op_clang_v4int64: vec_op_clang_##name##_v4i64, \
    vec_op_clang_v8int64: vec_op_clang_##name##_v8i64, \
    vec_op_clang_v16int64: vec_op_clang_##name##_v16i64*/ \
))


//float32's
static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_make_v4f32(float v0, float v1, float v2, float v3)
{
    return (vec_op_clang_v4float32){ v0, v1, v2, v3 };
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_fill_v4f32(float v0)
{
    return (vec_op_clang_v4float32)(v0);
}

static VEC_OP_INLINE float vec_op_clang_get_v4f32(vec_op_clang_v4float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    return v[Index];
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_set_v4f32(vec_op_clang_v4float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    v[Index] = Value;
    return v;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_swizzle_v4f32(vec_op_clang_v4float32 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    return (vec_op_clang_v4float32){ a[v0], a[v1], a[v2], a[v3] };
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_add_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return a + b;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_sub_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return a - b;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_mul_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return a * b;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_div_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return a / b;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_recip_v4f32(vec_op_clang_v4float32 a)
{
    return (vec_op_clang_v4float32)(1.0f) / a;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_sqrt_v4f32(vec_op_clang_v4float32 a)
{
    return (vec_op_clang_v4float32){ sqrtf(a.x), sqrtf(a.y), sqrtf(a.z), sqrtf(a.w) }; //it's a shame we have to do this (as no general builtin) as it's unlikely it'll understand we want to do a vectorized sqrt rather than calling the sqrtf function with each scalar
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_rsqrt_v4f32(vec_op_clang_v4float32 a)
{
    return vec_op_clang_recip_v4f32(vec_op_clang_sqrt_v4f32(a));
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_min_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return (vec_op_clang_v4float32){ a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y, a.z < b.z ? a.z : b.z, a.w < b.w ? a.w : b.w }; //as v1 conditional-expression v2 only work for ext_vector integers
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_max_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return (vec_op_clang_v4float32){ a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w > b.w ? a.w : b.w };
}

static VEC_OP_INLINE float vec_op_clang_dots_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    vec_op_clang_v4float32 c = vec_op_clang_mul_v4f32(a, b);
    return c.x + c.y + c.z + c.w;
}

static VEC_OP_INLINE vec_op_clang_v4float32 vec_op_clang_dot_v4f32(vec_op_clang_v4float32 a, vec_op_clang_v4float32 b)
{
    return vec_op_clang_fill_v4f32(vec_op_clang_dots_v4f32(a, b));
}


#undef VEC_OP_VEC2
#undef VEC_OP_VEC3
#undef VEC_OP_VEC4
#undef VEC_OP_VEC8
#undef VEC_OP_VEC16
#endif



//vector float32's
#if !VEC_OP_SUPPORTS_VF32
#define VEC_OP_SUPPORTS_VF32 VEC_OP_CLANG

#define vfloat32_t vec_op_clang_vfloat32
#define vf32make VEC_OP_CLANG_FUNC(vfloat32_t, make)
#define vf32fill VEC_OP_CLANG_FUNC(vfloat32_t, fill)
#define vf32get VEC_OP_CLANG_FUNC(vfloat32_t, get)
#define vf32set VEC_OP_CLANG_FUNC(vfloat32_t, set)
#define vf32swizzle VEC_OP_CLANG_FUNC(vfloat32_t, swizzle)
#define vf32add VEC_OP_CLANG_FUNC(vfloat32_t, add)
#define vf32sub VEC_OP_CLANG_FUNC(vfloat32_t, sub)
#define vf32mul VEC_OP_CLANG_FUNC(vfloat32_t, mul)
#define vf32div VEC_OP_CLANG_FUNC(vfloat32_t, div)
#define vf32recip VEC_OP_CLANG_FUNC(vfloat32_t, recip)
#define vf32sqrt VEC_OP_CLANG_FUNC(vfloat32_t, sqrt)
#define vf32rsqrt VEC_OP_CLANG_FUNC(vfloat32_t, rsqrt)
#define vf32min VEC_OP_CLANG_FUNC(vfloat32_t, min)
#define vf32max VEC_OP_CLANG_FUNC(vfloat32_t, max)
#define vf32dot VEC_OP_CLANG_FUNC(vfloat32_t, dot)
#define vf32dots VEC_OP_CLANG_FUNC(vfloat32_t, dots)
#endif

#if !VEC_OP_SUPPORTS_V4F32
#define VEC_OP_SUPPORTS_V4F32 VEC_OP_CLANG

#define v4float32_t vec_op_clang_v4float32
#define v4f32make VEC_OP_CLANG_FUNC(v4float32_t, make)
#define v4f32fill VEC_OP_CLANG_FUNC(v4float32_t, fill)
#define v4f32get VEC_OP_CLANG_FUNC(v4float32_t, get)
#define v4f32set VEC_OP_CLANG_FUNC(v4float32_t, set)
#define v4f32swizzle VEC_OP_CLANG_FUNC(v4float32_t, swizzle)
#define v4f32add VEC_OP_CLANG_FUNC(v4float32_t, add)
#define v4f32sub VEC_OP_CLANG_FUNC(v4float32_t, sub)
#define v4f32mul VEC_OP_CLANG_FUNC(v4float32_t, mul)
#define v4f32div VEC_OP_CLANG_FUNC(v4float32_t, div)
#define v4f32recip VEC_OP_CLANG_FUNC(v4float32_t, recip)
#define v4f32sqrt VEC_OP_CLANG_FUNC(v4float32_t, sqrt)
#define v4f32rsqrt VEC_OP_CLANG_FUNC(v4float32_t, rsqrt)
#define v4f32min VEC_OP_CLANG_FUNC(v4float32_t, min)
#define v4f32max VEC_OP_CLANG_FUNC(v4float32_t, max)
#define v4f32dot VEC_OP_CLANG_FUNC(v4float32_t, dot)
#define v4f32dots VEC_OP_CLANG_FUNC(v4float32_t, dots)
#endif
