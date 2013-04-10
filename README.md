VecOp
=====

A vector/SIMD (when available) implementation. This refers to vectorization, not to be confused with vector math (though would ideally use it to build a vector math library).

DO NOT USE!!!
=============

This is an incomplete implementation of what one would expect from a vector library. So it is not ready for actual use. It's missing lots of expected functionality from loads/stores, conditionals, packs/unpacks, logical/bitwise operations, type conversions, etc. It's possible I may finish it off at one point, but it's better to assume I won't as this was more of an experimentation rather than something I want to create.


A little about it
-----------------
I thought this was an interesting way to go about implementing a vector library. As it provides a simple context for supporting the architecture SIMD, to falling back to the compiler vector extensions and letting it try to use SIMD if available, to falling back to a naive portable implementation. It also provides a useful way to debug and test. As you can force different implementations to be used or not used.

As far as debugging is concerned what I would've also liked to have added would be (define enabled) floating point type checks before every operation. In other words if it was enabled it would log whether the current value is a denormal, NAN, infinite, etc. Which can be useful to help with understanding how to go about optimizing your algorithms, as in many architectures those types of things (especially denormals) are quite costly.

The biggest problem with it is easily the scale of it, and how it is not very maintainable. Most of it can just be generated from some scripts, but as soon as you get to the architecture specific implementations then this gets really tedious. 

The speed
---------
This approach performs reasonably well. If needing to support many platforms then falling back to compiler vector extensions before falling back to the unoptimal code, is quite good for at least speeding up what wouldn't have been sped up (assuming it's even supported, otherwise would translate to the same machine code). But this design for the architecture specific optimizations is still a bit of a problem, compared to hand written asm.

For instance:

    static VEC_OP_INLINE float vec_op_x86_sse_get_v4f32(vec_op_x86_sse_v4float32 v, size_t Index)
    {
    #if VEC_OP_USE_SAFETY_CHECKS
        assert(Index < 4);
    #endif
        float Val[4];
        _mm_store_ps(Val, v);
        return Val[Index];
    }

In this function we just have to hope the compiler uses the most optimal case, which with the above code is somewhat unlikely.

The optimal generation would be dependant on knowing the ABI for the current platform, so we know the calling convention and storage. And being able to produce different instructions based on the input.

On Mac OS X targeting x86_64 it follows the System V ABI (with some exceptions), so SSE class arguments get passed using xmm0-xmm7, and SSE class returns can use xmm0-xmm1. In this case the argument v will be stored in xmm0 and the returned float will be stored in the scalar position of xmm0.

So the optimal version of this function would be one that can guarantee the generation of the code following these guides: If the Index is already the Index of the scalar portion of xmm0 then it should not generate anything, if the Index isn't then it should reposition the value at that Index in the xmm0 register to the scalar position of it (using a shuffle or something) in xmm0.


The other area is to do with end usage of these inline functions (assuming the generated code gets inlined, compiling with Clang or GCC it will). As it's then dependant on the programmer (and the compiler) to try structure their code to avoid register spillage, take advantage of parallelizing instructions, limiting stalls (read/write waits), and trying to code optimally for the instruction cache.

Examples
--------
    #include "VecOp.h"

    vfloat32_t normalize1(vfloat32_t a)
    {
        return vdiv(a, vsqrt(vdot(a, a)));
    }
    
    /*
      An example call:
        vfloat32_t v = normalize1(vf32make(1.0f, 2.0f, 3.0f, 4.0f));
        printf("%f,%f,%f,%f\n", vget(v, VEC_OP_V0), vget(v, VEC_OP_V1), vget(v, VEC_OP_V2), vget(v, VEC_OP_V3));
    */
    
    #define VEC_OP_FORCE_NO_X86_SSE 1
    #include "VecOp.h"
    
    vfloat32_t normalize2(vfloat32_t a)
    {
        return vdiv(a, vsqrt(vdot(a, a)));
    }
    
    #define VEC_OP_FORCE_STANDARD 1
    #include "VecOp.h"
    
    vfloat32_t normalize3(vfloat32_t a)
    {
        return vdiv(a, vsqrt(vdot(a, a)));
    }

The above uses VecOpX86SSE for normalize1, VecOpClang for normalize2, and VecOpStd for normalize3, which generates the following code:

        .globl _normalize1
    _normalize1:
      	pushq %rbp
        movq %rsp,%rbp
    
        //the generated code
        vdpps $255,%xmm0,%xmm0,%xmm1
        vsqrtps %xmm1,%xmm1
        vdivps %xmm1,%xmm0,%xmm0
        //generated code end
    
        popq %rbp
        ret
    
        .globl _normalize2
    _normalize2:
        pushq %rbp
        movq %rsp,%rbp
    
        //the generated code
        vmulps %xmm0,%xmm0,%xmm1
        vpermilps $1,%xmm1,%xmm2
        vaddss %xmm2,%xmm1,%xmm2
        vunpckhps %xmm1,%xmm1,%xmm3
        vaddss %xmm2,%xmm3,%xmm2
        vpermilps $3,%xmm1,%xmm1
        vaddss %xmm2,%xmm1,%xmm1
        vsqrtss %xmm1,%xmm0,%xmm1
        vpermilps $0,%xmm1,%xmm1
        vdivps %xmm1,%xmm0,%xmm0
        //generated code end
    
        pop %rbp
        ret
    
        .globl _normalize3
    _normalize3:
        pushq %rbp
        movq %rsp,%rbp
    
        //the generated code
        vmulss %xmm0,%xmm0,%xmm3
        vpermilps $1,%xmm0,%xmm2
        vmulss %xmm2,%xmm2,%xmm4
        vaddss %xmm4,%xmm3,%xmm3
        vmulss %xmm1,%xmm1,%xmm4
        vaddss %xmm4,%xmm3,%xmm4
        vpermilps $1,%xmm1,%xmm3
        vmulss %xmm3,%xmm3,%xmm5
        vaddss %xmm4,%xmm5,%xmm4
        vsqrtss %xmm4,%xmm0,%xmm4
        vdivss %xmm4,%xmm1,%xmm1
        vdivss %xmm4,%xmm3,%xmm3
        vdivss %xmm4,%xmm0,%xmm0
        vdivss %xmm4,%xmm2,%xmm2
        vinsertps $16,%xmm2,%xmm0,%xmm0
        vinsertps $16,%xmm3,%xmm1,%xmm1
        //generated code end
    
        pop %rbp
        ret


