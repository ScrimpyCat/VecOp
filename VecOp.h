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

/*
 Configurable defines: (define before inclusion to use)
 Note: All optional defines, are to be defined to true (so it meets "#if define") if you wish to use.
 
 VEC_OP_NATIVE_VECTOR_SIZE - specify the size in bytes of the native type (default is 16)
 
 VEC_OP_USE_SAFETY_CHECKS - activates safety checks (uses assert's) for things like array indexing, null pointers, etc.
 
 VEC_OP_FORCE_STANDARD - forces it to use the standard non-optimal operations.
 VEC_OP_FORCE_NO_STANDARD - forces it to not use the back up standard if some types can't be supported in optimal variants.
 VEC_OP_FORCE_NO_CLANG - forces it to not use clang's ext_vector if supported (as it normally would as a hopefully faster backup)
 VEC_OP_FORCE_NO_X86_SSE - if compiling with __SSE__ enabled it will force it not to use it (basically use this to not use any SSE and fallback to another variant).
 VEC_OP_FORCE_NO_X86_SSE2 - if compiling with __SSE2__ enabled it will force it to use only SSE
 VEC_OP_FORCE_NO_X86_SSE3 - if compiling with __SSE3__ enabled it will force it to use only SSE2 and SSE
 VEC_OP_FORCE_NO_X86_SSSE3 - if compiling with __SSSE3__ enabled it will force it to use only SSE3 and SSE2 and SSE
 VEC_OP_FORCE_NO_X86_SSE4_1 - if __SSE4_1__ etc.
 VEC_OP_FORCE_NO_X86_SSE4_2 - if __SSE4_2__ etc.
 VEC_OP_FORCE_NO_X86_SSE5 - if __SSE5__ etc.
 
 Understanding the function encoding: 
 The type names can be split up into v(n) where (n) is optional, {} is a choice, and all else is constant/as is.
 v = vector of standard type elements up to 16 bytes.
 v(n) = vector of n elements (e.g. v2 has x and y, v4 has x, y, z, w).
 {f32,f64,i8,i16,i32,i64} = the standard data types { float, double, int8_t, int16_t, int32_t, int64_t }.
 
 Useful defines:
 Can query VEC_OP_SUPPORTS_V(n){I,F}n to make sure whether a particular vector type is supported (sould always be supported unless 
 you used VEC_OP_FORCE_NO_STANDARD). The support can also be queried with a specific type, so you can check whether it's using the back
 up standard or whether it's using optimal. e.g. if VEC_OP_SUPPORTS_VF32 == VEC_OP_STANDARD then VEC_OP_SUPPORTS_VF32 type is using 
 standard. Check the start of each header to see the naming.
 
 */

#ifndef VEC_OP_NATIVE_VECTOR_SIZE
#define VEC_OP_NATIVE_VECTOR_SIZE 16
#endif


#undef VEC_OP_SUPPORTS_VF32
#undef VEC_OP_SUPPORTS_V2F32
#undef VEC_OP_SUPPORTS_V3F32
#undef VEC_OP_SUPPORTS_V4F32
#undef VEC_OP_SUPPORTS_V8F32
#undef VEC_OP_SUPPORTS_V16F32

#undef VEC_OP_SUPPORTS_VF64
#undef VEC_OP_SUPPORTS_V2F64
#undef VEC_OP_SUPPORTS_V3F64
#undef VEC_OP_SUPPORTS_V4F64
#undef VEC_OP_SUPPORTS_V8F64
#undef VEC_OP_SUPPORTS_V16F64

#undef VEC_OP_SUPPORTS_VI8
#undef VEC_OP_SUPPORTS_V2I8
#undef VEC_OP_SUPPORTS_V3I8
#undef VEC_OP_SUPPORTS_V4I8
#undef VEC_OP_SUPPORTS_V8I8
#undef VEC_OP_SUPPORTS_V16I8

#undef VEC_OP_SUPPORTS_VI16
#undef VEC_OP_SUPPORTS_V2I16
#undef VEC_OP_SUPPORTS_V3I16
#undef VEC_OP_SUPPORTS_V4I16
#undef VEC_OP_SUPPORTS_V8I16
#undef VEC_OP_SUPPORTS_V16I16

