// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: powerpc-registered-target

// RUN: %clang -S -emit-llvm -target powerpc64le-unknown-linux-gnu -mcpu=pwr8 -ffreestanding -DNO_WARN_X86_INTRINSICS %s \
// RUN:   -fno-discard-value-names -mllvm -disable-llvm-optzns -o - | llvm-cxxfilt | FileCheck %s --check-prefixes=CHECK,LE
// RUN: %clang -S -emit-llvm -target powerpc64-unknown-linux-gnu -mcpu=pwr8 -ffreestanding -DNO_WARN_X86_INTRINSICS %s \
// RUN:   -fno-discard-value-names -mllvm -disable-llvm-optzns -o - | llvm-cxxfilt | FileCheck %s --check-prefixes=CHECK,BE

#include <smmintrin.h>

__m128i mi, m1, m2;

void __attribute__((noinline))
test_extract() {
  _mm_extract_epi8(mi, 0);
  _mm_extract_epi32(mi, 0);
  _mm_extract_epi64(mi, 0);
  _mm_extract_ps(mi, 0);
}

// CHECK-LABEL: @test_extract

// CHECK: define available_externally signext i32 @_mm_extract_epi8(<2 x i64> [[REG1:[0-9a-zA-Z_%.]+]], i32 signext [[REG2:[0-9a-zA-Z_%.]+]])
// CHECK: store <2 x i64> [[REG1]], <2 x i64>* [[REG3:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store i32 [[REG2]], i32* [[REG4:[0-9a-zA-Z_%.]+]], align 4
// CHECK-NEXT: [[REG5:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG3]], align 16
// CHECK-NEXT: [[REG6:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG5]] to <16 x i8>
// CHECK-NEXT: [[REG7:[0-9a-zA-Z_%.]+]] = load i32, i32* [[REG4]], align 4
// CHECK-NEXT: [[REG8:[0-9a-zA-Z_%.]+]] = and i32 [[REG7]], 15
// CHECK-NEXT: [[REG9:[0-9a-zA-Z_%.]+]] = extractelement <16 x i8> [[REG6]], i32 [[REG8]]
// CHECK-NEXT: [[REG10:[0-9a-zA-Z_%.]+]] = zext i8 [[REG9]] to i32
// CHECK-NEXT: ret i32 [[REG10]]

// CHECK: define available_externally signext i32 @_mm_extract_epi32(<2 x i64> [[REG11:[0-9a-zA-Z_%.]+]], i32 signext [[REG12:[0-9a-zA-Z_%.]+]])
// CHECK: store <2 x i64> [[REG11]], <2 x i64>* [[REG13:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store i32 [[REG12]], i32* [[REG14:[0-9a-zA-Z_%.]+]], align 4
// CHECK-NEXT: [[REG15:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG13]], align 16
// CHECK-NEXT: [[REG16:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG15]] to <4 x i32>
// CHECK-NEXT: [[REG17:[0-9a-zA-Z_%.]+]] = load i32, i32* [[REG14]], align 4
// CHECK-NEXT: [[REG18:[0-9a-zA-Z_%.]+]] = and i32 [[REG17]], 3
// CHECK-NEXT: [[REG19:[0-9a-zA-Z_%.]+]] = extractelement <4 x i32> [[REG16]], i32 [[REG18]]
// CHECK-NEXT: ret i32 [[REG19]]

// CHECK: define available_externally signext i32 @_mm_extract_epi64(<2 x i64> [[REG20:[0-9a-zA-Z_%.]+]], i32 signext [[REG21:[0-9a-zA-Z_%.]+]])
// CHECK: store <2 x i64> [[REG20]], <2 x i64>* [[REG22:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store i32 [[REG21]], i32* [[REG23:[0-9a-zA-Z_%.]+]], align 4
// CHECK-NEXT: [[REG24:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG22]], align 16
// CHECK-NEXT: [[REG25:[0-9a-zA-Z_%.]+]] = load i32, i32* [[REG23]], align 4
// CHECK-NEXT: [[REG26:[0-9a-zA-Z_%.]+]] = and i32 [[REG25]], 1
// CHECK-NEXT: [[REG27:[0-9a-zA-Z_%.]+]] = extractelement <2 x i64> [[REG24]], i32 [[REG26]]
// CHECK-NEXT: [[REG28:[0-9a-zA-Z_%.]+]] = trunc i64 [[REG27]] to i32
// CHECK-NEXT: ret i32 [[REG28]]

