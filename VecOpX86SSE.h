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

#ifndef VecOp_VecOpX86SSE_h
#define VecOp_VecOpX86SSE_h
#define VEC_OP_X86_SSE      10
#define VEC_OP_X86_SSE2     11
#define VEC_OP_X86_SSE3     12
#define VEC_OP_X86_SSSE3    13
#define VEC_OP_X86_SSE4_1   14
#define VEC_OP_X86_SSE4_2   15
#define VEC_OP_X86_SSE5     16

#include <immintrin.h>



//float32
typedef __v4sf vec_op_x86_sse_v4float32;
//float64
typedef __v2df vec_op_x86_sse_v2float64;
//int8
typedef __v16qi vec_op_x86_sse_v16int8;
//int16
typedef __v8hi vec_op_x86_sse_v8int16;
//int32
typedef __v4si vec_op_x86_sse_v4int32;
//int64
typedef __v2di vec_op_x86_sse_v2int64;
//assumed native(16 byte) size
#if VEC_OP_NATIVE_VECTOR_SIZE == 16
typedef vec_op_x86_sse_v4float32 vec_op_x86_sse_vfloat32;
typedef vec_op_x86_sse_v2float64 vec_op_x86_sse_vfloat64;
typedef vec_op_x86_sse_v16int8 vec_op_x86_sse_vint8;
typedef vec_op_x86_sse_v8int16 vec_op_x86_sse_vint16;
typedef vec_op_x86_sse_v4int32 vec_op_x86_sse_vint32;
typedef vec_op_x86_sse_v2int64 vec_op_x86_sse_vint64;
#endif


#define VEC_OP_FUNC_SSEv(type, name, version) (_Generic(*(type*)0, \
    vec_op_x86_sse_v4float32: vec_op_x86_##version##_##name##_v4f32/*, \
    \
    vec_op_x86_sse_v2float64: vec_op_x86_##version##_##name##_v2f64, \
    \
    vec_op_x86_sse_v16int8: vec_op_x86_##version##_##name##_v16i8, \
    \
    vec_op_x86_sse_v8int16: vec_op_x86_##version##_##name##_v8i16, \
    \
    vec_op_x86_sse_v4int32: vec_op_x86_##version##_##name##_v4i32, \
    \
    vec_op_x86_sse_v2int64: vec_op_x86_##version##_##name##_v2i64 */\
))

#define VEC_OP_FUNC_SSE(type, name) VEC_OP_FUNC_SSEv(type, name, sse)
#define VEC_OP_FUNC_SSE2(type, name) VEC_OP_FUNC_SSEv(type, name, sse2)
#define VEC_OP_FUNC_SSE3(type, name) VEC_OP_FUNC_SSEv(type, name, sse3)
#define VEC_OP_FUNC_SSSE3(type, name) VEC_OP_FUNC_SSEv(type, name, ssse3)
#define VEC_OP_FUNC_SSE4_1(type, name) VEC_OP_FUNC_SSEv(type, name, sse4_1)
#define VEC_OP_FUNC_SSE4_2(type, name) VEC_OP_FUNC_SSEv(type, name, sse4_2)
#define VEC_OP_FUNC_SSE5(type, name) VEC_OP_FUNC_SSEv(type, name, sse5)



//float32
static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_make_v4f32(float v0, float v1, float v2, float v3)
{
    return _mm_load_ps((float[4]){ v0, v1, v2, v3 });
}
#define vec_op_x86_sse2_make_v4f32 vec_op_x86_sse_make_v4f32
#define vec_op_x86_sse3_make_v4f32 vec_op_x86_sse2_make_v4f32
#define vec_op_x86_ssse3_make_v4f32 vec_op_x86_sse3_make_v4f32
#define vec_op_x86_sse4_1_make_v4f32 vec_op_x86_ssse3_make_v4f32
#define vec_op_x86_sse4_2_make_v4f32 vec_op_x86_sse4_1_make_v4f32
#define vec_op_x86_sse5_make_v4f32 vec_op_x86_sse4_2_make_v4f32

static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_fill_v4f32(float v0)
{
    return _mm_set1_ps(v0);
}
#define vec_op_x86_sse2_fill_v4f32 vec_op_x86_sse_fill_v4f32
#define vec_op_x86_sse3_fill_v4f32 vec_op_x86_sse2_fill_v4f32
#define vec_op_x86_ssse3_fill_v4f32 vec_op_x86_sse3_fill_v4f32
#define vec_op_x86_sse4_1_fill_v4f32 vec_op_x86_ssse3_fill_v4f32
#define vec_op_x86_sse4_2_fill_v4f32 vec_op_x86_sse4_1_fill_v4f32
static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse5_fill_v4f32(float v0){return vec_op_x86_sse4_2_fill_v4f32(v0);}