#undef VEC_OP_SUPPORTS_VI32
#undef VEC_OP_SUPPORTS_V2I32
#undef VEC_OP_SUPPORTS_V3I32
#undef VEC_OP_SUPPORTS_V4I32
#undef VEC_OP_SUPPORTS_V8I32
#undef VEC_OP_SUPPORTS_V16I32

#undef VEC_OP_SUPPORTS_VI64
#undef VEC_OP_SUPPORTS_V2I64
#undef VEC_OP_SUPPORTS_V3I64
#undef VEC_OP_SUPPORTS_V4I64
#undef VEC_OP_SUPPORTS_V8I64
#undef VEC_OP_SUPPORTS_V16I64

#undef vfloat32_t
#undef v2float32_t
#undef v3float32_t
#undef v4float32_t
#undef v8float32_t
#undef v16float32_t

#undef vfloat64_t
#undef v2float64_t
#undef v3float64_t
#undef v4float64_t
#undef v8float64_t
#undef v16float64_t

#undef vint8_t
#undef v2int8_t
#undef v3int8_t
#undef v4int8_t
#undef v8int8_t
#undef v16int8_t

#undef vint16_t
#undef v2int16_t
#undef v3int16_t
#undef v4int16_t
#undef v8int16_t
#undef v16int16_t

#undef vint32_t
#undef v2int32_t
#undef v3int32_t
#undef v4int32_t
#undef v8int32_t
#undef v16int32_t

#undef vint64_t
#undef v2int64_t
#undef v3int64_t
#undef v4int64_t
#undef v8int64_t
#undef v16int64_t


#undef vf32make
#undef vf32fill
#undef vf32get
#undef vf32set
#undef vf32swizzle
#undef vf32add
#undef vf32sub
#undef vf32mul
#undef vf32div
#undef vf32recip
#undef vf32sqrt
#undef vf32rsqrt
#undef vf32min
#undef vf32max
#undef vf32dot
#undef vf32dots


#undef v2f32make
#undef v2f32fill
#undef v2f32get
#undef v2f32set
#undef v2f32swizzle
#undef v2f32add
#undef v2f32sub
#undef v2f32mul
#undef v2f32div
#undef v2f32recip
#undef v2f32sqrt
#undef v2f32rsqrt
#undef v2f32min
#undef v2f32max
#undef v2f32dot
#undef v2f32dots


#undef v3f32make
#undef v3f32fill
#undef v3f32get
#undef v3f32set
#undef v3f32swizzle
#undef v3f32add
#undef v3f32sub
#undef v3f32mul
#undef v3f32div
#undef v3f32recip
#undef v3f32sqrt
#undef v3f32rsqrt
#undef v3f32min
#undef v3f32max
#undef v3f32dot
#undef v3f32dots


#undef v4f32make
#undef v4f32fill
#undef v4f32get
#undef v4f32set
#undef v4f32swizzle
#undef v4f32add
#undef v4f32sub
#undef v4f32mul
#undef v4f32div
#undef v4f32recip
#undef v4f32sqrt
#undef v4f32rsqrt
#undef v4f32min
#undef v4f32max
#undef v4f32dot
#undef v4f32dots


#undef v8f32make
#undef v8f32fill
#undef v8f32get
#undef v8f32set
#undef v8f32swizzle
#undef v8f32add
#undef v8f32sub
#undef v8f32mul
#undef v8f32div
#undef v8f32recip
#undef v8f32sqrt
#undef v8f32rsqrt
#undef v8f32min
#undef v8f32max
#undef v8f32dot
#undef v8f32dots


#undef v16f32make
#undef v16f32fill
#undef v16f32get
#undef v16f32set
#undef v16f32swizzle
#undef v16f32add
#undef v16f32sub
#undef v16f32mul
#undef v16f32div
#undef v16f32recip
#undef v16f32sqrt
#undef v16f32rsqrt
#undef v16f32min
#undef v16f32max
#undef v16f32dot
#undef v16f32dots


//vector float64's

