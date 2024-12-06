cmake_minimum_required(VERSION 3.15)
project(SoftPosit C)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source CACHE STRING "Source directory")
set(PYTHON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/python CACHE STRING "Python bindings directory")
set(SPECIALIZE_TYPE 8086-SSE CACHE STRING "Specialized type directory")
set(SOFTPOSIT_OPTS "-DINLINE_LEVEL=5" CACHE STRING "Additional compilation options")
set(COMPILER_FLAGS "-Werror-implicit-function-declaration -DSOFTPOSIT_FAST_INT64 -O2")

add_library(softposit_include INTERFACE)

target_include_directories(softposit_include INTERFACE
    ${SOURCE_DIR}/include
    ${SOURCE_DIR}/${SPECIALIZE_TYPE}
    .
)

set(OBJS_PRIMITIVES "")
set(OBJS_SPECIALIZE "")

set(OBJS_OTHERS
    s_addMagsP8.c
    s_subMagsP8.c
    s_mulAddP8.c
    p8_add.c
    p8_sub.c
    p8_mul.c
    p8_div.c
    p8_sqrt.c
    p8_to_p16.c
    p8_to_p32.c
    p8_to_pX2.c
    p8_to_i32.c
    p8_to_i64.c
    p8_to_ui32.c
    p8_to_ui64.c
    p8_roundToInt.c
    p8_mulAdd.c
    p8_eq.c
    p8_le.c
    p8_lt.c
    quire8_fdp_add.c
    quire8_fdp_sub.c
    ui32_to_p8.c
    ui64_to_p8.c
    i32_to_p8.c
    i64_to_p8.c
    s_addMagsP16.c
    s_subMagsP16.c
    s_mulAddP16.c
    p16_to_ui32.c
    p16_to_ui64.c
    p16_to_i32.c
    p16_to_i64.c
    p16_to_p8.c
    p16_to_p32.c
    p16_to_pX2.c
    p16_roundToInt.c
    p16_add.c
    p16_sub.c
    p16_mul.c
    p16_mulAdd.c
    p16_div.c
    p16_eq.c
    p16_le.c
    p16_lt.c
    p16_sqrt.c
    quire16_fdp_add.c
    quire16_fdp_sub.c
    quire_helper.c
    ui32_to_p16.c
    ui64_to_p16.c
    i32_to_p16.c
    i64_to_p16.c
    s_addMagsP32.c
    s_subMagsP32.c
    s_mulAddP32.c
    p32_to_ui32.c
    p32_to_ui64.c
    p32_to_i32.c
    p32_to_i64.c
    p32_to_p8.c
    p32_to_p16.c
    p32_to_pX2.c
    p32_roundToInt.c
    p32_add.c
    p32_sub.c
    p32_mul.c
    p32_mulAdd.c
    p32_div.c
    p32_eq.c
    p32_le.c
    p32_lt.c
    p32_sqrt.c
    quire32_fdp_add.c
    quire32_fdp_sub.c
    ui32_to_p32.c
    ui64_to_p32.c
    i32_to_p32.c
    i64_to_p32.c
    s_approxRecipSqrt_1Ks.c
    c_convertDecToPosit8.c
    c_convertPosit8ToDec.c
    c_convertDecToPosit16.c
    c_convertPosit16ToDec.c
    c_convertQuire8ToPosit8.c
    c_convertQuire16ToPosit16.c
    c_convertQuire32ToPosit32.c
    c_convertDecToPosit32.c
    c_convertPosit32ToDec.c
    c_int.c
    s_addMagsPX2.c
    s_subMagsPX2.c
    s_mulAddPX2.c
    pX2_add.c
    pX2_sub.c
    pX2_mul.c
    pX2_div.c
    pX2_mulAdd.c
    pX2_roundToInt.c
    pX2_sqrt.c
    pX2_eq.c
    pX2_le.c
    pX2_lt.c
    ui32_to_pX2.c
    ui64_to_pX2.c
    i32_to_pX2.c
    i64_to_pX2.c
    c_convertQuireX2ToPositX2.c
)

set(OBJS_ALL ${OBJS_PRIMITIVES} ${OBJS_SPECIALIZE} ${OBJS_OTHERS})
list(TRANSFORM OBJS_ALL PREPEND ${SOURCE_DIR}/)

add_library(softposit STATIC ${OBJS_ALL})
target_compile_options(softposit PRIVATE "${SOFTPOSIT_OPTS} ${COMPILER_FLAGS}")

target_link_libraries(softposit PUBLIC softposit_include)