static VEC_OP_INLINE float vec_op_x86_sse_get_v4f32(vec_op_x86_sse_v4float32 v, size_t Index)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    float Val[4];
    _mm_store_ps(Val, v);
    return Val[Index];
}
#define vec_op_x86_sse2_get_v4f32 vec_op_x86_sse_get_v4f32
#define vec_op_x86_sse3_get_v4f32 vec_op_x86_sse2_get_v4f32
#define vec_op_x86_ssse3_get_v4f32 vec_op_x86_sse3_get_v4f32
#define vec_op_x86_sse4_1_get_v4f32 vec_op_x86_ssse3_get_v4f32
#define vec_op_x86_sse4_2_get_v4f32 vec_op_x86_sse4_1_get_v4f32
#define vec_op_x86_sse5_get_v4f32 vec_op_x86_sse4_2_get_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_set_v4f32(vec_op_x86_sse_v4float32 v, size_t Index, float Value)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(Index < 4);
#endif
    float Val[4];
    _mm_store_ps(Val, v);
    Val[Index] = Value;
    return _mm_load_ps(Val);
}
#define vec_op_x86_sse2_set_v4f32 vec_op_x86_sse_set_v4f32
#define vec_op_x86_sse3_set_v4f32 vec_op_x86_sse2_set_v4f32
#define vec_op_x86_ssse3_set_v4f32 vec_op_x86_sse3_set_v4f32
#define vec_op_x86_sse4_1_set_v4f32 vec_op_x86_ssse3_set_v4f32
#define vec_op_x86_sse4_2_set_v4f32 vec_op_x86_sse4_1_set_v4f32
#define vec_op_x86_sse5_set_v4f32 vec_op_x86_sse4_2_set_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_swizzle_v4f32(vec_op_x86_sse_v4float32 a, size_t v0, size_t v1, size_t v2, size_t v3)
{
#if VEC_OP_USE_SAFETY_CHECKS
    assert(v0 < 4 && v1 < 4 && v2 < 4 && v3 < 4);
#endif
    
    /*
     Assume the compiler will know if it's known at compile-time input (for all v0,v1,v2,v3) to only generate the specific case. If it isn't it would be better to
     just manually shuffle the vector, rather than having it create the entire switch statement. 
     */
    switch ((uint8_t)_MM_SHUFFLE(v3, v2, v1, v0))
    {
        case 0: return _mm_shuffle_ps(a, a, 0);
        case 1: return _mm_shuffle_ps(a, a, 1);
        case 2: return _mm_shuffle_ps(a, a, 2);
        case 3: return _mm_shuffle_ps(a, a, 3);
        case 4: return _mm_shuffle_ps(a, a, 4);
        case 5: return _mm_shuffle_ps(a, a, 5);
        case 6: return _mm_shuffle_ps(a, a, 6);
        case 7: return _mm_shuffle_ps(a, a, 7);
        case 8: return _mm_shuffle_ps(a, a, 8);
        case 9: return _mm_shuffle_ps(a, a, 9);
        case 10: return _mm_shuffle_ps(a, a, 10);
        case 11: return _mm_shuffle_ps(a, a, 11);
        case 12: return _mm_shuffle_ps(a, a, 12);
        case 13: return _mm_shuffle_ps(a, a, 13);
        case 14: return _mm_shuffle_ps(a, a, 14);
        case 15: return _mm_shuffle_ps(a, a, 15);
        case 16: return _mm_shuffle_ps(a, a, 16);
        case 17: return _mm_shuffle_ps(a, a, 17);
        case 18: return _mm_shuffle_ps(a, a, 18);
        case 19: return _mm_shuffle_ps(a, a, 19);
        case 20: return _mm_shuffle_ps(a, a, 20);
        case 21: return _mm_shuffle_ps(a, a, 21);
        case 22: return _mm_shuffle_ps(a, a, 22);
        case 23: return _mm_shuffle_ps(a, a, 23);
        case 24: return _mm_shuffle_ps(a, a, 24);
        case 25: return _mm_shuffle_ps(a, a, 25);
        case 26: return _mm_shuffle_ps(a, a, 26);
        case 27: return _mm_shuffle_ps(a, a, 27);
        case 28: return _mm_shuffle_ps(a, a, 28);
        case 29: return _mm_shuffle_ps(a, a, 29);
        case 30: return _mm_shuffle_ps(a, a, 30);
        case 31: return _mm_shuffle_ps(a, a, 31);
        case 32: return _mm_shuffle_ps(a, a, 32);
        case 33: return _mm_shuffle_ps(a, a, 33);
        case 34: return _mm_shuffle_ps(a, a, 34);
        case 35: return _mm_shuffle_ps(a, a, 35);
        case 36: return _mm_shuffle_ps(a, a, 36);
        case 37: return _mm_shuffle_ps(a, a, 37);
        case 38: return _mm_shuffle_ps(a, a, 38);
        case 39: return _mm_shuffle_ps(a, a, 39);
        case 40: return _mm_shuffle_ps(a, a, 40);
        case 41: return _mm_shuffle_ps(a, a, 41);
        case 42: return _mm_shuffle_ps(a, a, 42);
        case 43: return _mm_shuffle_ps(a, a, 43);
        case 44: return _mm_shuffle_ps(a, a, 44);
        case 45: return _mm_shuffle_ps(a, a, 45);
        case 46: return _mm_shuffle_ps(a, a, 46);
        case 47: return _mm_shuffle_ps(a, a, 47);
        case 48: return _mm_shuffle_ps(a, a, 48);
        case 49: return _mm_shuffle_ps(a, a, 49);
        case 50: return _mm_shuffle_ps(a, a, 50);
        case 51: return _mm_shuffle_ps(a, a, 51);
        case 52: return _mm_shuffle_ps(a, a, 52);
        case 53: return _mm_shuffle_ps(a, a, 53);
        case 54: return _mm_shuffle_ps(a, a, 54);
        case 55: return _mm_shuffle_ps(a, a, 55);
        case 56: return _mm_shuffle_ps(a, a, 56);
        case 57: return _mm_shuffle_ps(a, a, 57);
        case 58: return _mm_shuffle_ps(a, a, 58);
        case 59: return _mm_shuffle_ps(a, a, 59);
        case 60: return _mm_shuffle_ps(a, a, 60);
        case 61: return _mm_shuffle_ps(a, a, 61);
        case 62: return _mm_shuffle_ps(a, a, 62);
        case 63: return _mm_shuffle_ps(a, a, 63);
        case 64: return _mm_shuffle_ps(a, a, 64);
        case 65: return _mm_shuffle_ps(a, a, 65);
        case 66: return _mm_shuffle_ps(a, a, 66);
        case 67: return _mm_shuffle_ps(a, a, 67);
        case 68: return _mm_shuffle_ps(a, a, 68);
        case 69: return _mm_shuffle_ps(a, a, 69);
        case 70: return _mm_shuffle_ps(a, a, 70);
        case 71: return _mm_shuffle_ps(a, a, 71);
        case 72: return _mm_shuffle_ps(a, a, 72);
        case 73: return _mm_shuffle_ps(a, a, 73);
        case 74: return _mm_shuffle_ps(a, a, 74);
        case 75: return _mm_shuffle_ps(a, a, 75);
        case 76: return _mm_shuffle_ps(a, a, 76);
        case 77: return _mm_shuffle_ps(a, a, 77);
        case 78: return _mm_shuffle_ps(a, a, 78);
        case 79: return _mm_shuffle_ps(a, a, 79);
        case 80: return _mm_shuffle_ps(a, a, 80);
        case 81: return _mm_shuffle_ps(a, a, 81);
        case 82: return _mm_shuffle_ps(a, a, 82);
        case 83: return _mm_shuffle_ps(a, a, 83);
        case 84: return _mm_shuffle_ps(a, a, 84);
        case 85: return _mm_shuffle_ps(a, a, 85);
        case 86: return _mm_shuffle_ps(a, a, 86);
        case 87: return _mm_shuffle_ps(a, a, 87);
        case 88: return _mm_shuffle_ps(a, a, 88);
        case 89: return _mm_shuffle_ps(a, a, 89);
        case 90: return _mm_shuffle_ps(a, a, 90);
        case 91: return _mm_shuffle_ps(a, a, 91);
        case 92: return _mm_shuffle_ps(a, a, 92);
        case 93: return _mm_shuffle_ps(a, a, 93);
        case 94: return _mm_shuffle_ps(a, a, 94);
        case 95: return _mm_shuffle_ps(a, a, 95);
        case 96: return _mm_shuffle_ps(a, a, 96);
        case 97: return _mm_shuffle_ps(a, a, 97);
        case 98: return _mm_shuffle_ps(a, a, 98);
        case 99: return _mm_shuffle_ps(a, a, 99);
        case 100: return _mm_shuffle_ps(a, a, 100);
        case 101: return _mm_shuffle_ps(a, a, 101);
        case 102: return _mm_shuffle_ps(a, a, 102);
        case 103: return _mm_shuffle_ps(a, a, 103);
        case 104: return _mm_shuffle_ps(a, a, 104);
        case 105: return _mm_shuffle_ps(a, a, 105);
        case 106: return _mm_shuffle_ps(a, a, 106);
        case 107: return _mm_shuffle_ps(a, a, 107);
        case 108: return _mm_shuffle_ps(a, a, 108);
        case 109: return _mm_shuffle_ps(a, a, 109);
        case 110: return _mm_shuffle_ps(a, a, 110);
        case 111: return _mm_shuffle_ps(a, a, 111);
        case 112: return _mm_shuffle_ps(a, a, 112);
        case 113: return _mm_shuffle_ps(a, a, 113);
        case 114: return _mm_shuffle_ps(a, a, 114);
        case 115: return _mm_shuffle_ps(a, a, 115);
        case 116: return _mm_shuffle_ps(a, a, 116);
        case 117: return _mm_shuffle_ps(a, a, 117);
        case 118: return _mm_shuffle_ps(a, a, 118);
        case 119: return _mm_shuffle_ps(a, a, 119);
        case 120: return _mm_shuffle_ps(a, a, 120);
        case 121: return _mm_shuffle_ps(a, a, 121);
        case 122: return _mm_shuffle_ps(a, a, 122);
        case 123: return _mm_shuffle_ps(a, a, 123);
        case 124: return _mm_shuffle_ps(a, a, 124);
        case 125: return _mm_shuffle_ps(a, a, 125);
        case 126: return _mm_shuffle_ps(a, a, 126);
        case 127: return _mm_shuffle_ps(a, a, 127);
        case 128: return _mm_shuffle_ps(a, a, 128);
        case 129: return _mm_shuffle_ps(a, a, 129);
        case 130: return _mm_shuffle_ps(a, a, 130);
        case 131: return _mm_shuffle_ps(a, a, 131);
        case 132: return _mm_shuffle_ps(a, a, 132);
        case 133: return _mm_shuffle_ps(a, a, 133);
        case 134: return _mm_shuffle_ps(a, a, 134);
        case 135: return _mm_shuffle_ps(a, a, 135);
        case 136: return _mm_shuffle_ps(a, a, 136);
        case 137: return _mm_shuffle_ps(a, a, 137);
        case 138: return _mm_shuffle_ps(a, a, 138);
        case 139: return _mm_shuffle_ps(a, a, 139);
        case 140: return _mm_shuffle_ps(a, a, 140);
        case 141: return _mm_shuffle_ps(a, a, 141);
        case 142: return _mm_shuffle_ps(a, a, 142);
        case 143: return _mm_shuffle_ps(a, a, 143);
        case 144: return _mm_shuffle_ps(a, a, 144);
        case 145: return _mm_shuffle_ps(a, a, 145);
        case 146: return _mm_shuffle_ps(a, a, 146);
        case 147: return _mm_shuffle_ps(a, a, 147);
        case 148: return _mm_shuffle_ps(a, a, 148);
        case 149: return _mm_shuffle_ps(a, a, 149);
        case 150: return _mm_shuffle_ps(a, a, 150);
        case 151: return _mm_shuffle_ps(a, a, 151);
        case 152: return _mm_shuffle_ps(a, a, 152);
        case 153: return _mm_shuffle_ps(a, a, 153);
        case 154: return _mm_shuffle_ps(a, a, 154);
        case 155: return _mm_shuffle_ps(a, a, 155);
        case 156: return _mm_shuffle_ps(a, a, 156);
        case 157: return _mm_shuffle_ps(a, a, 157);
        case 158: return _mm_shuffle_ps(a, a, 158);
        case 159: return _mm_shuffle_ps(a, a, 159);
        case 160: return _mm_shuffle_ps(a, a, 160);
        case 161: return _mm_shuffle_ps(a, a, 161);
        case 162: return _mm_shuffle_ps(a, a, 162);
        case 163: return _mm_shuffle_ps(a, a, 163);
        case 164: return _mm_shuffle_ps(a, a, 164);
        case 165: return _mm_shuffle_ps(a, a, 165);
        case 166: return _mm_shuffle_ps(a, a, 166);
        case 167: return _mm_shuffle_ps(a, a, 167);
        case 168: return _mm_shuffle_ps(a, a, 168);
        case 169: return _mm_shuffle_ps(a, a, 169);
        case 170: return _mm_shuffle_ps(a, a, 170);
        case 171: return _mm_shuffle_ps(a, a, 171);
        case 172: return _mm_shuffle_ps(a, a, 172);
        case 173: return _mm_shuffle_ps(a, a, 173);
        case 174: return _mm_shuffle_ps(a, a, 174);
        case 175: return _mm_shuffle_ps(a, a, 175);
        case 176: return _mm_shuffle_ps(a, a, 176);
        case 177: return _mm_shuffle_ps(a, a, 177);
        case 178: return _mm_shuffle_ps(a, a, 178);
        case 179: return _mm_shuffle_ps(a, a, 179);
        case 180: return _mm_shuffle_ps(a, a, 180);
        case 181: return _mm_shuffle_ps(a, a, 181);
        case 182: return _mm_shuffle_ps(a, a, 182);
        case 183: return _mm_shuffle_ps(a, a, 183);
        case 184: return _mm_shuffle_ps(a, a, 184);
        case 185: return _mm_shuffle_ps(a, a, 185);
        case 186: return _mm_shuffle_ps(a, a, 186);
        case 187: return _mm_shuffle_ps(a, a, 187);
        case 188: return _mm_shuffle_ps(a, a, 188);
        case 189: return _mm_shuffle_ps(a, a, 189);
        case 190: return _mm_shuffle_ps(a, a, 190);
        case 191: return _mm_shuffle_ps(a, a, 191);
        case 192: return _mm_shuffle_ps(a, a, 192);
        case 193: return _mm_shuffle_ps(a, a, 193);
        case 194: return _mm_shuffle_ps(a, a, 194);
        case 195: return _mm_shuffle_ps(a, a, 195);
        case 196: return _mm_shuffle_ps(a, a, 196);
        case 197: return _mm_shuffle_ps(a, a, 197);
        case 198: return _mm_shuffle_ps(a, a, 198);
        case 199: return _mm_shuffle_ps(a, a, 199);
        case 200: return _mm_shuffle_ps(a, a, 200);
        case 201: return _mm_shuffle_ps(a, a, 201);
        case 202: return _mm_shuffle_ps(a, a, 202);
        case 203: return _mm_shuffle_ps(a, a, 203);
        case 204: return _mm_shuffle_ps(a, a, 204);
        case 205: return _mm_shuffle_ps(a, a, 205);
        case 206: return _mm_shuffle_ps(a, a, 206);
        case 207: return _mm_shuffle_ps(a, a, 207);
        case 208: return _mm_shuffle_ps(a, a, 208);
        case 209: return _mm_shuffle_ps(a, a, 209);
        case 210: return _mm_shuffle_ps(a, a, 210);
        case 211: return _mm_shuffle_ps(a, a, 211);
        case 212: return _mm_shuffle_ps(a, a, 212);
        case 213: return _mm_shuffle_ps(a, a, 213);
        case 214: return _mm_shuffle_ps(a, a, 214);
        case 215: return _mm_shuffle_ps(a, a, 215);
        case 216: return _mm_shuffle_ps(a, a, 216);
        case 217: return _mm_shuffle_ps(a, a, 217);
        case 218: return _mm_shuffle_ps(a, a, 218);
        case 219: return _mm_shuffle_ps(a, a, 219);
        case 220: return _mm_shuffle_ps(a, a, 220);
        case 221: return _mm_shuffle_ps(a, a, 221);
        case 222: return _mm_shuffle_ps(a, a, 222);
        case 223: return _mm_shuffle_ps(a, a, 223);
        case 224: return _mm_shuffle_ps(a, a, 224);
        case 225: return _mm_shuffle_ps(a, a, 225);
        case 226: return _mm_shuffle_ps(a, a, 226);
        case 227: return _mm_shuffle_ps(a, a, 227);
        case 228: return a; //assume the compiler optimzes the rest of the shuffles appropriately
        case 229: return _mm_shuffle_ps(a, a, 229);
        case 230: return _mm_shuffle_ps(a, a, 230);
        case 231: return _mm_shuffle_ps(a, a, 231);
        case 232: return _mm_shuffle_ps(a, a, 232);
        case 233: return _mm_shuffle_ps(a, a, 233);
        case 234: return _mm_shuffle_ps(a, a, 234);
        case 235: return _mm_shuffle_ps(a, a, 235);
        case 236: return _mm_shuffle_ps(a, a, 236);
        case 237: return _mm_shuffle_ps(a, a, 237);
        case 238: return _mm_shuffle_ps(a, a, 238);
        case 239: return _mm_shuffle_ps(a, a, 239);
        case 240: return _mm_shuffle_ps(a, a, 240);
        case 241: return _mm_shuffle_ps(a, a, 241);
        case 242: return _mm_shuffle_ps(a, a, 242);
        case 243: return _mm_shuffle_ps(a, a, 243);
        case 244: return _mm_shuffle_ps(a, a, 244);
        case 245: return _mm_shuffle_ps(a, a, 245);
        case 246: return _mm_shuffle_ps(a, a, 246);
        case 247: return _mm_shuffle_ps(a, a, 247);
        case 248: return _mm_shuffle_ps(a, a, 248);
        case 249: return _mm_shuffle_ps(a, a, 249);
        case 250: return _mm_shuffle_ps(a, a, 250);
        case 251: return _mm_shuffle_ps(a, a, 251);
        case 252: return _mm_shuffle_ps(a, a, 252);
        case 253: return _mm_shuffle_ps(a, a, 253);
        case 254: return _mm_shuffle_ps(a, a, 254);
        case 255: return _mm_shuffle_ps(a, a, 255);
    }
    
    return a; //won't reach, but to shut up compiler
}
#define vec_op_x86_sse2_swizzle_v4f32 vec_op_x86_sse_swizzle_v4f32
#define vec_op_x86_sse3_swizzle_v4f32 vec_op_x86_sse2_swizzle_v4f32
#define vec_op_x86_ssse3_swizzle_v4f32 vec_op_x86_sse3_swizzle_v4f32
#define vec_op_x86_sse4_1_swizzle_v4f32 vec_op_x86_ssse3_swizzle_v4f32
#define vec_op_x86_sse4_2_swizzle_v4f32 vec_op_x86_sse4_1_swizzle_v4f32
#define vec_op_x86_sse5_swizzle_v4f32 vec_op_x86_sse4_2_swizzle_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_add_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_add_ps(a, b);
}
#define vec_op_x86_sse2_add_v4f32 vec_op_x86_sse_add_v4f32
#define vec_op_x86_sse3_add_v4f32 vec_op_x86_sse2_add_v4f32
#define vec_op_x86_ssse3_add_v4f32 vec_op_x86_sse3_add_v4f32
#define vec_op_x86_sse4_1_add_v4f32 vec_op_x86_ssse3_add_v4f32
#define vec_op_x86_sse4_2_add_v4f32 vec_op_x86_sse4_1_add_v4f32
#define vec_op_x86_sse5_add_v4f32 vec_op_x86_sse4_2_add_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_sub_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_sub_ps(a, b);
}
#define vec_op_x86_sse2_sub_v4f32 vec_op_x86_sse_sub_v4f32
#define vec_op_x86_sse3_sub_v4f32 vec_op_x86_sse2_sub_v4f32
#define vec_op_x86_ssse3_sub_v4f32 vec_op_x86_sse3_sub_v4f32
#define vec_op_x86_sse4_1_sub_v4f32 vec_op_x86_ssse3_sub_v4f32
#define vec_op_x86_sse4_2_sub_v4f32 vec_op_x86_sse4_1_sub_v4f32
#define vec_op_x86_sse5_sub_v4f32 vec_op_x86_sse4_2_sub_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_mul_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_mul_ps(a, b);
}
#define vec_op_x86_sse2_mul_v4f32 vec_op_x86_sse_mul_v4f32
#define vec_op_x86_sse3_mul_v4f32 vec_op_x86_sse2_mul_v4f32
#define vec_op_x86_ssse3_mul_v4f32 vec_op_x86_sse3_mul_v4f32
#define vec_op_x86_sse4_1_mul_v4f32 vec_op_x86_ssse3_mul_v4f32
#define vec_op_x86_sse4_2_mul_v4f32 vec_op_x86_sse4_1_mul_v4f32
#define vec_op_x86_sse5_mul_v4f32 vec_op_x86_sse4_2_mul_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_div_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_div_ps(a, b);
}
#define vec_op_x86_sse2_div_v4f32 vec_op_x86_sse_div_v4f32
#define vec_op_x86_sse3_div_v4f32 vec_op_x86_sse2_div_v4f32
#define vec_op_x86_ssse3_div_v4f32 vec_op_x86_sse3_div_v4f32
#define vec_op_x86_sse4_1_div_v4f32 vec_op_x86_ssse3_div_v4f32
#define vec_op_x86_sse4_2_div_v4f32 vec_op_x86_sse4_1_div_v4f32
#define vec_op_x86_sse5_div_v4f32 vec_op_x86_sse4_2_div_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_recip_v4f32(vec_op_x86_sse_v4float32 a)
{
    return _mm_rcp_ps(a);
}
#define vec_op_x86_sse2_recip_v4f32 vec_op_x86_sse_recip_v4f32
#define vec_op_x86_sse3_recip_v4f32 vec_op_x86_sse2_recip_v4f32
#define vec_op_x86_ssse3_recip_v4f32 vec_op_x86_sse3_recip_v4f32
#define vec_op_x86_sse4_1_recip_v4f32 vec_op_x86_ssse3_recip_v4f32
#define vec_op_x86_sse4_2_recip_v4f32 vec_op_x86_sse4_1_recip_v4f32
#define vec_op_x86_sse5_recip_v4f32 vec_op_x86_sse4_2_recip_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_sqrt_v4f32(vec_op_x86_sse_v4float32 a)
{
    return _mm_sqrt_ps(a);
}
#define vec_op_x86_sse2_sqrt_v4f32 vec_op_x86_sse_sqrt_v4f32
#define vec_op_x86_sse3_sqrt_v4f32 vec_op_x86_sse2_sqrt_v4f32
#define vec_op_x86_ssse3_sqrt_v4f32 vec_op_x86_sse3_sqrt_v4f32
#define vec_op_x86_sse4_1_sqrt_v4f32 vec_op_x86_ssse3_sqrt_v4f32
#define vec_op_x86_sse4_2_sqrt_v4f32 vec_op_x86_sse4_1_sqrt_v4f32
#define vec_op_x86_sse5_sqrt_v4f32 vec_op_x86_sse4_2_sqrt_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_rsqrt_v4f32(vec_op_x86_sse_v4float32 a)
{
    return _mm_rsqrt_ps(a);
}
#define vec_op_x86_sse2_rsqrt_v4f32 vec_op_x86_sse_rsqrt_v4f32
#define vec_op_x86_sse3_rsqrt_v4f32 vec_op_x86_sse2_rsqrt_v4f32
#define vec_op_x86_ssse3_rsqrt_v4f32 vec_op_x86_sse3_rsqrt_v4f32
#define vec_op_x86_sse4_1_rsqrt_v4f32 vec_op_x86_ssse3_rsqrt_v4f32
#define vec_op_x86_sse4_2_rsqrt_v4f32 vec_op_x86_sse4_1_rsqrt_v4f32
#define vec_op_x86_sse5_rsqrt_v4f32 vec_op_x86_sse4_2_rsqrt_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_min_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_min_ps(a, b);
}
#define vec_op_x86_sse2_min_v4f32 vec_op_x86_sse_min_v4f32
#define vec_op_x86_sse3_min_v4f32 vec_op_x86_sse2_min_v4f32
#define vec_op_x86_ssse3_min_v4f32 vec_op_x86_sse3_min_v4f32
#define vec_op_x86_sse4_1_min_v4f32 vec_op_x86_ssse3_min_v4f32
#define vec_op_x86_sse4_2_min_v4f32 vec_op_x86_sse4_1_min_v4f32
#define vec_op_x86_sse5_min_v4f32 vec_op_x86_sse4_2_min_v4f32


