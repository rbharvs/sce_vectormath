/*
  Copyright (C) 2006, 2007 Sony Computer Entertainment Inc.
  All rights reserved.

  Redistribution and use in source and binary forms,
  with or without modification, are permitted provided that the
  following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   * Neither the name of the Sony Computer Entertainment Inc nor the names
     of its contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#define _VECTORMATH_AOS_TEST
#define _VECTORMATH_DEBUG

#include "vectormath_aos.h"

FILE* goldReference=0;
float epsilon=1e-4f;
int totalFailedTests = 0;
int totalPassedTests = 0;

#include "test.h"

int iteration = 0;

using namespace Vectormath;
using namespace Vectormath::Aos;

void
Matrix3_methods_test()
{
    Matrix3 a_Matrix3, b_Matrix3;
    Matrix4 a_Matrix4, b_Matrix4;
    Transform3 a_Transform3, b_Transform3;
    Vector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    Vector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    Point3 a_Point3, b_Point3, c_Point3, d_Point3;
    Quat a_Quat, b_Quat, c_Quat, d_Quat;
    Vector4 tmpV4;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector3 = Vector3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( a_Vector3, pad );
    a_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( b_Vector3, pad );
    b_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( c_Vector3, pad );
    c_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( d_Vector3, pad );
    d_Vector3 = tmpV4.getXYZ( );
    testvm( a_Vector3, "set Vector3 with floats" );
    testvm( b_Vector3, "set Vector3 with floats" );
    testvm( c_Vector3, "set Vector3 with floats" );
    testvm( d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector4 = Vector4( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Vector4, "set Vector4 with floats" );
    testvm( b_Vector4, "set Vector4 with floats" );
    testvm( c_Vector4, "set Vector4 with floats" );
    testvm( d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Point3 = Point3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( Vector3( a_Point3 ), pad );
    a_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( b_Point3 ), pad );
    b_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( c_Point3 ), pad );
    c_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( d_Point3 ), pad );
    d_Point3 = Point3( tmpV4.getXYZ( ) );
    testvm( a_Point3, "set Point3 with floats" );
    testvm( b_Point3, "set Point3 with floats" );
    testvm( c_Point3, "set Point3 with floats" );
    testvm( d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Quat = Quat( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Quat, "set Quat with floats" );
    testvm( b_Quat, "set Quat with floats" );
    testvm( c_Quat, "set Quat with floats" );
    testvm( d_Quat, "set Quat with floats" );
    a_Matrix3 = Matrix3( a_Vector3, b_Vector3, c_Vector3 );
    b_Matrix3 = Matrix3( d_Vector3, a_Vector3, b_Vector3 );
    testvm( a_Matrix3, "set Matrix3 columns" );
    testvm( b_Matrix3, "set Matrix3 columns" );
    a_Matrix4 = Matrix4( a_Vector4, b_Vector4, c_Vector4, d_Vector4 );
    b_Matrix4 = Matrix4( d_Vector4, a_Vector4, b_Vector4, c_Vector4 );
    testvm( a_Matrix4, "set Matrix4 columns" );
    testvm( b_Matrix4, "set Matrix4 columns" );
    a_Transform3 = Transform3( a_Vector3, b_Vector3, c_Vector3, d_Vector3 );
    b_Transform3 = Transform3( d_Vector3, a_Vector3, b_Vector3, c_Vector3 );
    testvm( a_Transform3, "set Transform3 columns" );
    testvm( b_Transform3, "set Transform3 columns" );
    testvm( appendScale( a_Matrix3, a_Vector3 ), "appendScale Matrix3 Vector3" );
    testvm( prependScale( a_Vector3, a_Matrix3 ), "prependScale Vector3 Matrix3" );
    testvm( mulPerElem( a_Matrix3, b_Matrix3 ), "mulPerElem Matrix3" );
    testvm( absPerElem( a_Matrix3 ), "absPerElem Matrix3" );
    testvm( transpose( a_Matrix3 ), "transpose Matrix3" );
    testvm( inverse( a_Matrix3 ), "inverse Matrix3" );
    testvm( ( inverse( a_Matrix3 ) * a_Matrix3 ), "inverse(Matrix3) * Matrix3" );
    testfloatWithoutName("%f\n", getfloat(determinant( a_Matrix3 )) );
    testvm( outer( a_Vector3, b_Vector3 ), "outer Vector3" );
    testvm( rowMul( a_Vector3, a_Matrix3 ), "rowMul Vector3" );
    testvm( crossMatrix( a_Vector3 ), "crossMatrix" );
    testvm( crossMatrixMul( a_Vector3, a_Matrix3 ), "crossMatrixMul" );
}

void
Matrix4_methods_test()
{
    Matrix3 a_Matrix3, b_Matrix3;
    Matrix4 a_Matrix4, b_Matrix4;
    Transform3 a_Transform3, b_Transform3;
    Vector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    Vector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    Point3 a_Point3, b_Point3, c_Point3, d_Point3;
    Quat a_Quat, b_Quat, c_Quat, d_Quat;
    Vector4 tmpV4;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector3 = Vector3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( a_Vector3, pad );
    a_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( b_Vector3, pad );
    b_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( c_Vector3, pad );
    c_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( d_Vector3, pad );
    d_Vector3 = tmpV4.getXYZ( );
    testvm( a_Vector3, "set Vector3 with floats" );
    testvm( b_Vector3, "set Vector3 with floats" );
    testvm( c_Vector3, "set Vector3 with floats" );
    testvm( d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector4 = Vector4( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Vector4, "set Vector4 with floats" );
    testvm( b_Vector4, "set Vector4 with floats" );
    testvm( c_Vector4, "set Vector4 with floats" );
    testvm( d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Point3 = Point3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( Vector3( a_Point3 ), pad );
    a_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( b_Point3 ), pad );
    b_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( c_Point3 ), pad );
    c_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( d_Point3 ), pad );
    d_Point3 = Point3( tmpV4.getXYZ( ) );
    testvm( a_Point3, "set Point3 with floats" );
    testvm( b_Point3, "set Point3 with floats" );
    testvm( c_Point3, "set Point3 with floats" );
    testvm( d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Quat = Quat( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Quat, "set Quat with floats" );
    testvm( b_Quat, "set Quat with floats" );
    testvm( c_Quat, "set Quat with floats" );
    testvm( d_Quat, "set Quat with floats" );
    a_Matrix3 = Matrix3( a_Vector3, b_Vector3, c_Vector3 );
    b_Matrix3 = Matrix3( d_Vector3, a_Vector3, b_Vector3 );
    testvm( a_Matrix3, "set Matrix3 columns" );
    testvm( b_Matrix3, "set Matrix3 columns" );
    a_Matrix4 = Matrix4( a_Vector4, b_Vector4, c_Vector4, d_Vector4 );
    b_Matrix4 = Matrix4( d_Vector4, a_Vector4, b_Vector4, c_Vector4 );
    testvm( a_Matrix4, "set Matrix4 columns" );
    testvm( b_Matrix4, "set Matrix4 columns" );
    a_Transform3 = Transform3( a_Vector3, b_Vector3, c_Vector3, d_Vector3 );
    b_Transform3 = Transform3( d_Vector3, a_Vector3, b_Vector3, c_Vector3 );
    testvm( a_Transform3, "set Transform3 columns" );
    testvm( b_Transform3, "set Transform3 columns" );
    testvm( appendScale( a_Matrix4, a_Vector3 ), "appendScale Matrix4 Vector3" );
    testvm( prependScale( a_Vector3, a_Matrix4 ), "prependScale Vector3 Matrix4" );
    testvm( mulPerElem( a_Matrix4, b_Matrix4 ), "mulPerElem Matrix4" );
    testvm( absPerElem( a_Matrix4 ), "absPerElem Matrix4" );
    testvm( transpose( a_Matrix4 ), "transpose Matrix4" );
    testvm( inverse( a_Matrix4 ), "inverse Matrix4" );
    testvm( ( inverse( a_Matrix4 ) * a_Matrix4 ), "inverse(Matrix4) * Matrix4" );
    a_Matrix4.setRow( 3, Vector4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    a_Matrix4.setUpper3x3( Matrix3( normalize( a_Quat ) ) );
    testvm( affineInverse( a_Matrix4 ), "affineInverse Matrix4" );
    testvm( ( affineInverse( a_Matrix4 ) * a_Matrix4 ), "affineInverse(Matrix4) * Matrix4" );
    testvm( orthoInverse( a_Matrix4 ), "orthoInverse Matrix4" );
    testvm( ( orthoInverse( a_Matrix4 ) * a_Matrix4 ), "orthoInverse(Matrix4) * Matrix4" );
    testfloatWithoutName("%f\n", getfloat(determinant( a_Matrix4 )) );
    testvm( outer( a_Vector4, b_Vector4 ), "outer Vector4" );
}

void
Transform3_methods_test()
{
    Matrix3 a_Matrix3, b_Matrix3;
    Matrix4 a_Matrix4, b_Matrix4;
    Transform3 a_Transform3, b_Transform3;
    Vector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    Vector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    Point3 a_Point3, b_Point3, c_Point3, d_Point3;
    Quat a_Quat, b_Quat, c_Quat, d_Quat;
    Vector4 tmpV4;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector3 = Vector3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Vector3 = Vector3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( a_Vector3, pad );
    a_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( b_Vector3, pad );
    b_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( c_Vector3, pad );
    c_Vector3 = tmpV4.getXYZ( );
    tmpV4 = Vector4( d_Vector3, pad );
    d_Vector3 = tmpV4.getXYZ( );
    testvm( a_Vector3, "set Vector3 with floats" );
    testvm( b_Vector3, "set Vector3 with floats" );
    testvm( c_Vector3, "set Vector3 with floats" );
    testvm( d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Vector4 = Vector4( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Vector4 = Vector4( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Vector4, "set Vector4 with floats" );
    testvm( b_Vector4, "set Vector4 with floats" );
    testvm( c_Vector4, "set Vector4 with floats" );
    testvm( d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    a_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Point3 = Point3( rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    c_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    d_Point3 = Point3( rndflt1, rndflt2, rndflt3 );
    tmpV4 = Vector4( Vector3( a_Point3 ), pad );
    a_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( b_Point3 ), pad );
    b_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( c_Point3 ), pad );
    c_Point3 = Point3( tmpV4.getXYZ( ) );
    tmpV4 = Vector4( Vector3( d_Point3 ), pad );
    d_Point3 = Point3( tmpV4.getXYZ( ) );
    testvm( a_Point3, "set Point3 with floats" );
    testvm( b_Point3, "set Point3 with floats" );
    testvm( c_Point3, "set Point3 with floats" );
    testvm( d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    a_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    b_Quat = Quat( rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    c_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    d_Quat = Quat( rndflt1, rndflt2, rndflt3, rndflt4 );
    testvm( a_Quat, "set Quat with floats" );
    testvm( b_Quat, "set Quat with floats" );
    testvm( c_Quat, "set Quat with floats" );
    testvm( d_Quat, "set Quat with floats" );
    a_Matrix3 = Matrix3( a_Vector3, b_Vector3, c_Vector3 );
    b_Matrix3 = Matrix3( d_Vector3, a_Vector3, b_Vector3 );
    testvm( a_Matrix3, "set Matrix3 columns" );
    testvm( b_Matrix3, "set Matrix3 columns" );
    a_Matrix4 = Matrix4( a_Vector4, b_Vector4, c_Vector4, d_Vector4 );
    b_Matrix4 = Matrix4( d_Vector4, a_Vector4, b_Vector4, c_Vector4 );
    testvm( a_Matrix4, "set Matrix4 columns" );
    testvm( b_Matrix4, "set Matrix4 columns" );
    a_Transform3 = Transform3( a_Vector3, b_Vector3, c_Vector3, d_Vector3 );
    b_Transform3 = Transform3( d_Vector3, a_Vector3, b_Vector3, c_Vector3 );
    testvm( a_Transform3, "set Transform3 columns" );
    testvm( b_Transform3, "set Transform3 columns" );
    testvm( appendScale( a_Transform3, a_Vector3 ), "appendScale Transform3 Vector3" );
    testvm( prependScale( a_Vector3, a_Transform3 ), "prependScale Vector3 Transform3" );
    testvm( mulPerElem( a_Transform3, b_Transform3 ), "mulPerElem Transform3" );
    testvm( absPerElem( a_Transform3 ), "absPerElem Transform3" );
    testvm( inverse( a_Transform3 ), "inverse Transform3" );
    testvm( ( inverse( a_Transform3 ) * a_Transform3 ), "inverse(Transform3) * Transform3" );
    a_Transform3.setUpper3x3( Matrix3( normalize( a_Quat ) ) );
    testvm( orthoInverse( a_Transform3 ), "orthoInverse Transform3" );
    testvm( ( orthoInverse( a_Transform3 ) * a_Transform3 ), "orthoInverse(Transform3) * Transform3" );
}

int main()
{
	goldReference=fopen("../test4_reference.txt","r");
    int i;
//    printf("\n __begin__ \n");
    for ( i = 0; i < 2; i++ ) {
        Matrix3_methods_test();
        Matrix4_methods_test();
        Transform3_methods_test();
    }
   if (goldReference)
	{
		fclose(goldReference);
		printf("totalPassedTests= %d\n", totalPassedTests);
		printf("totalFailedTests = %d\n", totalFailedTests);
	} else
	{
		printf("\n __end__ \n");
	}
    return 0;
}