#undef vf64make
#undef vf64fill
#undef vf64get
#undef vf64set
#undef vf64swizzle
#undef vf64add
#undef vf64sub
#undef vf64mul
#undef vf64div
#undef vf64recip
#undef vf64sqrt
#undef vf64rsqrt
#undef vf64min
#undef vf64max
#undef vf64dot
#undef vf64dots


#undef v2f64make
#undef v2f64fill
#undef v2f64get
#undef v2f64set
#undef v2f64swizzle
#undef v2f64add
#undef v2f64sub
#undef v2f64mul
#undef v2f64div
#undef v2f64recip
#undef v2f64sqrt
#undef v2f64rsqrt
#undef v2f64min
#undef v2f64max
#undef v2f64dot
#undef v2f64dots


#undef v3f64make
#undef v3f64fill
#undef v3f64get
#undef v3f64set
#undef v3f64swizzle
#undef v3f64add
#undef v3f64sub
#undef v3f64mul
#undef v3f64div
#undef v3f64recip
#undef v3f64sqrt
#undef v3f64rsqrt
#undef v3f64min
#undef v3f64max
#undef v3f64dot
#undef v3f64dots


#undef v4f64make
#undef v4f64fill
#undef v4f64get
#undef v4f64set
#undef v4f64swizzle
#undef v4f64add
#undef v4f64sub
#undef v4f64mul
#undef v4f64div
#undef v4f64recip
#undef v4f64sqrt
#undef v4f64rsqrt
#undef v4f64min
#undef v4f64max
#undef v4f64dot
#undef v4f64dots


#undef v8f64make
#undef v8f64fill
#undef v8f64get
#undef v8f64set
#undef v8f64swizzle
#undef v8f64add
#undef v8f64sub
#undef v8f64mul
#undef v8f64div
#undef v8f64recip
#undef v8f64sqrt
#undef v8f64rsqrt
#undef v8f64min
#undef v8f64max
#undef v8f64dot
#undef v8f64dots


#undef v16f64make
#undef v16f64fill
#undef v16f64get
#undef v16f64set
#undef v16f64swizzle
#undef v16f64add
#undef v16f64sub
#undef v16f64mul
#undef v16f64div
#undef v16f64recip
#undef v16f64sqrt
#undef v16f64rsqrt
#undef v16f64min
#undef v16f64max
#undef v16f64dot
#undef v16f64dots


//vector int8's

#undef vi8make
#undef vi8fill
#undef vi8get
#undef vi8set
#undef vi8swizzle
#undef vi8add
#undef vi8sub
#undef vi8mul
#undef vi8div
#undef vi8recip
#undef vi8sqrt
#undef vi8rsqrt
#undef vi8min
#undef vi8max
#undef vi8dot
#undef vi8dots


#undef v2i8make
#undef v2i8fill
#undef v2i8get
#undef v2i8set
#undef v2i8swizzle
#undef v2i8add
#undef v2i8sub
#undef v2i8mul
#undef v2i8div
#undef v2i8recip
#undef v2i8sqrt
#undef v2i8rsqrt
#undef v2i8min
#undef v2i8max
#undef v2i8dot
#undef v2i8dots


#undef v3i8make
#undef v3i8fill
#undef v3i8get
#undef v3i8set
#undef v3i8swizzle
#undef v3i8add
#undef v3i8sub
#undef v3i8mul
#undef v3i8div
#undef v3i8recip
#undef v3i8sqrt
#undef v3i8rsqrt
#undef v3i8min
#undef v3i8max
#undef v3i8dot
#undef v3i8dots


#undef v4i8make
#undef v4i8fill
#undef v4i8get
#undef v4i8set
#undef v4i8swizzle
#undef v4i8add
#undef v4i8sub
#undef v4i8mul
#undef v4i8div
#undef v4i8recip
#undef v4i8sqrt
#undef v4i8rsqrt
#undef v4i8min
#undef v4i8max
#undef v4i8dot
#undef v4i8dots