static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_max_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_max_ps(a, b);
}
#define vec_op_x86_sse2_max_v4f32 vec_op_x86_sse_max_v4f32
#define vec_op_x86_sse3_max_v4f32 vec_op_x86_sse2_max_v4f32
#define vec_op_x86_ssse3_max_v4f32 vec_op_x86_sse3_max_v4f32
#define vec_op_x86_sse4_1_max_v4f32 vec_op_x86_ssse3_max_v4f32
#define vec_op_x86_sse4_2_max_v4f32 vec_op_x86_sse4_1_max_v4f32
#define vec_op_x86_sse5_max_v4f32 vec_op_x86_sse4_2_max_v4f32


#if __SSE4_1__
static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse4_1_dot_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return _mm_dp_ps(a, b, 0xff);
}
#else
#define vec_op_x86_sse4_1_dot_v4f32 vec_op_x86_ssse3_dot_v4f32
#endif
#if __SSE3__
static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse3_dot_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    vec_op_x86_sse_v4float32 Temp = vec_op_x86_sse3_mul_v4f32(a, b);
    Temp = _mm_hadd_ps(_mm_hadd_ps(Temp, Temp), Temp);
    
    return vec_op_x86_sse3_swizzle_v4f32(Temp, VEC_OP_V0, VEC_OP_V1, VEC_OP_V0, VEC_OP_V1);
}
#else
#define vec_op_x86_sse3_dot_v4f32 vec_op_x86_sse2_dot_v4f32
#endif
static VEC_OP_INLINE vec_op_x86_sse_v4float32 vec_op_x86_sse_dot_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    //could be written to use fewer instructions, however would then have more read dependencies. though here we have to hope there's no register spillage (e.g. forcing loads/stores).
    vec_op_x86_sse_v4float32 TempXYZW = vec_op_x86_sse_mul_v4f32(a, b);
    vec_op_x86_sse_v4float32 TempYZWX = vec_op_x86_sse_swizzle_v4f32(TempXYZW, VEC_OP_V1, VEC_OP_V2, VEC_OP_V3, VEC_OP_V0);
    vec_op_x86_sse_v4float32 TempZWXY = vec_op_x86_sse_swizzle_v4f32(TempXYZW, VEC_OP_V2, VEC_OP_V3, VEC_OP_V0, VEC_OP_V1);
    vec_op_x86_sse_v4float32 TempWXYZ = vec_op_x86_sse_swizzle_v4f32(TempXYZW, VEC_OP_V3, VEC_OP_V0, VEC_OP_V1, VEC_OP_V2);
    
    vec_op_x86_sse_v4float32 TempA = vec_op_x86_sse_add_v4f32(TempXYZW, TempYZWX);
    vec_op_x86_sse_v4float32 TempB = vec_op_x86_sse_add_v4f32(TempZWXY, TempWXYZ);
    
    return vec_op_x86_sse_add_v4f32(TempA, TempB);
}
#define vec_op_x86_sse2_dot_v4f32 vec_op_x86_sse_dot_v4f32
#define vec_op_x86_ssse3_dot_v4f32 vec_op_x86_sse3_dot_v4f32
#define vec_op_x86_sse4_2_dot_v4f32 vec_op_x86_sse4_1_dot_v4f32
#define vec_op_x86_sse5_dot_v4f32 vec_op_x86_sse4_2_dot_v4f32


