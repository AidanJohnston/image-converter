// types.h
#ifndef __TYPES_H_
#define __TYPES_H_

#include <vector>

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed char  s8;
typedef signed short s16;
typedef signed int   s32;

typedef std::vector<u8> bytes;


/* Start of Frame Types
 * nondifferential huffman-coding frames
 * Describes which DCT algorithm to use
 *
 * N: non
 * DIFF: differential
 * BASE: baseline
 * DCT: Discrete cosine transformation
 * EXT: extended
 * LOSS: lossless
 * PRO: progressive
 * AR: arithmetic
 */

#define N_DIFF_BASE_DCT 0xC0
#define N_DIFF_EXT_SEQ_DCT 0xC1
#define N_DIFF_PRO_DCT 0xC2
#define N_DIFF_LOSS 0xC3

// differential huffman-coding frames
#define DIFF_SEQ_DCT 0xC5
#define DIFF_PRO_DCT 0xC6
#define DIFF_LOSS 0xC7

// nondifferential arithmetic-coding frames
#define N_DIFF_AR_EXT_SEQ_DCT 0xC9
#define N_DIFF_AR_PRO_DCT 0xCA
#define N_DIFF_AR_LOSS 0xCB

// differential arithmetic-coding frames
#define DIFF_AR_EXT_SEQ_DCT 0xCD
#define DIFF_AR_PRO_DCT 0xCE
#define DIFF_AR_LOSS 0xCF

#endif//__TYPES_H_