#undef v8i8make
#undef v8i8fill
#undef v8i8get
#undef v8i8set
#undef v8i8swizzle
#undef v8i8add
#undef v8i8sub
#undef v8i8mul
#undef v8i8div
#undef v8i8recip
#undef v8i8sqrt
#undef v8i8rsqrt
#undef v8i8min
#undef v8i8max
#undef v8i8dot
#undef v8i8dots


#undef v16i8make
#undef v16i8fill
#undef v16i8get
#undef v16i8set
#undef v16i8swizzle
#undef v16i8add
#undef v16i8sub
#undef v16i8mul
#undef v16i8div
#undef v16i8recip
#undef v16i8sqrt
#undef v16i8rsqrt
#undef v16i8min
#undef v16i8max
#undef v16i8dot
#undef v16i8dots



//vector int16's

#undef vi16make
#undef vi16fill
#undef vi16get
#undef vi16set
#undef vi16swizzle
#undef vi16add
#undef vi16sub
#undef vi16mul
#undef vi16div
#undef vi16recip
#undef vi16sqrt
#undef vi16rsqrt
#undef vi16min
#undef vi16max
#undef vi16dot
#undef vi16dots


#undef v2i16make
#undef v2i16fill
#undef v2i16get
#undef v2i16set
#undef v2i16swizzle
#undef v2i16add
#undef v2i16sub
#undef v2i16mul
#undef v2i16div
#undef v2i16recip
#undef v2i16sqrt
#undef v2i16rsqrt
#undef v2i16min
#undef v2i16max
#undef v2i16dot
#undef v2i16dots


#undef v3i16make
#undef v3i16fill
#undef v3i16get
#undef v3i16set
#undef v3i16swizzle
#undef v3i16add
#undef v3i16sub
#undef v3i16mul
#undef v3i16div
#undef v3i16recip
#undef v3i16sqrt
#undef v3i16rsqrt
#undef v3i16min
#undef v3i16max
#undef v3i16dot
#undef v3i16dots


#undef v4i16make
#undef v4i16fill
#undef v4i16get
#undef v4i16set
#undef v4i16swizzle
#undef v4i16add
#undef v4i16sub
#undef v4i16mul
#undef v4i16div
#undef v4i16recip
#undef v4i16sqrt
#undef v4i16rsqrt
#undef v4i16min
#undef v4i16max
#undef v4i16dot
#undef v4i16dots


#undef v8i16make
#undef v8i16fill
#undef v8i16get
#undef v8i16set
#undef v8i16swizzle
#undef v8i16add
#undef v8i16sub
#undef v8i16mul
#undef v8i16div
#undef v8i16recip
#undef v8i16sqrt
#undef v8i16rsqrt
#undef v8i16min
#undef v8i16max
#undef v8i16dot
#undef v8i16dots


#undef v16i16make
#undef v16i16fill
#undef v16i16get
#undef v16i16set
#undef v16i16swizzle
#undef v16i16add
#undef v16i16sub
#undef v16i16mul
#undef v16i16div
#undef v16i16recip
#undef v16i16sqrt
#undef v16i16rsqrt
#undef v16i16min
#undef v16i16max
#undef v16i16dot
#undef v16i16dots



//vector int32's

#undef vi32make
#undef vi32fill
#undef vi32get
#undef vi32set
#undef vi32swizzle
#undef vi32add
#undef vi32sub
#undef vi32mul
#undef vi32div
#undef vi32recip
#undef vi32sqrt
#undef vi32rsqrt
#undef vi32min
#undef vi32max
#undef vi32dot
#undef vi32dots


#undef v2i32make
#undef v2i32fill
#undef v2i32get
#undef v2i32set
#undef v2i32swizzle
#undef v2i32add
#undef v2i32sub
#undef v2i32mul
#undef v2i32div
#undef v2i32recip
#undef v2i32sqrt
#undef v2i32rsqrt
#undef v2i32min
#undef v2i32max
#undef v2i32dot
#undef v2i32dots


#undef v3i32make
#undef v3i32fill
#undef v3i32get
#undef v3i32set
#undef v3i32swizzle
#undef v3i32add
#undef v3i32sub
#undef v3i32mul
#undef v3i32div
#undef v3i32recip
#undef v3i32sqrt
#undef v3i32rsqrt
#undef v3i32min
#undef v3i32max
#undef v3i32dot
#undef v3i32dots