static VEC_OP_INLINE float vec_op_x86_sse4_1_dots_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return vec_op_x86_sse4_1_get_v4f32(vec_op_x86_sse4_1_dot_v4f32(a, b), VEC_OP_V0);
}
#if __SSE3__
static VEC_OP_INLINE float vec_op_x86_sse3_dots_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    vec_op_x86_sse_v4float32 Temp = vec_op_x86_sse3_mul_v4f32(a, b);
    return vec_op_x86_sse3_get_v4f32(_mm_hadd_ps(_mm_hadd_ps(Temp, Temp), Temp), VEC_OP_V0);
}
#else
#define vec_op_x86_sse3_dots_v4f32 vec_op_x86_sse2_dots_v4f32
#endif
static VEC_OP_INLINE float vec_op_x86_sse_dots_v4f32(vec_op_x86_sse_v4float32 a, vec_op_x86_sse_v4float32 b)
{
    return vec_op_x86_sse_get_v4f32(vec_op_x86_sse_dot_v4f32(a, b), VEC_OP_V0);
}
#define vec_op_x86_sse2_dots_v4f32 vec_op_x86_sse_dots_v4f32
#define vec_op_x86_ssse3_dots_v4f32 vec_op_x86_sse3_dots_v4f32
#define vec_op_x86_sse4_2_dots_v4f32 vec_op_x86_sse4_1_dots_v4f32
#define vec_op_x86_sse5_dots_v4f32 vec_op_x86_sse4_2_dots_v4f32

