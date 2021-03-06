#pragma once

#include "../unit_test_framework.h"

namespace Unit_Test
{
    void addTests_Image_Function_Cuda( UnitTestFramework & framework ); // function what adds all below tests to framework

    namespace Image_Function_Cuda_Test
    {
        bool AbsoluteDifference2ParametersTest();
        bool AbsoluteDifference3ParametersTest();

        bool BitwiseAnd2ParametersTest();
        bool BitwiseAnd3ParametersTest();

        bool BitwiseOr2ParametersTest();
        bool BitwiseOr3ParametersTest();

        bool BitwiseXor2ParametersTest();
        bool BitwiseXor3ParametersTest();

        bool ConvertToGrayScale1ParameterTest();
        bool ConvertToGrayScale2ParametersTest();

        bool ConvertToRgb1ParameterTest();
        bool ConvertToRgb2ParametersTest();

        bool GammaCorrection3ParametersTest();
        bool GammaCorrection4ParametersTest();

        bool Histogram1ParameterTest();
        bool Histogram2ParametersTest();

        bool Invert1ParameterTest();
        bool Invert2ParametersTest();

        bool LookupTable2ParametersTest();
        bool LookupTable3ParametersTest();

        bool Maximum2ParametersTest();
        bool Maximum3ParametersTest();

        bool Minimum2ParametersTest();
        bool Minimum3ParametersTest();

        bool Subtract2ParametersTest();
        bool Subtract3ParametersTest();

        bool Threshold2ParametersTest();
        bool Threshold3ParametersTest();

        bool ThresholdDouble3ParametersTest();
        bool ThresholdDouble4ParametersTest();
    };
};