#undef v4i32make
#undef v4i32fill
#undef v4i32get
#undef v4i32set
#undef v4i32swizzle
#undef v4i32add
#undef v4i32sub
#undef v4i32mul
#undef v4i32div
#undef v4i32recip
#undef v4i32sqrt
#undef v4i32rsqrt
#undef v4i32min
#undef v4i32max
#undef v4i32dot
#undef v4i32dots


#undef v8i32make
#undef v8i32fill
#undef v8i32get
#undef v8i32set
#undef v8i32swizzle
#undef v8i32add
#undef v8i32sub
#undef v8i32mul
#undef v8i32div
#undef v8i32recip
#undef v8i32sqrt
#undef v8i32rsqrt
#undef v8i32min
#undef v8i32max
#undef v8i32dot
#undef v8i32dots


#undef v16i32make
#undef v16i32fill
#undef v16i32get
#undef v16i32set
#undef v16i32swizzle
#undef v16i32add
#undef v16i32sub
#undef v16i32mul
#undef v16i32div
#undef v16i32recip
#undef v16i32sqrt
#undef v16i32rsqrt
#undef v16i32min
#undef v16i32max
#undef v16i32dot
#undef v16i32dots



//vector int64's

#undef vi64make
#undef vi64fill
#undef vi64get
#undef vi64set
#undef vi64swizzle
#undef vi64add
#undef vi64sub
#undef vi64mul
#undef vi64div
#undef vi64recip
#undef vi64sqrt
#undef vi64rsqrt
#undef vi64min
#undef vi64max
#undef vi64dot
#undef vi64dots


#undef v2i64make
#undef v2i64fill
#undef v2i64get
#undef v2i64set
#undef v2i64swizzle
#undef v2i64add
#undef v2i64sub
#undef v2i64mul
#undef v2i64div
#undef v2i64recip
#undef v2i64sqrt
#undef v2i64rsqrt
#undef v2i64min
#undef v2i64max
#undef v2i64dot
#undef v2i64dots


#undef v3i64make
#undef v3i64fill
#undef v3i64get
#undef v3i64set
#undef v3i64swizzle
#undef v3i64add
#undef v3i64sub
#undef v3i64mul
#undef v3i64div
#undef v3i64recip
#undef v3i64sqrt
#undef v3i64rsqrt
#undef v3i64min
#undef v3i64max
#undef v3i64dot
#undef v3i64dots


#undef v4i64make
#undef v4i64fill
#undef v4i64get
#undef v4i64set
#undef v4i64swizzle
#undef v4i64add
#undef v4i64sub
#undef v4i64mul
#undef v4i64div
#undef v4i64recip
#undef v4i64sqrt
#undef v4i64rsqrt
#undef v4i64min
#undef v4i64max
#undef v4i64dot
#undef v4i64dots


#undef v8i64make
#undef v8i64fill
#undef v8i64get
#undef v8i64set
#undef v8i64swizzle
#undef v8i64add
#undef v8i64sub
#undef v8i64mul
#undef v8i64div
#undef v8i64recip
#undef v8i64sqrt
#undef v8i64rsqrt
#undef v8i64min
#undef v8i64max
#undef v8i64dot
#undef v8i64dots


#undef v16i64make
#undef v16i64fill
#undef v16i64get
#undef v16i64set
#undef v16i64swizzle
#undef v16i64add
#undef v16i64sub
#undef v16i64mul
#undef v16i64div
#undef v16i64recip
#undef v16i64sqrt
#undef v16i64rsqrt
#undef v16i64min
#undef v16i64max
#undef v16i64dot
#undef v16i64dots





#ifndef VecOp_VecOp_h
#define VecOp_VecOp_h