#endif



#undef VEC_OP_X86_SSE_HIGHEST_ALLOWED
#undef VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION

#if VEC_OP_FORCE_NO_X86_SSE2
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE(type, name)
#elif VEC_OP_FORCE_NO_X86_SSE3
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE2
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE2(type, name)
#elif VEC_OP_FORCE_NO_X86_SSSE3
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE3
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE3(type, name)
#elif VEC_OP_FORCE_NO_X86_SSE4_1
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSSE3
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSSE3(type, name)
#elif VEC_OP_FORCE_NO_X86_SSE4_2
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE4_1
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE4_1(type, name)
#elif VEC_OP_FORCE_NO_X86_SSE5
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE4_2
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE4_2(type, name)
#else
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED VEC_OP_X86_SSE5
#define VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(type, name) VEC_OP_FUNC_SSE5(type, name)
#endif


//vector float32's
#if !VEC_OP_SUPPORTS_VF32
#define VEC_OP_SUPPORTS_VF32 VEC_OP_X86_SSE_HIGHEST_ALLOWED

#define vfloat32_t vec_op_x86_sse_vfloat32
#define vf32make VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, make)
#define vf32fill VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, fill)
#define vf32get VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, get)
#define vf32set VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, set)
#define vf32swizzle VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, swizzle)
#define vf32add VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, add)
#define vf32sub VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, sub)
#define vf32mul VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, mul)
#define vf32div VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, div)
#define vf32recip VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, recip)
#define vf32sqrt VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, sqrt)
#define vf32rsqrt VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, rsqrt)
#define vf32min VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, min)
#define vf32max VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, max)
#define vf32dot VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, dot)
#define vf32dots VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(vfloat32_t, dots)
#endif


#if !VEC_OP_SUPPORTS_V4F32
#define VEC_OP_SUPPORTS_V4F32 VEC_OP_X86_SSE_HIGHEST_ALLOWED

#define v4float32_t vec_op_x86_sse_v4float32
#define v4f32make VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, make)
#define v4f32fill VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, fill)
#define v4f32get VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, get)
#define v4f32set VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, set)
#define v4f32swizzle VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, swizzle)
#define v4f32add VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, add)
#define v4f32sub VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, sub)
#define v4f32mul VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, mul)
#define v4f32div VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, div)
#define v4f32recip VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, recip)
#define v4f32sqrt VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, sqrt)
#define v4f32rsqrt VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, rsqrt)
#define v4f32min VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, min)
#define v4f32max VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, max)
#define v4f32dot VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, dot)
#define v4f32dots VEC_OP_X86_SSE_HIGHEST_ALLOWED_FUNCTION(v4float32_t, dots)
#endif

