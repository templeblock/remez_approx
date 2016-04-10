/*
 * Copyright (c) 2016, fukuroda(https://github.com/fukuroder)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of faster_and_better_sin_approx nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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

// References
//   https://code.google.com/p/fastapprox/
/*
static inline float
fastersin (float x)
{
  static const float fouroverpi = 1.2732395447351627f;
  static const float fouroverpisq = 0.40528473456935109f;
  static const float q = 0.77633023248007499f;
  union { float f; uint32_t i; } p = { 0.22308510060189463f };

  union { float f; uint32_t i; } vx = { x };
  uint32_t sign = vx.i & 0x80000000;
  vx.i &= 0x7FFFFFFF;

  float qpprox = fouroverpi * x - fouroverpisq * x * vx.f;

  p.i |= sign;

  return qpprox * (q + p.f * qpprox);
}
*/

#pragma once

//
static inline float remez_sin_f(float x)
{
    static const float s1 = 1.2728678435556479f;
    static const float s2 = 0.4051664184092053f;
    static const float s3 = 0.77754742428930464f;
    union { float f; uint32_t i; } s4 = { 0.22207681739058507f };

    union { float f; uint32_t i; } vx = { x };
    uint32_t sign = vx.i & 0x80000000;
    vx.i &= 0x7FFFFFFF;

    //float qpprox = s1 * x - s2 * x * vx.f;
    float qpprox = x * (s1 - s2 * vx.f);

    s4.i |= sign;

    return qpprox * (s3 + s4.f * qpprox);
}

//
static inline double remez_sin(double x)
{
    static const double s1 = 1.2728678435556479;
    static const double s2 = 0.4051664184092053;
    static const double s3 = 0.77754742428930464;
    union { double f; uint64_t i; } s4 = { 0.22207681739058507 };
    
    union { double f; uint64_t i; } vx = { x };
    uint64_t sign = vx.i & 0x8000000000000000;
    vx.i &= 0x7FFFFFFFFFFFFFFF;
    
    //double qpprox = s1 * x - s2 * x * vx.f;
    double qpprox = x * (s1 - s2 * vx.f);
    
    s4.i |= sign;
    
    return qpprox * (s3 + s4.f * qpprox);
}

#if 0
//
static inline float remez_sin_f2(float x)
{
    static const float s1 = 1.2728678435556479f;
    static const float s2 = 0.4051664184092053f;
    static const float s3 = 0.77754742428930464f;
    union { float f; uint32_t i; } s4 = { 0.22207681739058507f };
    
    union { float f; uint32_t i; } vx = { x };
    uint32_t sign = vx.i & 0x80000000;
    vx.i &= 0x7FFFFFFF;
    
    float qpprox = s1 * x - s2 * x * vx.f;
    
    s4.i |= sign;
    
    return qpprox * (s3 + s4.f * qpprox);
}

//
static inline double remez_sin2(double x)
{
    static const double s1 = 1.2728678435556479;
    static const double s2 = 0.4051664184092053;
    static const double s3 = 0.77754742428930464;
    union { double f; uint64_t i; } s4 = { 0.22207681739058507 };
    
    union { double f; uint64_t i; } vx = { x };
    uint64_t sign = vx.i & 0x8000000000000000;
    vx.i &= 0x7FFFFFFFFFFFFFFF;
    
    double qpprox = s1 * x - s2 * x * vx.f;
    
    s4.i |= sign;
    
    return qpprox * (s3 + s4.f * qpprox);
}
#endif