//element's position in the vector (e.g. use in swizzle)
#define VEC_OP_V0 0
#define VEC_OP_V1 1
#define VEC_OP_V2 2
#define VEC_OP_V3 3
#define VEC_OP_V4 4
#define VEC_OP_V5 5
#define VEC_OP_V6 6
#define VEC_OP_V7 7
#define VEC_OP_V8 8
#define VEC_OP_V9 9
#define VEC_OP_V10 10
#define VEC_OP_V11 11
#define VEC_OP_V12 12
#define VEC_OP_V13 13
#define VEC_OP_V14 14
#define VEC_OP_V15 15


#define VEC_OP_GENERIC_FUNCTION(name, type) (_Generic(type, \
    v2float32_t: v2f32##name, \
    v3float32_t: v3f32##name, \
    v4float32_t: v4f32##name, \
    v8float32_t: v8f32##name, \
    v16float32_t: v16f32##name, \
    \
    v2float64_t: v2f64##name, \
    v3float64_t: v3f64##name, \
    v4float64_t: v4f64##name, \
    v8float64_t: v8f64##name, \
    v16float64_t: v16f64##name, \
    \
    v2int8_t: v2i8##name, \
    v3int8_t: v3i8##name, \
    v4int8_t: v4i8##name, \
    v8int8_t: v8i8##name, \
    v16int8_t: v16i8##name, \
    \
    v2int16_t: v2i16##name, \
    v3int16_t: v3i16##name, \
    v4int16_t: v4i16##name, \
    v8int16_t: v8i16##name, \
    v16int16_t: v16i16##name, \
    \
    v2int32_t: v2i32##name, \
    v3int32_t: v3i32##name, \
    v4int32_t: v4i32##name, \
    v8int32_t: v8i32##name, \
    v16int32_t: v16i32##name, \
    \
    v2int64_t: v2i64##name, \
    v3int64_t: v3i64##name, \
    v4int64_t: v4i64##name, \
    v8int64_t: v8i64##name, \
    v16int64_t: v16i64##name \
))

#define vget(a, index) VEC_OP_GENERIC_FUNCTION(get, a)(a, index)
#define vset(a, index, val) VEC_OP_GENERIC_FUNCTION(set, a)(a, index, val)
#define vswizzle(a, ...) VEC_OP_GENERIC_FUNCTION(swizzle, a)(a, __VA_ARGS__)
#define vadd(a, b) VEC_OP_GENERIC_FUNCTION(add, a)(a, b) //add
#define vsub(a, b) VEC_OP_GENERIC_FUNCTION(sub, a)(a, b) //subtract
#define vmul(a, b) VEC_OP_GENERIC_FUNCTION(mul, a)(a, b) //multiply
#define vdiv(a, b) VEC_OP_GENERIC_FUNCTION(div, a)(a, b) //divide
#define vrecip(a) VEC_OP_GENERIC_FUNCTION(recip, a)(a) //reciprocal
#define vsqrt(a) VEC_OP_GENERIC_FUNCTION(sqrt, a)(a) //square root
#define vrsqrt(a) VEC_OP_GENERIC_FUNCTION(rsqrt, a)(a) //reciprocal square root
#define vmin(a, b) VEC_OP_GENERIC_FUNCTION(min, a)(a, b) //minima
#define vmax(a, b) VEC_OP_GENERIC_FUNCTION(max, a)(a, b) //maxima
#define vdot(a, b) VEC_OP_GENERIC_FUNCTION(dot, a)(a, b) //dot product (returns vector)
#define vdots(a, b) VEC_OP_GENERIC_FUNCTION(dots, a)(a, b) //dot product (returns scalar)


#if __clang__ || __GCC__
#define VEC_OP_INLINE inline __attribute__((always_inline))
#else
#define VEC_OP_INLINE inline
#endif

#endif


#if VEC_OP_FORCE_STANDARD

#include "VecOpStd.h"

#else

#if __SSE__ && !VEC_OP_FORCE_NO_X86_SSE
#include "VecOpX86SSE.h"
#endif

#if __clang__ && !VEC_OP_FORCE_NO_CLANG
#if __has_extension(attribute_ext_vector_type)
#include "VecOpClang.h"
#endif
#endif

#if __GCC__
//vector_size extension
#endif

#if !VEC_OP_FORCE_NO_STANDARD
#include "VecOpStd.h"
#endif

#endif
