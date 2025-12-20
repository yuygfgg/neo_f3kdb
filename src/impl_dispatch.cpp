#include "core.h"

#define IMPL_DISPATCH_IMPORT_DECLARATION

#include "impl_dispatch_decl.h"

#if defined(__x86_64__) || defined(__i386__) || defined(_M_X64) || defined(_M_IX86)
#define NEO_F3KDB_HAS_X86_SIMD 1
#define NEO_F3KDB_HAS_SSE4_IMPL 1
#elif defined(__aarch64__) || defined(__arm__) || defined(_M_ARM)
#define NEO_F3KDB_HAS_X86_SIMD 0
#define NEO_F3KDB_HAS_SSE4_IMPL 1
#else
#define NEO_F3KDB_HAS_X86_SIMD 0
#define NEO_F3KDB_HAS_SSE4_IMPL 0
#endif

const process_plane_impl_t* process_plane_impl_high_precision_no_dithering[] = {
    process_plane_impl_c_high_no_dithering,
    process_plane_impl_c_high_no_dithering,
    process_plane_impl_c_high_no_dithering,
    NEO_F3KDB_HAS_SSE4_IMPL ? process_plane_impl_sse4_high_no_dithering : process_plane_impl_c_high_no_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx2_high_no_dithering : process_plane_impl_c_high_no_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx512_high_no_dithering : process_plane_impl_c_high_no_dithering,
};

const process_plane_impl_t* process_plane_impl_high_precision_ordered_dithering[] = {
    process_plane_impl_c_high_ordered_dithering,
    process_plane_impl_c_high_ordered_dithering,
    process_plane_impl_c_high_ordered_dithering,
    NEO_F3KDB_HAS_SSE4_IMPL ? process_plane_impl_sse4_high_ordered_dithering : process_plane_impl_c_high_ordered_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx2_high_ordered_dithering : process_plane_impl_c_high_ordered_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx512_high_ordered_dithering : process_plane_impl_c_high_ordered_dithering,
};

const process_plane_impl_t* process_plane_impl_high_precision_floyd_steinberg_dithering[] = {
    process_plane_impl_c_high_floyd_steinberg_dithering,
    process_plane_impl_c_high_floyd_steinberg_dithering,
    process_plane_impl_c_high_floyd_steinberg_dithering,
    NEO_F3KDB_HAS_SSE4_IMPL ? process_plane_impl_sse4_high_floyd_steinberg_dithering : process_plane_impl_c_high_floyd_steinberg_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx2_high_floyd_steinberg_dithering : process_plane_impl_c_high_floyd_steinberg_dithering,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx512_high_floyd_steinberg_dithering : process_plane_impl_c_high_floyd_steinberg_dithering,
};

const process_plane_impl_t* process_plane_impl_16bit_interleaved[] = {
    process_plane_impl_c_16bit_interleaved,
    process_plane_impl_c_16bit_interleaved,
    process_plane_impl_c_16bit_interleaved,
    NEO_F3KDB_HAS_SSE4_IMPL ? process_plane_impl_sse4_16bit_interleaved : process_plane_impl_c_16bit_interleaved,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx2_16bit_interleaved : process_plane_impl_c_16bit_interleaved,
    NEO_F3KDB_HAS_X86_SIMD ? process_plane_impl_avx512_16bit_interleaved : process_plane_impl_c_16bit_interleaved,
};


const process_plane_impl_t** process_plane_impls[] = {
	nullptr, // process_plane_impl_low_precision has been removed,
	process_plane_impl_high_precision_no_dithering,
	process_plane_impl_high_precision_ordered_dithering,
	process_plane_impl_high_precision_floyd_steinberg_dithering,
    process_plane_impl_16bit_interleaved
};