// CHECK: define available_externally signext i32 @_mm_extract_ps(<4 x float> [[REG29:[0-9a-zA-Z_%.]+]], i32 signext [[REG30:[0-9a-zA-Z_%.]+]])
// CHECK: store <4 x float> [[REG29]], <4 x float>* [[REG31:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store i32 [[REG30]], i32* [[REG32:[0-9a-zA-Z_%.]+]], align 4
// CHECK-NEXT: [[REG33:[0-9a-zA-Z_%.]+]] = load <4 x float>, <4 x float>* [[REG31]], align 16
// CHECK-NEXT: [[REG34:[0-9a-zA-Z_%.]+]] = bitcast <4 x float> [[REG33]] to <4 x i32>
// CHECK-NEXT: [[REG35:[0-9a-zA-Z_%.]+]] = load i32, i32* [[REG32]], align 4
// CHECK-NEXT: [[REG36:[0-9a-zA-Z_%.]+]] = and i32 [[REG35]], 3
// CHECK-NEXT: [[REG37:[0-9a-zA-Z_%.]+]] = extractelement <4 x i32> [[REG34]], i32 [[REG36]]
// CHECK-NEXT: ret i32 [[REG37]]

void __attribute__((noinline))
test_blend() {
  _mm_blend_epi16(m1, m2, 0);
  _mm_blendv_epi8(m1, m2, mi);
}

// CHECK-LABEL: @test_blend

// CHECK: define available_externally <2 x i64> @_mm_blend_epi16(<2 x i64> [[REG38:[0-9a-zA-Z_%.]+]], <2 x i64> [[REG39:[0-9a-zA-Z_%.]+]], i32 signext [[REG40:[0-9a-zA-Z_%.]+]])
// CHECK: store <2 x i64> [[REG38]], <2 x i64>* [[REG41:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store <2 x i64> [[REG39]], <2 x i64>* [[REG42:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store i32 [[REG40]], i32* [[REG43:[0-9a-zA-Z_%.]+]], align 4
// CHECK-NEXT: [[REG44:[0-9a-zA-Z_%.]+]] = load i32, i32* [[REG43]], align 4
// CHECK-NEXT: [[REG45:[0-9a-zA-Z_%.]+]] = trunc i32 [[REG44]] to i8
// CHECK-NEXT: [[REG46:[0-9a-zA-Z_%.]+]] = call <16 x i8> @vec_splats(signed char)(i8 signext [[REG45]])
// CHECK-NEXT: store <16 x i8> [[REG46]], <16 x i8>* [[REG47:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: [[REG48:[0-9a-zA-Z_%.]+]] = load <16 x i8>, <16 x i8>* [[REG47]], align 16
// CHECK-NEXT: [[REG49:[0-9a-zA-Z_%.]+]] = call <16 x i8> @llvm.ppc.altivec.vgbbd(<16 x i8> [[REG48]])
// CHECK-NEXT: store <16 x i8> [[REG49]], <16 x i8>* [[REG47]], align 16
// CHECK-NEXT: [[REG50:[0-9a-zA-Z_%.]+]] = load <16 x i8>, <16 x i8>* [[REG47]], align 16
// CHECK-NEXT: [[REG51:[0-9a-zA-Z_%.]+]] = call <8 x i16> @vec_unpackh(signed char vector[16])(<16 x i8> [[REG50]])
// CHECK-NEXT: store <8 x i16> [[REG51]], <8 x i16>* [[REG52:[0-9a-zA-Z_%.]+]], align 16

