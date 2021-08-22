# To run unit tests refer to commands from link below:
# https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(emgToolbox)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(/Users/jordanhybki/Documents/GitHub/STARX-EMG-Feature-Toolkit/source)

add_executable(
    unitTest

    ../source/emgToolbox.h
    ../source/AbsoluteValueOfTheSummationOfExpRoot.cpp
    ../source/AbsoluteValueOfTheSummationOfSquareRoot.cpp
    ../source/AverageAmplitudeChange.cpp
    ../source/AverageEnergy.cpp
    ../source/Cardinality.cpp
    ../source/CoefficientOfVariation.cpp
    ../source/DifferenceAbsoluteMeanValue.cpp
    ../source/DifferenceAbsoluteStandardDeviationValue.cpp
    ../source/DifferenceVarianceValue.cpp
    ../source/EnhancedMeanAbsoluteValue.cpp
    ../source/EnhancedWaveLength.cpp
    ../source/IntegratedEMG.cpp
    ../source/InterquartileRange.cpp
    ../source/Kurtosis.cpp
    ../source/LogCoefficientOfVariation.cpp
    ../source/LogDetector.cpp
    ../source/LogDifferenceAbsoluteMeanValue.cpp
    ../source/LogDifferenceAbsoluteStandardDeviationValue.cpp
    ../source/LogTeagerKaiserEnergyOperator.cpp
    ../source/MaximumFractalLength.cpp
    ../source/MeanAbsoluteDeviation.cpp
    ../source/MeanAbsoluteValue.cpp
    ../source/MeanValueOfTheSquareRoot.cpp
    ../source/ModifiedMeanAbsoluteValue.cpp
    ../source/ModifiedMeanAbsoluteValue2.cpp
    ../source/MyopulsePercentageRate.cpp
    ../source/NewZeroCrossing.cpp
    ../source/RootMeanSquare.cpp
    ../source/SimpleSquareIntegral.cpp
    ../source/Skewness.cpp
    ../source/SlopeSignChange.cpp
    ../source/StandardDeviation.cpp
    ../source/TemporalMoment.cpp
    ../source/Variance.cpp
    ../source/VarianceOfEMG.cpp
    ../source/VOrder.cpp
    ../source/WaveformLength.cpp
    ../source/WillisonAmplitude.cpp
    ../source/ZeroCrossing.cpp

    unitTest.cc

)
target_link_libraries(
    unitTest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(unitTest)