// BE: [[REG53:[0-9a-zA-Z_%.]+]] = load <8 x i16>, <8 x i16>* [[REG52]], align 16
// BE-NEXT: [[REG54:[0-9a-zA-Z_%.]+]] = call <8 x i16> @vec_reve(unsigned short vector[8])(<8 x i16> [[REG53]])
// BE-NEXT: store <8 x i16> [[REG54]], <8 x i16>* [[REG52]], align 16

// CHECK: [[REG55:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG41]], align 16
// CHECK-NEXT: [[REG56:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG55]] to <8 x i16>
// CHECK-NEXT: [[REG57:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG42]], align 16
// CHECK-NEXT: [[REG58:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG57]] to <8 x i16>
// CHECK-NEXT: [[REG59:[0-9a-zA-Z_%.]+]] = load <8 x i16>, <8 x i16>* [[REG52]], align 16
// CHECK-NEXT: [[REG60:[0-9a-zA-Z_%.]+]] = call <8 x i16> @vec_sel(unsigned short vector[8], unsigned short vector[8], unsigned short vector[8])(<8 x i16> [[REG56]], <8 x i16> [[REG58]], <8 x i16> [[REG59]])
// CHECK-NEXT: [[REG61:[0-9a-zA-Z_%.]+]] = bitcast <8 x i16> [[REG60]] to <2 x i64>
// CHECK-NEXT: ret <2 x i64> [[REG61]]

// CHECK: define available_externally <2 x i64> @_mm_blendv_epi8(<2 x i64> [[REG62:[0-9a-zA-Z_%.]+]], <2 x i64> [[REG63:[0-9a-zA-Z_%.]+]], <2 x i64> [[REG64:[0-9a-zA-Z_%.]+]])
// CHECK: store <2 x i64> [[REG62]], <2 x i64>* [[REG65:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store <2 x i64> [[REG63]], <2 x i64>* [[REG66:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: store <2 x i64> [[REG64]], <2 x i64>* [[REG67:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: [[REG68:[0-9a-zA-Z_%.]+]] = call <16 x i8> @vec_splats(unsigned char)(i8 zeroext 7)
// CHECK-NEXT: store <16 x i8> [[REG68]], <16 x i8>* [[REG69:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: [[REG70:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG67]], align 16
// CHECK-NEXT: [[REG71:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG70]] to <16 x i8>
// CHECK-NEXT: [[REG72:[0-9a-zA-Z_%.]+]] = load <16 x i8>, <16 x i8>* [[REG69]], align 16
// CHECK-NEXT: [[REG73:[0-9a-zA-Z_%.]+]] = call <16 x i8> @vec_sra(unsigned char vector[16], unsigned char vector[16])(<16 x i8> [[REG71]], <16 x i8> [[REG72]])
// CHECK-NEXT: store <16 x i8> [[REG73]], <16 x i8>* [[REG74:[0-9a-zA-Z_%.]+]], align 16
// CHECK-NEXT: [[REG75:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG65]], align 16
// CHECK-NEXT: [[REG76:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG75]] to <16 x i8>
// CHECK-NEXT: [[REG77:[0-9a-zA-Z_%.]+]] = load <2 x i64>, <2 x i64>* [[REG66]], align 16
// CHECK-NEXT: [[REG78:[0-9a-zA-Z_%.]+]] = bitcast <2 x i64> [[REG77]] to <16 x i8>
// CHECK-NEXT: [[REG79:[0-9a-zA-Z_%.]+]] = load <16 x i8>, <16 x i8>* [[REG74]], align 16
// CHECK-NEXT: [[REG80:[0-9a-zA-Z_%.]+]] = call <16 x i8> @vec_sel(unsigned char vector[16], unsigned char vector[16], unsigned char vector[16])(<16 x i8> [[REG76]], <16 x i8> [[REG78]], <16 x i8> [[REG79]])
// CHECK-NEXT: [[REG81:[0-9a-zA-Z_%.]+]] = bitcast <16 x i8> [[REG80]] to <2 x i64>
// CHECK-NEXT: ret <2 x i64> [[REG81]]
